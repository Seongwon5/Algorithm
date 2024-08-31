#include<iostream>
using namespace std;
//17070_ 파이프 옮기기

int N;//집의 크기는 3x3부터 16x16까지 가능
int house[16][16];//집의 상태를 나타내는 2차원 배열.

//파이프의 끝이 row, col 에 있고 파이프의 상태가 가로, 세로 대각선인 경우로 분류할 수 있으며
//각각의 상황에서 파이프의 한쪽 끝을 N,N으로 이동시키는 방법의 수를 메모이제이션 한다.
//배열에서 파이프의 끝이 N-1,N-1에 있는 경우 경우의 수는 1가지이다.

//전체 경우의 수는 16x16x3으로 메모이제이션을 통해 제한 시간 내에 해결 가능하다.

//가장 처음에 파이프는(0,1)을 끝점으로 하여 가로로 자리하고 있다.
//메모이제이션 배열에서 0은 가로, 1은 세로, 2는 대각선으로 정의한다.
int cache[16][16][3];//행, 열, 방향
//각 부분 문제에서 가로, 세로, 대각선 방향으로 움직일 수 있는지 검사한 후 재귀호출한다.
int canMove(int row, int col){//현재 위치를 입력받아서 갈 수 있는 방향을 알려주는 함수이다.
    //이동할 수 없다면 0을, 가로로만 이동 가능하면 1을, 세로로만 이동 가능하다면 2를, 가로, 또는
    //세로로만 이동 가능하다면 3을, 대각선으로 이동 가능하다면 4를 출력한다.
    if(house[row+1][col]==0&&row+1<N){//세로로 이동 가능한경우
        if(house[row][col+1]==0&&col+1<N){//세로, 가로로 모두 이동 가능한경우
            if(house[row+1][col+1]==0){
                return 4;
            }
            else{
                return 3;
            }
        }
        else{//세로로만 이동 가능한경우
            return 2;
        }
    }
    else if(house[row][col+1]==0&&col+1<N){//가로로만 이동 가능한경우
        return 1;
    }
    else{
        return 0;
    }
    
}
int solve(int row, int col, int direction){//0 가로, 1 세로, 2 대각선
    int&ret=cache[row][col][direction];
    if(cache[row][col][direction]!=-1) return ret;
    if(row==N-1&&col==N-1){//정상적으로 끝 지점에 도달한 경우
        return ret=1;
    }
    //
    ret=0;
    int canmove=canMove(row, col);
    if(direction==0){//현재 가로
        if(canmove==4){//가로나 대각선 가능
            ret+=solve(row, col+1, 0);
            ret+=solve(row+1, col+1, 2);
        }
        else if(canmove==1||canmove==3){//가로만 가능
            ret+=solve(row, col+1, 0);
        }
        else{
            ret=0;
        }
    }
    else if(direction==1){//현재 세로
        if(canmove==4){//세로나 대각선 가능
            ret+=solve(row+1, col, 1);
            ret+=solve(row+1, col+1, 2);
        }
        else if(canmove==2||canmove==3){//세로만 가능
            ret+=solve(row+1, col, 1);
        }
        else{
            ret=0;
        }
    }
    else{//현재 대각선
        //세로, 가로, 대각선 모두 고려  
        if(canmove==4){//전부 가능
        ret+=solve(row+1, col+1, 2);
        ret+=solve(row+1, col, 1);
        ret+=solve(row, col+1, 0);
        }
        else if(canmove==3){//가로, 세로 가능
            ret+=solve(row+1, col, 1);
            ret+=solve(row, col+1, 0);
        }
        else if(canmove==2){//세로만 가능
            ret+=solve(row+1, col, 1);
        }
        else if(canmove==1){//가로만 가능
            ret+=solve(row, col+1, 0);
        }
        else{
            ret=0;
        }    
    }
    return ret;
}
int main(){
    cin>>N;
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cin>>house[i][j];
        }
    }
    for(int i=0;i<16;i++){
        for(int j=0;j<16;j++){
            for(int k=0;k<3;k++){
                cache[i][j][k]=-1;
            }
        }
    }

    cout<<solve(0, 1, 0)<<endl;

}