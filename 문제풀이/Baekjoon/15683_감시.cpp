//내가 이 문제에서 배운 것들
//배열을 매개변수로 넘긴다는 것의 정확한 의미를 알게 되었다.
//함수의 매개변수로 2차원 배열의 행과 열을 넘길 때 순서를 실수하지 않도록 주의하자.
//재귀 호출의 기저 사례에 도달했을 때 반드시 return 할 수 있도록 해야한다.
//회전, 이동에 관한 배열을 효율적으로 작성하는 방법을 고민해볼 필요가 있다.

//enum 개념은 추가로 더 공부하자.
#include<iostream>
#include<vector>
using namespace std;
int N,M;
int board[8][8];//사무실(0), cctv(1~5), 벽(6), cctv 감시구간(7)
int answer=99999999;//사각 지대의 최소 넓이
void copyboard(int from[][8], int to[][8]){
    for(int i=0;i<8;i++){
        for(int j=0;j<8;j++){
            to[i][j]=from[i][j];
        }
    }
}
enum direction{
    UP=0,
    DOWN=1,
    LEFT=2,
    RIGHT=3
};
int directionInfo[4][2]={
    {-1,0},
    {1,0},
    {0,-1},
    {0,1}
};
class CCTV{
public:
    int col;//0<=col<N   세로 좌표
    int row;//0<=row<M   가로 좌표
    int num;//1<=num<=5  cctv의 번호
    CCTV(int row, int col ,int num){
        this->col=col;
        this->row=row;
        this->num=num;
    }
    vector<int> cctvInfo[6][4]={
        
            {{}, {}, {}, {}},//0
            {{UP},{DOWN},{LEFT},{RIGHT}},//1
            {{UP,DOWN},{LEFT,RIGHT},{UP,DOWN},{LEFT,RIGHT}},//2
            {{UP,LEFT},{UP,RIGHT},{LEFT,DOWN},{RIGHT,DOWN}},//3
            {{UP,DOWN,LEFT},{UP,DOWN,RIGHT},{LEFT,RIGHT,UP},{LEFT,RIGHT,DOWN}},//4
            {{UP,DOWN,LEFT,RIGHT},{UP,DOWN,LEFT,RIGHT},{UP,DOWN,LEFT,RIGHT},{UP,DOWN,LEFT,RIGHT}}//5
        
    };

};
vector<CCTV> cctv;
void spread(int mboard[][8] ,int row, int col, int d){
    int rowMove=directionInfo[d][0];
    int colMove=directionInfo[d][1];
    if(row<0||row>=N||col<0||col>=M) return;//보드 밖으로 벗어난 경우 즉시 리턴
    if(mboard[row][col]==6) return;//벽을 만난 경우 즉시 리턴
    if(mboard[row][col]==0){//아직 감시중이지 않은 구역을 만난 경우 감시구역으로 처리한다.
        mboard[row][col]=7;
        spread(mboard, row+rowMove, col+colMove, d);
    }
    else{//cctv 또는 이미 감시중인 구역을 만났을 경우 그대로 유지하고 다음 칸으로 진행한다.
        spread(mboard, row+rowMove, col+colMove, d);
    }

};
//설정한 방향으로 감시 구역을 확산한다.

void solve(int savedBoard[][8],int current){//사각 지대의 최소 크기를 출력한다.
//  함수는 처음에 current=0으로 시작함.
    if(current==cctv.size()){//마지막 cctv의 감시 구역까지 결정 된 경우 사각 지대의 최소 크기를 출력한다.
        int area=0;//사각지대의 크기
        for(int i=0;i<N;i++){
            for(int j=0;j<M;j++){
                if(savedBoard[i][j]==0){
                    area++;
                }
            }
        }
        /*
        for(int i=0;i<N;i++){
            for(int j=0;j<M;j++){
                cout<<savedBoard[i][j];
            }
            cout<<endl;
        }
        */
        answer=min(answer, area);
       //cout<<"최소 구역이 "<<area<<"로 갱신되었습니다."<<endl;
        return;
    }
    int tmpBoard[8][8];
    CCTV a= cctv[current];
    copyboard(savedBoard, tmpBoard);//현재 보드 상태를 저장
    for(int i=0;i<4;i++){
        for(int j=0;j<a.cctvInfo[a.num][i].size();j++){
            //cctv의 모든 방향을 한 번씩 순회하면서 상태를 만듬.
            spread(tmpBoard, a.row, a.col, a.cctvInfo[a.num][i][j]);
        }
        //하나의 상태를 만들었으므로 다음 함수를 호출함.
        solve(tmpBoard, current+1);
        //보드의 상태를 saved로 다시 초기화시킨 후 루프의 다음 상태로 진입
        copyboard(savedBoard,tmpBoard);
    }
}
int main(){
    cin>>N>>M;
    for(int i=0;i<N;i++){//보드의 상태를 입력받는 루프.
        for(int j=0;j<M;j++){
            cin>>board[i][j];
        }
    }
    for(int i=0;i<N;i++){//보드의 상태를 입력받는 루프.
        for(int j=0;j<M;j++){
            if(board[i][j]!=6&&board[i][j]!=0){
                cctv.push_back(CCTV(i,j,board[i][j]));
            }
        }
    }
   solve(board,0);
    cout<<answer<<endl;

}