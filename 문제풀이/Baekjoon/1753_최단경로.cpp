#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int V,E;
int K;
vector<vector<pair<int,int>>>dist(20000);
int d[20000];// 시작점으로부터의 거리
#define INF 987654321;
bool visited[20000];


int main(){
    cin>>V>>E;
    cin>>K;
    for(int i=0;i<V;i++){
        visited[i]=false;
        d[i]=INF;
    }
    for(int i=0;i<E;i++){
        int u,v,w;
        cin>>u>>v>>w;
        dist[u-1].push_back(pair<int,int>(v-1,w));
    }
/////////////////////////////////////////////////////////////////
    class compare{
        public:
        bool operator() (pair<int,int> &a, pair<int, int> &b){
           return a.second>b.second;
       }
    };
   
    priority_queue<pair<int, int>, vector<pair<int,int>>,compare> q;
    d[K-1]=0;
    q.push(pair<int, int>(K-1, 0));


    while(!q.empty()){
        pair<int,int> now=q.top();
        q.pop();
        int num=now.first;
        if(visited[num]==true) continue;
        visited[num]=true;
        int distance=now.second;
        //해당 노드와 연결된 노드를 검사하면서 갱신된 경우에만 큐에 삽입함.
        for(int i=0;i<dist[num].size();i++){
            if(d[dist[num][i].first]>d[num]+dist[num][i].second){
                d[dist[num][i].first]=d[num]+dist[num][i].second;
                q.push(pair<int,int>(dist[num][i].first,d[num]+dist[num][i].second));
            }
        }



    }
//////////////////////////////////////////////////////
    for(int i=0;i<V;i++){
        if(d[i]>=987654321){
            cout<<"INF"<<endl;
        }
        else{
            cout<<d[i]<<endl;
        }
    }

}