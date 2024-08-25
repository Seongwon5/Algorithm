#include<iostream>
#include<queue>
using namespace std;
int d[100001];
bool visited[100001];
int N, K;
//실패한 최솟값 선형탐색 다익스트라 알고리즘을 이용한 풀이
/*int getNextIdx(){
    int min=98765432;
    int minIdx=-1;
    for(int i=0;i<100001;i++){
        if(d[i]<min&&!visited[i]){
            min=d[i];
            minIdx=i;
        }
    }
    return minIdx;
}
int main(){
    cin>>N>>K;
    for(int i=0;i<100001;i++){
        d[i]=98765432;
        visited[i]=false;
    }
    visited[N]=true;
    d[N]=0;
    d[N+1]=1;
    d[N-1]=1;
    d[2*N]=0;
    for(int i=0;i<100000;i++){
        int idx=getNextIdx();
        visited[idx]=true;
        if(idx+1<100001){
            d[idx+1]=min(d[idx+1],d[idx]+1);
        }
        if(idx-1>=0){
            d[idx-1]=min(d[idx-1],d[idx]+1);
        }
        if(idx*2<100001){
            d[2*idx]=min(d[2*idx],d[idx]);
        }
    }
    cout<<d[K]<<endl;
}
*/



//우선순위 큐를 활용한 풀이

int main(){
    cin>>N>>K;
    for(int i=0;i<100001;i++){
        d[i]=98765432;
        visited[i]=false;
    }
    //1.시작 노드를 방문처리한 후 시작 노드와 연결된 노드의 최소거리를 모두 
    //갱신한 후 큐에 노드 정보를 집어넣는다.

    //2.우선순위 큐의 탑 노드를 방문하여 pop 한 후 아직 방문하지 않은 노드인 경우
    //방문처리한 후, 그 노드와 연결된 노드의 최소거리를 현재와 비교하여
    //갱신하고, 만약 갱신되었다면 우선순위 큐에 갱신된 정보(노드 번호와 거리)를 삽입한다.

    //우선순위 큐가 모두 빌 때까지 반복한다.
    //우선순위 큐의 정렬 기준은 거리가 짧은 순이다.
    class compare{
        public:
        bool operator() (pair<int,int> &a, pair<int, int> &b){
           return a.second>b.second;
       }
    };
   

    priority_queue<pair<int, int>, vector<pair<int,int>>,compare> q;
    d[N]=0;
    q.push(pair<int, int>(N, 0));


    while(!q.empty()){
        pair<int,int> now=q.top();
        q.pop();
        int num=now.first;
        if(visited[num]==true) continue;
        visited[num]=true;
        int distance=now.second;

        if(num*2<100001){
            if(d[num*2]>d[num]){
                d[num*2]=d[num];
                q.push(pair<int,int>(num*2, d[num]));
            }
        }
        if(num+1<100001){
            if(d[num+1]>d[num]+1){
                d[num+1]=d[num]+1;
                q.push(pair<int,int>(num+1, d[num]+1));
            }
        }
        if(num-1>=0){
            if(d[num-1]>d[num]+1){
                d[num-1]=d[num]+1;
                q.push(pair<int,int>(num-1, d[num]+1));
            }
        }
    }

    cout<<d[K]<<endl;


}