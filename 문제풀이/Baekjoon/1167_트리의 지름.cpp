#include<iostream>
#include<vector>
using namespace std;
//1167_트리의 지름
//내 아이디어: 모든 점에서 탐색을 수행하고(틀림), 더이상 탐색할 수 없을때까지
//bfs 수행, 탐색의 끝에 도달하면 현재까지 경로의 길이와
//현재 가장 긴 경로의 길이를 비교하여 최댓값을 저장함.

//가장 긴 경로의 길이가 트리의 지름일 것으로 예상됨.

//내가 처음에 틀린 이유: 모든 점에서 탐색을 수행하면 입력이 최대 10만이므로
//시간 내에 해결할 수 없다. dfs를 두 번만 수행하면
//첫번째 시도에 한쪽 끝에 도달하고 두 번째 시도에 트리의 지름을 구할 수 있음을
//깨달아 문제를 해결했다.

bool visited[100001];
int V;
int maxPath=0;
int maxNode=0;
class NODE{
    public:
    int to;
    int cost;
    NODE(int to, int cost){
        this->to=to;
        this->cost=cost;
    }
} ;
vector<NODE> nodes[100001];
void dfs(int n,int curLength){
    visited[n]=true;
    int able=0;
    for(int i=0;i<nodes[n].size();i++){
        if(!visited[nodes[n][i].to]){
            dfs(nodes[n][i].to, curLength+nodes[n][i].cost);
            able++;
        }
    }
    if(able==0){
        if(maxPath<curLength){
            maxNode=n;
            maxPath=curLength;
        }
    }
    visited[n]=false;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>V;
    for(int i=1;i<=V;i++){//모든 정점에 연결된 간선을 입력받는다.
        int num;
        cin>>num;
        
        int to, cost;
        cin>>to;
        while(to!=-1){
            cin>>cost;
            nodes[num].push_back(NODE(to,cost));
            cin>>to;
        }
    }
    for(int i=1;i<=V;i++){
        visited[i]=false;
    }

    dfs(1,0);
    dfs(maxNode,0);
    cout<<maxPath;
}