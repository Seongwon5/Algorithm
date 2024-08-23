#include<iostream>
using namespace std;

int cache[100000][3]//0번: 위쪽 칸을 고르는 경우, 1번: 아랫쪽 칸을 고르는 경우, 2번: 아무 칸도 고르지 않는 경우
int solve(int*stickers[][2],int n,int i, int choice){//i번 이상의 스티커로 만드는 최댓값
    int &ret=cache[i][choice];
    if(ret!=-1) return ret;
    if(i==n-1){
        if(choice==0){
            return ret=
        }
        else if(choice==1){
            return ret=
        }
        else{//choice==3
            return ret=0;
        }
    }
    if(choice==0){
        ret=max(ret,stickers[n][0]+max(solve(stickers, n+1,1), solve(stickers, n+1,2)));
    }
    else if(choice==1){
        ret=stickers[n][1]+max(solve(stickers, n+1,0), solve(stickers, n+1,2));
    }
    else{//choice==3
        ret=max(solve(stickers, n+1,0), solve(stickers, n+1,1));
        ret=max(ret,solve(stickers, n+1,2));
    }
}
int main(){
    int T;//테스트 케이스의 개수
    cin>>T;

    for(int i=0;i<T;i++){
        int n;
        cin>>n;
        int stickers[100000][2];
        for(int i=0;i<n;i++){
            for(int j=0;j<3;j++){
                cache[i][j]=-1;
            }
        }
        
        for(int i=0;i<2;i++){
            for(int j=0;j<n;j++){
                cin>>stickers[j][i];
            }
        }
    }
}