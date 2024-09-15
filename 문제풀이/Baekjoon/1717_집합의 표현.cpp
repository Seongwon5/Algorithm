#include<iostream>

int arr[1000000];
int N,M;

using namespace std;

int search(int a){
    if(arr[a]==a)return a;
    else{
        return arr[a]=search(arr[a]);
    }
}

void merge(int a, int b){
    int A=search(a);
    int B=search(b);

    if(A==B)return;
    if(A<B){
        arr[B]=A;
    }
    else{
        arr[A]=B;
    }
    
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin>>N>>M;
    for(int i=0;i<N+1;i++){
        arr[i]=i;
    }
    
    int op;
    int a,b;
    for(int i=0;i<M;i++){
        cin>>op>>a>>b;

        if(op==0){//union(a,b)
            merge(a,b);
        }
        else{//if find(a)==find(b)
            if(search(a)==search(b)){
                cout<<"YES"<<'\n';
            }
            else{
                cout<<"NO"<<'\n';
            }
        }
    }
}