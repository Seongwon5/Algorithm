#include<iostream>
using namespace std;
int N;//도시의 수
int W[17][17];//비용을 저장할 배열
int cache[65536][17];//행은 방문한 도시의 집합, 열은 마지막으로 방문한 도시의 번호
#define INF 987654321;
unsigned short filled=0;
//처음에 1번 도시를 방문하고, 모든 도시를 방문한 후에 다시 1번 도시로 돌아와야 하는 문제이다.
//함수 TSP의 정의: 현재 set 도시들을 방문했을 때, 남은 도시들을 방문하고 1번 도시로 돌아오는
//비용의 최솟값. 
//기저 사례: 만약 모든 도시를 방문했다면, 도시 last에서 1번으로 돌아갈 수 있는 경우에는 last-1 간선
//의 비용을 반환하고 last -1 간선이 없는 경우에는 INF를 반환한다.
int TSP(unsigned short set, int last){
    //기저 사례
    int &ret= cache[set][last];
    if(ret!=-1) return ret;
    if(set==filled){//모든 도시를 방문한 경우
        if(W[last][1]==0){
            return ret=INF;
        }
        else{
            return ret=W[last][1];
        }
    }
    //일반적인 사례
    //연결된 도시 중 아직 방문하지 않은 도시들에 대하여,
    //그들 도시를 set에 추가하여 재귀 호출을 한 뒤 모든 케이스의 비용 최솟값을 구해서 리턴한다.
    bool visited[17];
    ret=INF;
    for(int i=0;i<N;i++){
        if((1<<i)&set){//오른쪽에서 i번째 비트가 켜져있는 경우
            visited[i+1]=true;
        }
        else{
            visited[i+1]=false;
        }
    }
    for(int i=1;i<=N;i++){
        if(visited[i]==false&&W[last][i]!=0){//아직 방문하지 않은 연결된 노드
            int newSet=(1<<i-1)|set;//기존 set에 i번 정점의 비트를 추가로 켠 상태
            ret=min(ret,W[last][i]+TSP(newSet,i));//
        }
    }
    return ret;
    
}
int main(){
    cin>>N;
    for(int i=1;i<=N;i++){
        for(int j=1;j<=N;j++){
            cin>>W[i][j];//각각의 간선의 길이를 입력받는다.
            //간선이 존재하지 않는 경우는 0을 입력받는다.
        }
        for(int i=0;i<65536;i++){
            for(int j=0;j<17;j++){
                cache[i][j]=-1;
            }
        }
    }
    for(int i=0;i<N;i++){
        filled=filled|(1<<i);
    }
    cout<<TSP(1, 1);
}