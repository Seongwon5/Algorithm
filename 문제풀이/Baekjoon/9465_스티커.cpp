#include<iostream>
using namespace std;

int cache[100000][3];//0번: 이전에 위쪽 칸을 고른 경우, 1번: 이전에 아랫쪽 칸을 고른 경우, 2번: 이전에 아무 칸도 고르지 않은 경우
int solve(int stickers[][2],int n,int i, int choice){//i번 이상의 스티커로 만드는 최댓값
    int &ret=cache[i][choice];
    if(ret!=-1) return ret;
    if(i==n-1){//기저 사례: 마지막 칸에 도달한 경우
        if(choice==0){
            return ret=stickers[i][1];//아래 칸을 선택한다.
        }
        else if(choice==1){
            return ret=stickers[i][0];//위쪽 칸을 선택한다.
        }
        else{//이전에 아무 칸도 선택하지 않았던 경우
            return ret=max(stickers[i][0],stickers[i][1]);//두 칸 중에 더 큰 것을 선택한다.
        }
    }
    if(choice==0){//이전에 위쪽 칸을 골랐던 경우. 아래 칸을 고르든지, 아무것도 안 고르든지 둘 중 하나.
        ret=max(stickers[i][1]+solve(stickers, n, i+1, 1),solve(stickers, n, i+1, 2));
    }
    else if(choice==1){
        ret=max(stickers[i][0]+solve(stickers, n, i+1, 0),solve(stickers, n, i+1, 2));
    }
    else{//choice==2//아무것도 고르지 않은 경우: 어떤 선택을 하든 상관없다.
        ret=max(stickers[i][0]+solve(stickers, n, i+1, 0),stickers[i][1]+solve(stickers, n, i+1, 1));
        ret=max(ret,solve(stickers, n, i+1, 2));
    }
    return ret;//구한 최댓값을 리턴한다.
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

        cout<<solve(stickers, n , 0, 2)<<endl;//0번째 칸은 이전 칸이 없지만, 이전에 아무것도 고르지 않은 경우와 동일하다.
    }

}