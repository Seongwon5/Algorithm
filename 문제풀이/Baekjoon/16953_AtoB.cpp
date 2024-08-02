#include<iostream>
#define INF 99999999
#define MAX 1000000000
//오버플로우에 유의해야 했던 문제
using namespace std;

long long int solve(int tried, long long int A, long long int B){
    if (A==B) return tried;
    else{
        if(A>B) return INF;
        else{
            
            return min(solve(tried+1,A*2,B),solve(tried+1,A*10+1,B));
            
        }
    }
}
int main(){
    int a, b;
    cin>>a>>b;
    int answer=solve(0,a,b);
    if(answer==INF){
        cout<<"-1";
    }
    else{
        cout<<answer+1;
    }
}