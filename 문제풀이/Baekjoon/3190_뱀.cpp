#include<iostream>
#include<deque>
#include<queue>
using namespace std;
typedef pair<int,int> body;

const int left=0;
const int right=1;
const int up=2;
const int down=3;

const int dx[4]={0,0,-1,1};//순서대로 left, right, up, down
const int dy[4]={-1,1,0,0};
struct command{
    int time;
    char com;
};
int getNextDirection(int dir, char com){
    if(dir==0){
        if(com=='L'){
            return 3;
        }
        else{
            return 2;
        }
    }
    else if(dir==1){
        if(com=='L'){
            return 2;
        }
        else{
            return 3;
        }
    }
    else if(dir==2){
        if(com=='L'){
            return 0;
        }
        else{
            return 1;
        }
    }
    else{//down
        if(com=='L'){
            return 1;
        }
        else{
            return 0;
        }
    }
}
int N,K;
int t=0;
int board[101][101];
int main(){
    deque<body> snake;
    cin>>N>>K;
    
    for(int i=1;i<101;i++){
        for(int j=1;j<101;j++){
            board[i][j]=0;
        }
    }

    for(int i=0;i<K;i++){
        int row,col;
        cin>>row>>col;
        board[row][col]=1;
    }

    int L;
    cin>>L;
    int dir=1;

    queue<command> commandQueue;//명령어 큐를 구성한다.
    for(int i=0;i<L;i++){
        command cm;
        cin>>cm.time>>cm.com;
        commandQueue.push(cm);
    }
    
    snake.push_front(make_pair(0,0));

    while(true){//게임을 실행하는 무한 루프
        //1. snake가 이동 후 파괴되는지?
        ++t;//1초 증가
        int nextRow=snake.front().first+dx[dir];
        int nextCol=snake.front().second+dy[dir];

        for(int i=0;i<snake.size();i++){
            if(snake[i].first==nextRow&&snake[i].second==nextCol){
                break;
            }
        }
        if(nextRow<0||nextRow>=N||nextCol<0||nextCol>=N){
            break;
        }
        //2. 그렇지 않다면, snake가 사과를 먹는지?
        snake.push_front(make_pair(nextRow,nextCol));

        if(board[nextRow][nextCol]==1){
            board[nextRow][nextCol]=0;
        }
        else{
            snake.pop_back();
        }
        
        if(commandQueue.front().time==t){
            dir=getNextDirection(dir,commandQueue.front().com);
            commandQueue.pop();
        }
    }

    cout<<t<<endl;


}
