#include<iostream>
using namespace std;
long long int K, N;
long long int length[100000];
int main(){
    cin>>K>>N;
    for(int i=0;i<K;i++){
        cin>>length[i];
    }
    int min=1;
    int max=INT32_MAX;
    for(int i=1;true;i++){
        long long int num=0;
        for(int j=0;j<K;j++){
            num=num+length[j]/i;
        }
        if(num>=N) continue;
        else{
            cout<<i-1<<endl;
            break;
        }
    }
}