#include<iostream>
#include<vector>
using namespace std;
int d[801];
bool visited[801];
vector<pair<int, int>> edges[801];
int N,E;
int v1, v2;//반드시 지나야하는 정점의 목록을 입력받는다.
int main(){
    cin>>N>>E;
    for(int i=0;i<=N;i++){
        d[i]=1000000000;
        visited[i]=false;
    }
    for(int i=0;i<E;i++){
        int from, to, cost;
        cin>>from>>to>>cost;
        edges[from].push_back(pair<int,int>(to,cost));
        edges[to].push_back(pair<int, int>(from, cost));//양방향 간선이므로 반대편에서도 올 수 있도록 함.
    }
    cin>>v1>>v2;

    visited[1]=true;
    d[1]=0;
    for(int i=0;i<edges[1].size();i++){//해당 노드와 연결된 모든 노드를 갱신한다.
        d[edges[1][i].first]=min(d[edges[1][i].first],d[1]+edges[1][i].second);
    }

    for(int i=2;i<=N;i++){//N번 반복
        for(int j=0;j<edges[i].size();j++){
                d[edges[i][j].first]=min(d[edges[i][j].first],d[i]+edges[i][j].second);
        }   
    }
    if(d[N]>=999999991){
        cout<<-1<<endl;}
    else{
            cout<<d[N]<<endl;
    }
    

    
}