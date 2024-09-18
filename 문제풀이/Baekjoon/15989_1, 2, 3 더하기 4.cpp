#include<iostream>
using namespace std;
int cache[10001][4];
int solve(int n, int k){//현재 K까지 사용했을 때, 숫자 N을 만들 수 있는 경우의 수
//순서만 다른 것은 같은 것으로 판단하기 때문에 큰 수만 먼저 쓰도록 답의 순서를 강제한다.
    if(n<0)return 0;
    int& ret= cache[n][k];
    if(ret!=-1) return ret;
    if(n==0)return ret=1;
    ret=0;
    for(int i=3;i>=1;i--){
        if(k<i) continue;// 현재 사용할 수 있는 숫자보다 큰 숫자는 사용하지 못한다.
        ret+=solve(n-i,i);
    }
    return ret;
}
int main(){
    int T;
    cin>>T;
    for(int i=0;i<10001;i++){
        for(int j=0;j<4;j++){
            cache[i][j]=-1;
        }
    }
    for(int i=0;i<T;i++){
        int N;
        cin>>N;
        cout<<solve(N,3)<<endl;
    }
}