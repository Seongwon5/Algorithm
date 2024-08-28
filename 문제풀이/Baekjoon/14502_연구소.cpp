#include<iostream>

using namespace std;
//
int board[8][8] ;
bool visited[8][8] ;
int N, M;
int maxSafeArea=0;
//14502_연구소
const int moveX[4]={0, 1, 0, -1};
const int moveY[4]={1, 0, -1, 0};
//이 문제에서 해야하는 작업
//하나의 보드에 벽을 3개 세우는 작업
bool canMove(int board[][8], int i, int j){
    if(i>=0&&i<N&&j>=0&&j<M){
        if(board[i][j]==0||board[i][j]==2){
            if(!visited[i][j]) return true;
        }
    }
    return false;
}
void bfs(int board[][8], int i, int j){
    //정해진 크기의 보드 내에서 벽을 통과하지 않는 조건으로 전파시킨다.
    board[i][j]=2;
    visited[i][j]=true;
    for(int k=0;k<4;k++){
        if(canMove(board, i+moveX[k], j+moveY[k])){
            bfs(board, i+moveX[k], j+moveY[k]);
        }
    }

}
void makeWall(int board[][8], int toPick){//남은 벽의 개수를 입력으로 받음.
    if(toPick==0){//기저 사례의 처리.
        //깊이 우선 탐색을 통해 바이러스 전파하기
        for(int i=0;i<N;i++){
            for(int j=0;j<M;j++){
                visited[i][j]=false;
            }
        }
        int savedBoard[8][8];
        for(int i=0;i<N;i++){
            for(int j=0;j<M;j++){
                savedBoard[i][j]=board[i][j];
            }
        }
        for(int i=0;i<N;i++){
            for(int j=0;j<M;j++){
                if(board[i][j]==2&&!visited[i][j]){
                    bfs(board, i, j);
                }
            }
        }
        int safeArea=0;
        for(int i=0;i<N;i++){
            for(int j=0;j<M;j++){
                if(board[i][j]==0){
                    safeArea++;
                }
            }
        }
        //바이러스 전파 후에 답의 영역을 계산하기
        maxSafeArea=max(maxSafeArea, safeArea);
        for(int i=0;i<N;i++){//복구작업
            for(int j=0;j<M;j++){
                board[i][j]=savedBoard[i][j];
            }
        }
        return;
    }
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){//정해진 보드의 범위 내에서 벽을 세울 수 있는 위치를 찾음.
            //0인 위치에만 벽을 세울 수 있음.
            if(board[i][j]==0){
                board[i][j]=1;
                //벽을 하나 세운 후에는 재귀 호출을 통해 다음 벽을 생성하도록 함.
                makeWall(board, toPick-1);
                board[i][j]=0;
            }
        }
    }
}
//벽을 3개 다 세운 다음에 탐색을 활용하여 바이러스를 전파
//바이러스가 전파된 후에는 안전 영역의 너비를 계산함.

int main(){
    cin>>N>>M;
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            cin>>board[i][j];
        }
    }
    
    makeWall(board, 3);
    cout<<maxSafeArea<<endl;

}