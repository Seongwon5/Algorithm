#include<iostream>
using namespace std;
int currentTeam[10];
int minAbilityDiff=99999999;
int getDiff(int*ability,int n,int*currentTeam){
    int enemyTeam[10];
    //전체 n개의 숫자 중 currentteam에 없는 숫자들을 enemyTeam으로 결정한다.
    //모든 ability의 합은 ab 와 ba의 경우가 다르므로 단순히 n size의 for문을 2개 돌림으로써 모든 ability의
    //총합을 계산할 수 있다. getmain처럼 모든 순서를 구하는 것이 아니라 2명의 순서쌍만 구하면 된다.
    return 0;
}
void getMin(int*ability,int*currentTeam,int n,int startIdx,int remain){
    if(remain==0){
        minAbilityDiff=min(minAbilityDiff,getDiff(ability,n,currentTeam));
    }
    else{
        for(int i=startIdx+1,i<=n-remain;i++){
            currentTeam[N/2-remain]=startIdx;
            getMin(ability,currentTeam,n,i,remain-1);
        }
    }
}
int main(){
    int n;
    cin>>n;
    int **ability=new int*[n];
    for(int i=0;i<n;i++){
        ability[i]=new int[n];
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>ability[i][j];
        }
    }
}