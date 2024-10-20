#include<iostream>
#include<algorithm>
using namespace std;

int arr[100000];
int n;
int x;
int s=0;
int e;

int sum=0;
int main(){
    cin>>n;
    e=n-1;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    sort(arr,arr+n);
    cin>>x;
    while(true){
        if(e==s) break;
        if(arr[s]+arr[e]>x){
            --e;
        }
        else if(arr[s]+arr[e]<x){
            ++s;
        }
        else{//같은 경우
            --e;
            ++sum;
        }
    }

    cout<<sum<<endl;
}