#include<iostream>
#include<vector>
using namespace std;
int N,M;
int board[8][8];//사무실(0), cctv(1~5), 벽(6), cctv 감시구간(7)
void copyboard(int from[8][8], int to[8][8]){
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
class CCTV{
public:
    int col;//0<=col<N   세로 좌표
    int row;//0<=row<M   가로 좌표
    int num;//1<=num<=5  cctv의 번호
    CCTV(int col, int row,int num){
        this->col=col;
        this->row=row;
        this->num=num;
    }
    vector<int> cctvInfo[6][4]={
        
            {{}, {}, {}, {}},//0
            {{UP},{DOWN},{LEFT},{RIGHT}},//1
            {{UP,DOWN},{LEFT,RIGHT},{},{}},//2
            {{UP,LEFT},{UP,RIGHT},{LEFT,DOWN},{RIGHT,DOWN}},//3
            {{UP,DOWN,LEFT},{UP,DOWN,RIGHT},{LEFT,RIGHT,UP},{LEFT,RIGHT,DOWN}},//4
            {{UP,DOWN,LEFT,RIGHT},{},{},{}}//5
        
    };

};

vector<CCTV> cctv;
int solve(int savedBoard[8][8], CCTV a, int current){//사각 지대의 최소 크기를 출력한다.
    int tmpBoard[8][8];
    copyboard(savedBoard, tmpBoard);//현재 보드 상태를 저장
    for(int i=0;i<4;i++){
        for(int j=0;j<a.cctvInfo[a.num][i].size();j++){
            //cctv의 모든 방향을 한 번씩 순회하면서 상태를 만듬.
        }
    }
}
int main(){
    cin>>N>>M;
    for(int i=0;i<N;i++){//보드의 상태를 입력받는 루프.
        for(int j=0;j<M;j++){
            cin>>board[i][j];
        }
    }

}