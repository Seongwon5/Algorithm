#include<iostream>
#include<vector>

using namespace std;

int N;
int cache[2000][2000];
int arr[2000];

bool isPalindrome(int s, int e){

    int& ret= cache[s][e];
    if(ret!=-1) return ret;
    if(s==e) return ret=1;
    else if(s+1==e){
        if(arr[s]==arr[e])return ret=1;
        else{
            return ret=0;
        }
    }

    if(arr[s]==arr[e]&&isPalindrome(s+1,e-1)){
        ret=1;
    }
    else{
        ret=0;
    }
    return ret;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>N;
    for(int i=0;i<N;i++){
        cin>>arr[i];
    }
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cache[i][j]=-1;
        }
    }

    for(int i=0;i<N;i++){
        for(int j=i;j<N;j++){
            if(cache[i][j]==-1){
                isPalindrome(i,j);
            }
        }
    }

    int M;
    cin>>M;
    int s,e;
    for(int i=0;i<M;i++){
        cin>>s>>e;
        cout<<cache[s-1][e-1]<<'\n';
    }
}