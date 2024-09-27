#include<iostream>

using namespace std;

int N,M;//보드의 크기
char board[10][10];
const int dx[4]={-1,1,0,0};//상, 하, 좌, 우
const int dy[4]={0,0,-1,1};
int minTry=11;//시도 횟수의 최솟값.

//완전 탐색으로 문제를 해결할 경우:
//현재 try번 시도했을 경우
//현재 1번째 시도일 수도 있고, 최대 10번째 시도까지 가능함.
//해당 시도에서 구슬이 빠진다면, 시도 횟수의 최솟값을 갱신함.
//10번째 시도에서 구슬이 빠지지 않는다면, 최솟값을 갱신하지 않고 그대로 리턴함.

bool roll(char board[][10], int row, int col, int direction){//row, col  위치에 있는 구슬을 원하는 방향으로 굴림
    //반환형이 bool인 이유->구슬이 통과했다면 true를, 통과하지 못하는 경우라면 false를 반환한다.
    char now=board[row][col];
    int nextRow=row+dx[direction];
    int nextCol=col+dy[direction];
    if(board[nextRow][nextCol]=='#'||board[nextRow][nextCol]=='B'||board[nextRow][nextCol]=='R'){
        //움직일 수 없는 경우.
        //먼저 굴러갈 수 있는 구슬을 먼저 움직이기 때문에 구슬을 만났다면, 앞서가던 구슬이 먼저 멈춘 상태이다.
        return false;
    }
    else if(board[nextRow][nextCol]=='O'){//구멍을 만난 경우
        board[row][col]='.';
        return true;
    }
    else{//더 움직일 수 있는 상황->계속해서 굴린다.
        board[row][col]='.';
        board[nextRow][nextCol]=now;
        return roll(board, nextRow, nextCol, direction);
    }

}

void copyBoard(char from[][10], char to[][10]){//보드를 복사함.
    for(int i=0;i<10;i++){
        for(int j=0;j<10;j++){
            to[i][j]=from[i][j];
        }
    }
}

void solve(char board[][10], int now){//현재 보드의 상태가 board일 때, now번째 시도를 한다.
    if(now==11)return;
    char testBoard[10][10];
    bool found=false;
    
    int rRow=0, rCol=0, bRow=0, bCol=0;
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){//빨간색 구슬과 파란색 구슬, 구멍의 위치가 어디인지 파악한다.
            if(board[i][j]=='B'){
                bRow=i;
                bCol=j;
            }
            else if(board[i][j]=='R'){
                rRow=i;
                rCol=j;
            }
        }
    }

    
    for(int i=0;i<4;i++){//4 방향에 대하여 testboard를 초기화 한 후 원하는 상태를 만들고, 
                         //문제가 해결되지 않았다면 재귀호출하여 문제를 해결함.
        copyBoard(board, testBoard);//새로운 상태를 만들기 위해 copy
        

        //i가 0, 1, 2, 3일때 순서대로 상, 하, 좌, 우이다.
        
        //방향이 0 상일 경우, row가 더 적은 쪽을 먼저 굴린다.
        bool R=false;//빨간 공은 통과했는지?
        bool B=false;//파란 공은 통과했는지?
        if(i==0){
            if(rRow<bRow){//빨간 구슬을 먼저 굴림.
                R=roll(testBoard, rRow, rCol, i);
                B=roll(testBoard, bRow, bCol, i);
                if(B){//파란색이 통과한경우
                }
                else if(R){//파란색 통과 안했는데 빨간색만 통과한경우
                    minTry=min(minTry,now);
                }
                else{//둘 다 통과 못한 경우
                    solve(testBoard, now+1);
                }

            }
            else{//파란 구슬을 먼저 굴림.
                B=roll(testBoard, bRow, bCol, i);
                R=roll(testBoard, rRow, rCol, i);
                if(B){//파란색이 통과한경우
                }
                else if(R){//파란색 통과 안했는데 빨간색만 통과한경우
                    minTry=min(minTry,now);
                }
                else{//둘 다 통과 못한 경우
                    solve(testBoard, now+1);
                }

            }
        }
        //방향이 1 하일 경우, row가 더 큰 쪽을 먼저 굴린다.
        else if (i==1){
            if(rRow<bRow){//파란 구슬을 먼저 굴림.
                B=roll(testBoard, bRow, bCol, i);
                R=roll(testBoard, rRow, rCol, i);
                if(B){//파란색이 통과한경우
                }
                else if(R){//파란색 통과 안했는데 빨간색만 통과한경우
                    minTry=min(minTry,now);
                }
                else{//둘 다 통과 못한 경우
                    solve(testBoard, now+1);
                }

            }
            else{//빨간 구슬을 먼저 굴림.
                R=roll(testBoard, rRow, rCol, i);
                B=roll(testBoard, bRow, bCol, i);
                if(B){//파란색이 통과한경우
                }
                else if(R){//파란색 통과 안했는데 빨간색만 통과한경우
                    minTry=min(minTry,now);
                }
                else{//둘 다 통과 못한 경우
                    solve(testBoard, now+1);
                }

            }

        }
        //빙향이 2 좌일 경우, col이 더 작은 쪽을 먼저 굴린다.
        else if (i==2){
            if(rCol<bCol){//빨간 구슬을 먼저 굴림.
                R=roll(testBoard, rRow, rCol, i);
                B=roll(testBoard, bRow, bCol, i);
                if(B){//파란색이 통과한경우
                }
                else if(R){//파란색 통과 안했는데 빨간색만 통과한경우
                    minTry=min(minTry,now);
                }
                else{//둘 다 통과 못한 경우
                    solve(testBoard, now+1);
                }

            }
            else{//파란 구슬을 먼저 굴림.
                B=roll(testBoard, bRow, bCol, i);
                R=roll(testBoard, rRow, rCol, i);
                if(B){//파란색이 통과한경우
                }
                else if(R){//파란색 통과 안했는데 빨간색만 통과한경우
                    minTry=min(minTry,now);
                }
                else{//둘 다 통과 못한 경우
                    solve(testBoard, now+1);
                }

            }
        }
        //방향이 3 우일 경우, col이 더 큰 쪽을 먼저 굴린다.
        else{
            if(rCol<bCol){//파란 구슬을 먼저 굴림.
                B=roll(testBoard, bRow, bCol, i);
                R=roll(testBoard, rRow, rCol, i);
                if(B){//파란색이 통과한경우
                }
                else if(R){//파란색 통과 안했는데 빨간색만 통과한경우
                    minTry=min(minTry,now);
                }
                else{//둘 다 통과 못한 경우
                    solve(testBoard, now+1);
                }

            }
            else{//빨간 구슬을 먼저 굴림.
                R=roll(testBoard, rRow, rCol, i);
                B=roll(testBoard, bRow, bCol, i);
                if(B){//파란색이 통과한경우
                }
                else if(R){//파란색 통과 안했는데 빨간색만 통과한경우
                    minTry=min(minTry,now);
                }
                else{//둘 다 통과 못한 경우
                    solve(testBoard, now+1);
                }

            }   
        }


        //해당 시도에서 구슬이 빠진다면, 시도 횟수의 최솟값을 갱신함
    }
    //4 방향으로 시도 후에 now==10인 경우 해답을 구하지 못하면 그대로 종료한다.
    if(now==10&&!found){
        return;
    }

}
int main(){
    cin>>N>>M;

    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            cin>>board[i][j];
        }
    }

    solve(board, 1);

    if(minTry>10){
        cout<<-1<<endl;
    }
    else{
        cout<<minTry<<endl;
    }
}