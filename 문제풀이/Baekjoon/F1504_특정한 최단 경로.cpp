//이 문제를 틀린 이유:
//1.일단 실수가 너무 많음 반복문에서 i, j 헷갈리는거, 반복문 밖으로 빼야하는건데 안으로 넣은 것 등등
//2.다익스트라 알고리즘 자체를 완벽하게 짜지를 못함. 노드들 방문 처리 해주는것도 까먹었고, 
//현재 거리랑 새로 추가된 노드를 방문하는 거리를 계산할 때의 식도 틀림.
//다익스트라 알고리즘 짜는 연습을 해야할 것 같음.


#include<iostream>
#include<vector>
#define INF 1000000000
using namespace std;
long long int d[3][801];
bool visited[801];
long long int cost[801][801];
int N,E;
int v1, v2;//반드시 지나야하는 정점의 목록을 입력받는다.

int getMinIdx(int index){//현재 가장 시작점으로부터 가까운 방문하지 않은 노드의 인덱스를 구한다.
    int minIdx=1;
    int minVal=INF;
    for(int i=1;i<=N;i++){
        if(d[index][i]<=minVal&&(!visited[i])){
            minVal=d[index][i];
            minIdx=i;
        }
    }
    return minIdx;
}
void dijkstra(int start, int index){//start에서부터 다른 노드까지의 최단거리를 구하며, d 배열의 index 위치에 최솟값을 저장함.
    d[index][start]=0;//시작 정점의 거리를 0으로 설정함.
    visited[start]=true;
    for(int i=1;i<=N;i++){ 
        d[index][i]=min(cost[start][i],d[index][i]);
    }

    for(int i=1;i<=N;i++){
        int idx=getMinIdx(index);
        visited[idx]=true;
        //idx를 기준으로 연결된 모든 노드의 최소거리를 갱신한다.
        for(int j=1;j<=N;j++){
            if(!visited[j]){//이미 방문한 노드는 최소거리를 갱신하지 않음.
                d[index][j]=min(d[index][j],d[index][idx]+cost[idx][j]);
            }
        }
    }

}
int main(){
    cin>>N>>E;
    for(int i=0;i<=N;i++){
        for(int j=0;j<3;j++){
            d[j][i]=INF;
        }
        for(int j=0;j<=N;j++){
            if(i==j){//i==j 인 경우를 제외하고 모든 노드간의 거리를 무한으로 설정한다.
                cost[i][j]=0;
            }
            else{
                cost[i][j]=INF;
            }
        }
    }
    for(int i=0;i<E;i++){
        int from, to, c;
        cin>>from>>to>>c;
        cost[from][to]=c;
        cost[to][from]=c;//양방향에서 비용은 동일하다.
    }
    cin>>v1>>v2;
    int startNode[3]={1, v1, v2};
    for(int i=0;i<3;i++){
        for(int j=0;j<801;j++){
            visited[j]=false;//visited는 실행시마다 초기화시켜줘야 함.
        }
        dijkstra(startNode[i], i);
    }
    //세 시작점으로부터 모든 노드의 최소 거리를 구했으므로 v1, v2를 지나 N에 도달하는
    //모든 케이스들 중 최소 거리를 구한다.
    long long int answer=INF;
    answer=min(answer, d[0][v1]+d[1][v2]+d[2][N]);
    answer=min(answer, d[0][v2]+d[2][v1]+d[1][N]);

    if(answer>=INF){
        cout<<-1<<endl;
    }
    else{
        cout<<answer<<endl;
    }
}