#include<iostream>
#include<vector>

using namespace std;
#define INF 10000000;
int N, M, X;
int cost[1000][1000];

int main(){
    cin>>N>>M>>X;
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            if(i==j){
                cost[i][j]=0;
            }
            else{
                cost[i][j]=INF;
            }
        }
    }

    for(int i=0;i<M;i++){
        int start, end, time;
        cin>>start>>end>>time;
        cost[start-1][end-1]=time;
    }

    //플로이드 워셜 알고리즘의 적용
    for(int i=0;i<N;i++){//0번 정정부터 N번 정점까지 순서대로 추가하면서 고려
        for(int j=0;j<N;j++){//시작점 
            for(int k=0;k<N;k++){//끝점 
                cost[j][k]=min(cost[j][k],cost[j][i]+cost[i][k]);
            }
        }
    }
    int answer=-1;
    for(int i=0;i<N;i++){
        int num=cost[i][X-1]+cost[X-1][i];
        answer=max(answer,num);
    }
    cout<<answer<<endl;
}