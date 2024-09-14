#include<iostream>
#include<queue>
using namespace std;

int main(){
    
    priority_queue<int> minQueue;
    priority_queue<int> maxQueue;

    int N;
    cin>>N;
    for(int i=0;i<N;i++){
        int x;
        cin>>x;

        if(i==0){
            maxQueue.push(x);
            cout<<x<<'\n';
        }
        else{
            if(maxQueue.top()<x){
                minQueue.push(-x);
                if(maxQueue.size()<minQueue.size()){
                    int mintop=-minQueue.top();
                    minQueue.pop();
                    maxQueue.push(mintop);
                }
            }
            else{
                maxQueue.push(x);
                if(maxQueue.size()>minQueue.size()+1){
                    int maxtop=maxQueue.top();
                    maxQueue.pop();
                    minQueue.push(-maxtop);
                }
            }
            cout<<maxQueue.top()<<'\n';
        }
    }
}