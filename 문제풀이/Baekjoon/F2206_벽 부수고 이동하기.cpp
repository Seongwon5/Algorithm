#include<iostream>
#include<queue>
#include<string>
using namespace std;
//벽을 하나씩 제거하여 상태를 만든 후에, 각각의 케이스에 대하여 
//너비 우선 탐색을 수행한 후에 N,M 점에 대한 값을 구한다.

//너비우선 탐색을 위환 큐에는 row, col, distance 정보가 들어간다.
int N, M;
int minAns=987654321;
bool visited[1000][1000][2];//방문 정보를 저장하는 배열
const int dx[4]={0,0,1,-1};
const int dy[4]={1,-1,0,0};
int board[1000][1000];//맵의 정보를 저장하는 배열,0은 이동가능, 1은 벽
struct point{
    point(int row, int col, int dist, bool visited){
        this->row=row;
        this->col=col;
        this->dist=dist;
        this->visited=visited;
    }
    int row;
    int col;
    int dist;
    bool visited;
};
bool canMove(int row, int col){
    if(row<0||row>=N||col<0||col>=M){
        return false;
    }
    else{
        return true;
    }
}
void clearVisited(){
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            for(int k=0;k<2;k++){
                visited[i][j][k]=false;
            }
        }
    }
}
int main(){
    cin>>N>>M;
    for(int i=0;i<N;i++){
        string num;
        cin>>num;
        for(int j=0;j<num.size();j++){
            board[i][j]=num[j]-'0';
        }
    }

    clearVisited();
    //상태를 만든 후 수행
    visited[0][0][0]=true;
    queue<point> q;
    q.push(point(0,0,1,false));
    bool found=false;//정답을 찾았는지?
    while(!q.empty()){
        point curPoint=q.front();
        //cout<<"현재"<<curPoint.row<<","<<curPoint.col<<","<<curPoint.dist<<endl;
        if(curPoint.row==N-1&&curPoint.col==M-1){
            minAns=min(minAns,curPoint.dist);
        }
        q.pop();
        for(int k=0;k<4;k++){
            int nextRow=curPoint.row+dx[k];
            int nextCol=curPoint.col+dy[k];
            int nextDist=curPoint.dist+1;
            if(!canMove(nextRow,nextCol)){
                continue;
            }
            else{//움직일 수는 있는 경우
                if(curPoint.visited==false){//아직 안 부신 경우 1과 0을 모두 탐색함
                    if(board[nextRow][nextCol]==1){//1인 경우
                        if(!visited[nextRow][nextCol][1]){
                            q.push(point(nextRow, nextCol, nextDist, true));
                            visited[nextRow][nextCol][1]=true;
                        }
                    }
                    else{//0인 경우
                        if(board[nextRow][nextCol]==0){
                            if(!visited[nextRow][nextCol][0]){
                                q.push(point(nextRow,nextCol, nextDist, false));
                            visited[nextRow][nextCol][0]=true;
                            }
                        }
                    }

                }
                else{//이미 부신 경우 0만 탐색함
                    if(!visited[nextRow][nextCol][1]&&board[nextRow][nextCol]==0){
                        q.push(point(nextRow, nextCol, nextDist, 1));
                        visited[nextRow][nextCol][1]=true;
                    }
                }

            }
        }
    }
    if(minAns>=987654321){
        cout<<-1<<endl;
    }
    else{
        cout<<minAns<<endl;
    }

}