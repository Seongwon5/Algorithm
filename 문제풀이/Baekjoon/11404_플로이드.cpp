#include<iostream>
#define INF 987654321;
int dist[101][101];
using namespace std;
int main(){
    int n;
    int m;
    cin>>n>>m;

    for(int i=0;i<101;i++){
        for(int j=0;j<101;j++){
            if(i==j){
                dist[i][j]=0;
            }
            else{
                dist[i][j]=INF;
            }
        }
    }

    for(int i=0;i<m;i++){
        int a,b,c;
        cin>>a>>b>>c;
        dist[a][b]=min(dist[a][b],c);
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            for(int k=1;k<=n;k++){
                dist[j][k]=min(dist[j][k],dist[j][i]+dist[i][k]);
            }
        }
    }


    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(dist[i][j]>=98765432){
                cout<<"0 ";
            }
            else{
                cout<<dist[i][j]<<' ';
            }
        }
        cout<<endl;
    }
}