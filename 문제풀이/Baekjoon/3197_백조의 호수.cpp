#include<iostream>
#include<vector>
#include<queue>
using namespace std;

char board[1500][1500];
int R, C;
const int dx[4]={0,0,1,-1};
const int dy[4]={1,-1,0,0};
bool waterVisited[1500][1500];
bool swanVisited[1500][1500];
int swan[2][2];//첫번째 인덱스는 백조의 번호, 두 번째 인덱스는 백조의 좌표(row,col);
bool fin=false;

queue<pair<int,int>> swanQueue;
queue<pair<int,int>> waterQueue;

bool canMove(int row,int col){//지정한 칸으로 움직일 수 있는지 계산한다.
    if(row<0||col<0||row>=R||col>=C){
        return false;
    }
    else{
        return true;
    }
}

void clearVisited(){
    for(int i=0;i<R;i++){
        for(int j=0;j<C;j++){
            swanVisited[i][j]=false;
            waterVisited[i][j]=false;
        }
    }
}
void waterDfs(int row, int col){
    board[row][col]='.';
    for(int i=0;i<4;i++){
        int r= row+dx[i];
        int c= col+dy[i];
        if(canMove(r,c)&&(!waterVisited[r][c])){
            
            if(board[r][c]=='X'){
                waterVisited[r][c]=true;
                waterQueue.push(make_pair(r,c));
            }
            else if(board[r][c]=='.'){
                    waterVisited[r][c]=true;
                    waterDfs(r,c);
            }
        }
    }
}
void swanDfs(int row, int col){
   for(int i=0;i<4;i++){
        int r= row+dx[i];
        int c= col+dy[i];
        if(canMove(r,c)&&!swanVisited[r][c]){
            if(r==swan[1][0]&&c==swan[1][1]){
                fin=true;
                return;
            }
            else{
                if(board[r][c]=='.'){
                    swanVisited[r][c]=true;
                    swanDfs(r,c);
                }
                else if(board[r][c]=='X'){
                    swanVisited[r][c]=true;
                    swanQueue.push(make_pair(r,c));
                }
            }
        }
    }
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
    int elapsed=0;
    
    clearVisited();
    for(int i=0;i<R;i++){
        for(int j=0;j<C;j++){
            if(i==swan[0][0]&&j==swan[0][1]){
                swanVisited[i][j]=true;
                swanQueue.push(make_pair(i,j));
                waterVisited[i][j]=true;
                waterQueue.push(make_pair(i,j));
            }
            else if(board[i][j]=='.'||board[i][j]=='L'){
                waterVisited[i][j]=true;
                waterQueue.push(make_pair(i,j));
            }
        }
    }

    int water= waterQueue.size();
    int swan= swanQueue.size();
    for(int i=0;i<water;i++){
        int row=waterQueue.front().first;
        int col=waterQueue.front().second;
        waterQueue.pop();
        waterDfs(row,col);
    }
    for(int i=0;i<swan;i++){
        int row=swanQueue.front().first;
        int col=swanQueue.front().second;
        swanQueue.pop();
        swanDfs(row,col);
    }
        
    while(!fin){
        ++elapsed;
        int water= waterQueue.size();
        int swan= swanQueue.size();
        for(int i=0;i<water;i++){
            int row=waterQueue.front().first;
            int col=waterQueue.front().second;
            waterQueue.pop();
            waterDfs(row,col);
        }
        for(int i=0;i<swan;i++){
            int row=swanQueue.front().first;
            int col=swanQueue.front().second;
            swanQueue.pop();
            swanDfs(row,col);
        }
    }
    cout<<elapsed<<endl;

}