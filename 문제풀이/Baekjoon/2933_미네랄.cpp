#include<iostream>

using namespace std;


//1.막대기를 순서에 맞게 던진다(인덱스를 2로 나눈 나머지가 0이면 왼쪽부터)
//, 1이면 오른쪽부터 던짐

//막대기는 해당 높이의 왼쪽 끝 또는 오른쪽 끝에서부터 날아가면서 처음으로 만나는
//미네랄을 제거함.
//미네랄을 제거하지 못했다면 아무일도 일어나지 않고, 제거했다면 제거된 칸을 반환함.

//미네랄이 제거되었을 때, 제거된 칸으로부터 반경 3x3 이내에 있는 칸들에 대하여
//해당 칸이 미네랄이라면 깊이우선 탐색을 수행한다.

//탐색하면서 발견한 미네랄의 최저 높이가 바닥이 아니라면, 그 클러스터는 공중에 떠 있는 것이다.
//공중에 떠 있는 클러스터를 모두 큐에 추가하고, 큐를 순회하면서 가장 가까운 바닥이나ㅣ
//클러스터 간의 거리를 모두 계산한 다음, 가장 가까운 바닥의 거리가 0보다는 크면서
//가장 작은 거리를 x라고 하면, 그 클러스터에 포함된 모든 미네랄을 x만큼 밑으로 내리면 된다.
//쉽게 말해서, 분리된 클러스터가 떨어지는 거리는, 각 열에 대하여 떨어질 수 있는 최소 높이라는 것이다.



int R, C;
int N;
char board[100][100];
int testBoard[100][100];
bool visited[100][100];
int throwing[100];

const int dx[4]={1,-1,0,0};
const int dy[4]={0,0,-1,1};

bool canMove(int row, int col){
    if(row<0||col<0||row>=R||col>=C) return false;
    else return true;
}
pair<int,int> cast(int row, int col, int n){// 미네랄이 파괴된 경우 파괴된 미네랄의 위치를 출력한다.
    int direction=n%2;// 0은 왼쪽부터, 1은 오른쪽부터 던짐.
    if (canMove(row,col+dx[direction])){
        if(board[row][col+dx[direction]]=='x'){//미네랄을 발견한 경우
            board[row][col+dx[direction]]='.';
            return make_pair(row,col+dx[direction]);
        }
        else{
            return cast(row,col+dx[direction],n);
        }   
    }
    else{
        return make_pair(-1,-1);
    }
}

void clearVisited(){
    for(int i=0;i<R;i++){
        for(int j=0;j<C;j++){
            visited[i][j]=false;
        }
    }
}

void clearTestBoard(){
    for(int i=0;i<R;i++){
        for(int j=0;j<C;j++){
            testBoard[i][j]=0;
        }
    }
}

void dfs(int row, int col, int current){
    visited[row][col]=true;
    testBoard[row][col]=current;
    for(int i=0;i<4;i++){
            int nextRow=row+dx[i];
            int nextCol=col+dy[i];
            if((canMove(nextRow,nextCol)&&!visited[nextRow][nextCol])&&board[nextRow][nextCol]=='x'){
                dfs(nextRow,nextCol,current);
            }
        }
}
int calculateDistance(int row, int col, int curDist){
    if(row+1==R||testBoard[row+1][col]==1) return curDist;
    if(testBoard[row+1][col]==2)return 9999;
    else{//계속 0을 만나고 있을 때
        return calculateDistance(row+1,col,curDist+1);
    }
}

int main(){
    cin>>R>>C;
    for(int i=0;i<R;i++){
        for(int j=0;j<C;j++){
            cin>>board[i][j];
        }
    }
    int N;
    cin>>N;
    for(int i=0;i<N;i++){
        int x;
        cin>>x;
        throwing[i]=R-x;
    }
    for(int i=0;i<N;i++){
        pair<int,int> distroyed;

        


        if(i%2==0){
            distroyed= cast(throwing[i],-1,i);
        }
        else{
            distroyed= cast(throwing[i],C,i);
        }
        
        int row=distroyed.first;
        int col=distroyed.second;

        //미네랄의 파괴가 완료된 시점.
        if(distroyed.first==-1) continue;//아무것도 파괴되지 않았다면 다음 명령으로 넘어간다.
        //distroyed 위치의 미네랄이 파괴된 경우
        clearVisited();
        clearTestBoard();
        
        for(int i=0;i<C;i++){//바닥과 연결된 클러스터를 먼저 찾는다.
            if(!visited[R-1][i]&&(board[R-1][i]=='x')){
                dfs(R-1,i,1);
            }
        }

        int currentNum=1;
        bool multiClusters=false;
        for(int i=0;i<4;i++){
            int nextRow=row+dx[i];
            int nextCol=col+dy[i];
            if((canMove(nextRow,nextCol)&&!visited[nextRow][nextCol])&&board[nextRow][nextCol]=='x'){
                currentNum++;
                if(currentNum==2){
                    multiClusters=true;
                }
                dfs(nextRow,nextCol,currentNum);
            }
        }
        if(multiClusters){//바닥과 연결된 클러스터는 1, 떠있는 클러스터는 2이다.
            int minDist=9999;
            for(int i=0;i<R;i++){
                for(int j=0;j<C;j++){
                    if(testBoard[i][j]==2){
                        minDist=min(minDist,calculateDistance(i,j,0));
                    }
                }
            }

            for(int i=R-1;i>=0;i--){
                for(int j=0;j<C;j++){
                    if(testBoard[i][j]==2){
                        board[i][j]='.';
                        board[i+minDist][j]='x';
                    }
                }
            }

        }
    }
    for(int i=0;i<R;i++){
        for(int j=0;j<C;j++){
            cout<<board[i][j];
        }
        cout<<endl;
    }

}