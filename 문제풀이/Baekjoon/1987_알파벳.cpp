#include<iostream>

using namespace std;

int R, C;
char board[20][20];
const int dx[4]={1,0,-1,0};
const int dy[4]={0,1,0,-1};
bool visited[26];//알파벳 A=0 부터 Z=25까지
int canmove(int row, int col){
    if(visited[board[row][col]-'A']||row<0||row>=R||col<0||col>=C){
        return false;
    }
    else{
        return true;
    }
}
int solve(int row, int col){
    int canMovecount=0;
    int ret=0;
    for(int i=0;i<4;i++){
        if(canmove(row+dx[i],col+dy[i])){
            ++canMovecount;
            visited[board[row+dx[i]][col+dy[i]]-'A']=true;
            ret=max(1+solve(row+dx[i],col+dy[i]),ret);
            visited[board[row+dx[i]][col+dy[i]]-'A']=false;
        }
    }
    if(canMovecount==0){
        return 1;
    }
    else{
        return ret;
    }
}
int main(){
    cin>>R>>C;

    for(int i=0;i<R;i++){
        for(int j=0;j<C;j++){
            cin>>board[i][j];
        }
    }

    for(int i=0;i<26;i++){
        visited[i]=false;
    }

    visited[board[0][0]-'A']=true;

    cout<<solve(0,0)<<endl;

}