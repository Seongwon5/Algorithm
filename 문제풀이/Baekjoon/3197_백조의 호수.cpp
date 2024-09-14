#include<iostream>
#include<vector>
using namespace std;

char board[1500][1500];
int R, C;
const int dx[4]={0,0,1,-1};
const int dy[4]={1,-1,0,0};
bool visited[1500][1500];
int set[1500][1500];//분리 집합
int swan[2][2];//첫번째 인덱스는 백조의 번호, 두 번째 인덱스는 백조의 좌표(row,col);
int canMove(int row,int col);
void dfs(row,col);
void find(int row,int col);
void merge(int u, int v);
int canMove(int row,int col);
void clearVisited();
void spread(int row, int col);
bool canMeet();

void dfs(int row,int col){
    visited[row][col]=true;
    if(board[row][col]=='X') return;
    for(int i=0;i<4;i++){
        int r=row+dx[i];
        int c=col+dy[i];
        int can=canMeet(r,c);
        if((can==2||can==3)&&!visited[r][c]){
            merge(row*C+col, r*C+c);
            dfs(r,c);
        }
    }
}
void find(int row,int col){
    if (row*C+col==set[row][col]) return row*C+col;
    else{
        int nextRow=set[row][col]/C;
        int nextCol=set[row][col]%C;
        return find(nextRow,nextCol);
    }
}
void merge(int u, int v){
    int uRow=u/C;
    int uCol=u%C;

    int vRow=v/C;
    int vCol=v%C;

    int uParent=find(uRow,uCol);
    int vParent=find(vRow,vCol);

    if(uParent<vParent){//v를 u의 자식으로 한다.
        set[vParent/C][vParent%C]=set[uParent/C][uParent%C];
    }
    else{//u를 v의 자식으로 한다.
        set[uParent/C][uParent%C]=set[vParent/C][vParent%C];
    }
}

int canMove(int row,int col){//지정한 칸으로 움직일 수 있는지 계산한다.
    if(row<0||col<0||row>=R||col>=C){
        return 0;
    }
    else if(board[row][col]=='X'){
        return 1;
    }
    else if(board[row][col]=='L'){
        return 2;
    }
    else{
        return 3;
    }
}
void clearVisited(){
    for(int i=0;i<R;i++){
        for(int j=0;j<C;j++){
            visited[i][j]=false;
        }
    }
}
void spread(int row, int col){//해당 칸이 물일 경우, 그 칸 주변을 물로 만든다.
    if(board[row][col]=='.'&&!visited[row][col]){
        for(int i=0;i<4;i++){
            if(canMove(row+dx[i],col+dy[i])==1&&!visited[row+dx[i]][col+dy[i]]){
                visited[row+dx[i]][col+dy[i]]=true;
                board[row+dx[i]][col+dy[i]]='.';
            }
        }
        return;
    }
    else{
        return;
    }
}

/*bool findL(int row,int col){//재귀적으로 L을 찾음
    visited[row][col]=true;
    bool find=false;
    for(int i=0;i<4;i++){
        if(canMove(row+dx[i],col+dy[i])==2&&!visited[row+dx[i]][col+dy[i]]) {
            //cout<<row+dx[i]<<","<<col+dy[i]<<"에서 L발견"<<endl;
            return true;
        }
        if(canMove(row+dx[i],col+dy[i])==3&&!visited[row+dx[i]][col+dy[i]]){
            //그 칸이 물인 경우만 움직일 수 있음.
            //cout<<row+dx[i]<<","<<col+dy[i]<<"로 이동 가능"<<endl;
            find=find||findL(row+dx[i],col+dy[i]);
        }
    }
    return find;
};
*/

bool canMeet(){//두 백조가 서로 만날 수 있는지 계산한다.
    clearVisited();//dfs를 위해 방문 여부를 초기화
    return findL(swan[0][0],swan[0][1]);
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin>>R>>C;
    int cur=0;
    for(int i=0;i<R;i++){
        for(int j=0;j<C;j++){
            cin>>board[i][j];
            if(board[i][j]=='L'){//백조를 발견한 경우 백조 위치 정보를 추가함.
                swan[cur][0]=i;
                swan[cur][1]=j;
                cur++;
            }
        }
    }
    int num=0;
    for(int i=0;i<R;i++){
        for(int j=0;j<C;j++){
            set[i][j]=num;
            num++;
        }
    }
    for(int i=0;i<R;i++){
        for(int j=0;j<C;j++){
            dfs(i,j);
        }
    }

    //이제부터 하루씩 경과하면서 얼음을 녹이고,
    //그 다음 백조들이 서로 만날 수 있는지 계산해주면 된다.
    int elapsed=0;
    while(true){
        if(canMeet()) break;//해당 날짜에는 만날 수 없음.
        else{
            ++elapsed;
            clearVisited();
            for(int i=0;i<R;i++){
                for(int j=0;j<C;j++){
                    spread(i,j);
                }
            }
           /* for(int i=0;i<R;i++){
                for(int j=0;j<C;j++){
                    cout<<board[i][j]<<' ';
                }
                cout<<endl;
            }
            */

        }
    }
    cout<<elapsed<<endl;

}