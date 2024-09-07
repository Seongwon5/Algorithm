#include<iostream>
#include<vector>
#define INF 987654321;
using namespace std;
int N,M;//N과 M은 각각 사람의 수, 친구 관계의 수
bool connected[100][100];
int dist[100][100];
int main(){
    cin>>N>>M;
    for(int i=0;i<100;i++){
        for(int j=0;j<100;j++){
            if(i==j){
                dist[i][j]=0;
            }
            else{
                dist[i][j]=INF;
            }
        }
    }
    for(int i=0;i<M;i++){
        int x,y;
        cin>>x>>y;
        dist[x-1][y-1]=1;
        dist[y-1][x-1]=1;
    }
    
    

    for(int i=0;i<N;i++){//고려할 노드
        for(int j=0;j<N;j++){//출발 노드
            for(int k=0;k<N;k++){//도착 노드
               dist[j][k]=min(dist[j][k],dist[j][i]+dist[i][k]);
            }
        }
    }
    int minSum=INF;
    int minIdx=0;
    for(int j=N-1;j>=0;j--){//출발 지점.
        int sum=0;
        for(int k=0;k<N;k++){//도착 지점
            sum+=dist[j][k];
        }
        if(minSum>=sum){
            minSum=sum;
            minIdx=j;
        }
    }
    cout<<minIdx+1<<endl;
    
}