//이 문제에서 내가 저지른 가장 큰 실수: for문의 조건문은 for 루프 자체의 종료 조건이지,
//조건문이 false가 됐을때 건너뛰고 다음 수로 진행하게 되는 것이 아니다. 루프는 거기서 멈춘다.



#include<iostream>
#include<algorithm>
using namespace std;
int currentTeam[10];
int minAbilityDiff=99999999;
int getDiff(int**ability,int n,int*currentTeam){
    int enemyTeam[10];
    int teamSize=n/2;
    //cout<<"teamsize"<<teamSize<<endl;
    sort(currentTeam,currentTeam+teamSize);
    int j=0;
    int k=0;
    for(int i=0;i<n;i++){
        if(currentTeam[j]==i){
            j++;
        }
        else{//현재 숫자가 currentTeam에 없는 숫자일경우
            enemyTeam[k]=i;
            k++;
        }
    }
    int mTeamAbility=0;
    int eTeamAbility=0;
    for(int i=0;i<teamSize;i++){
        for(int j=0;j<teamSize;j++){
           // cout<<"i="<<i<<"j="<<j<<endl;
            mTeamAbility=mTeamAbility+ability[currentTeam[i]][currentTeam[j]];
            //cout<<"m팀능력치에"<<ability[currentTeam[i]][currentTeam[j]]<<"을 더합니다"<<endl;
            //cout<<"e팀능력치에"<<ability[enemyTeam[i]][enemyTeam[j]]<<"을 더합니다"<<endl;
            eTeamAbility=eTeamAbility+ability[enemyTeam[i]][enemyTeam[j]];
        }
    }
    //전체 n개의 숫자 중 currentteam에 없는 숫자들을 enemyTeam으로 결정한다.
    //cout<<"능력치는"<<mTeamAbility<<"대 "<<eTeamAbility<<"입니다"<<endl;
    int diff=mTeamAbility-eTeamAbility;
    if(diff>=0) return diff;
    else return -diff;
}
void getMin(int**ability,int*currentTeam,int n,int startIdx,int remain){
    if(remain==0){
        minAbilityDiff=min(minAbilityDiff,getDiff(ability,n,currentTeam));
    }
    else{
        for(int i=startIdx+1;i<=n-remain;i++){
            currentTeam[n/2-remain]=i;
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
    int currentTeam[10];
    getMin(ability,currentTeam,n,-1,n/2);
    cout<<minAbilityDiff<<endl;
}