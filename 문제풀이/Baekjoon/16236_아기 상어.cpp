#include<iostream>
#include<queue>
using namespace std;
int N;
const int dx[4]={-1,0,0,1};//우선적으로 탐색해야 하는 순서
const int dy[4]={0,-1,1,0};//위,왼쪽, 아래, 오른쪽 순서

bool visited[20][20];
int board[20][20];
//1.현재 위치에서 먹을 수 있는 가장 가까운 물고기를 너비우선 탐색한다.
//물고기가 발견되면 이동 거리만큼 시간이 흐르고 물고기의 크기와
//현재까지 먹은 물고기의 양을 최신화한다.
//2.1의 과정을 무한반복한다.

//각 칸의 정보는 row, col 좌표 그리고 거리로 나타내어진다.
struct point{
    point(int row, int col, int dist){
        this->row=row;
        this->col=col;
        this->dist=dist;
    }
    int row;
    int col;
    int dist;
};

//더 이상 진행할 수 없을 경우 현재 몇 초가 지났는지를 출력한다.
bool canMove(int row,int col){
    if(((row<0||row>=N)||col<0)||col>=N){
        return false;
    }
    else{
        return true;
    }
}
void clearVisited(){
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            visited[i][j]=false;;
        }
    }
}
int main(){
    cin>>N;
    
    int babySharkRow;
    int babySharkCol;
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cin>>board[i][j];
            if(board[i][j]==9){
                babySharkRow=i;
                babySharkCol=j;
            }
        }
    }
    int elapsed=0;
    int babySharkSize=2;
    int currentExp=0;
    while(true){
        clearVisited();
        //현재 위치를 기준으로 너비우선 탐색하여 다음 물고기를 찾음.
        visited[babySharkRow][babySharkCol]=true;
        queue<point> q;
        q.push(point(babySharkRow,babySharkCol,0));
        bool found=false;
        while(!q.empty()){
            int curRow=q.front().row;
            int curCol=q.front().col;
            int curDist=q.front().dist;
            q.pop();
            for(int i=0;i<4;i++){
                int nextRow=curRow+dx[i];
                int nextCol=curCol+dy[i];
                int nextDist=curDist+1;
                if((canMove(nextRow,nextCol)&&board[nextRow][nextCol]<=babySharkSize)&&!visited[nextRow][nextCol]){
                    //cout<<babySharkSize<<"사이즈의 상어가"<<board[nextRow][nextCol]<<"이 적힌 칸에 도달함"<<endl;
                    visited[nextRow][nextCol]=true;
                    if(board[nextRow][nextCol]<babySharkSize&&board[nextRow][nextCol]!=0){
                            //발견했으면 큐에 삽입하는 행위는 멈추고, 남은 큐를 다 비우면서 거리가 nextDist인 점들만 전부 다 훑어본다.
                            //그 중 i와 j가 가장 작은 점으로 이동해야 한다.
                            int minI=nextRow;
                            int minJ=nextCol;
                            while(!q.empty()){
                                int x=q.front().row;
                                int y=q.front().col;
                                int c=q.front().dist;
                                q.pop();
                                for(int m=0;m<4;m++){
                                    int nR=x+dx[m];
                                    int nC=y+dy[m];
                                    if(((canMove(nR,nC)&&board[nR][nC]<=babySharkSize)&&!visited[nR][nC])&&(c+1==nextDist)){
                                        
                                        visited[nR][nC]=true;
                                        if(board[nR][nC]<babySharkSize&&board[nR][nC]!=0){
                                            if(nR<minI){
                                                minI=nR;
                                                minJ=nC;
                                            }
                                            else if(nR==minI){
                                                if(nC<minJ){
                                                    minI=nR;
                                                    minJ=nC;
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                            
                            board[babySharkRow][babySharkCol]=0;
                            board[minI][minJ]=9;
                            if(++currentExp==babySharkSize){
                                babySharkSize++;
                                currentExp=0;
                            }
                            babySharkRow=minI;
                            babySharkCol=minJ;
                            elapsed+=(nextDist);
                            found=true;
                        break;
                    }
                    else{//먹을 수는 없어도 지나갈 수는 있는 경우
                        q.push(point(nextRow,nextCol,nextDist));
                    }
                
                }
            }
            if(found)break;
        }
        //너비우선 탐색 후에 발견하지 못했으면 종료
        if(!found){
            break;
        }
    }

    cout<<elapsed<<endl;
}