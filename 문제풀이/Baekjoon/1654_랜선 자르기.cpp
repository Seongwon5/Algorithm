#include<iostream>
using namespace std;
long long int K, N;
long long int length[100000];
int main(){
    cin>>K>>N;
    for(int i=0;i<K;i++){
        cin>>length[i];
    }
    long long int min=1;
    long long int max=INT32_MAX;
    long long int ans;
    while(true){
        long long int mid=(max+min)/2;
        if(max-min<=1){//mid가 min 또는 max와 같은 경우=기저사례
            long long int minans=0;
            long long int maxans=0;
            for(int i=0;i<K;i++){
            minans+=length[i]/min;
            }
            for(int i=0;i<K;i++){
            maxans+=length[i]/max;
            }
            if(maxans>=N) {
                ans=max;
            }
            else{
                ans=min;
            }
            break;
        }
        long long int num=0;
        for(int i=0;i<K;i++){
            num+=length[i]/mid;
        }
        if(num>=N){//개수가 충분한 경우
            min=mid;
        }
        else{//개수가 부족한 경우
            max=mid;
        }
        
    }
    cout<<ans<<endl;
}