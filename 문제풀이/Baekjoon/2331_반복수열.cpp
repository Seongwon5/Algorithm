#include<iostream>
#include<vector>
using namespace std;


int A, P;
int pow(int n, int p){
    if(p==1) return n;
    else{
        return n* pow(n,p-1);
    }
}
int getNext(int n, int p){
    int x=n;
    int ret=0;
    while(x){
        ret=ret+pow(x%10,p);
        x/=10;
    }
    return ret;
}
int main(){
    cin>>A>>P;
    vector<int> arr;
    arr.push_back(A);
    bool pattern=false;
    int index=-1;
    while(!pattern){
        for(int i=0;i<arr.size();i++){
            if(arr[i]==getNext(arr.back(),P)){
                pattern=true;
                index=i;
                break;
            }
        }
        //패턴이 발견되지 않는 경우
        arr.push_back(getNext(arr.back(),P));
    }

    cout<<index<<endl;
}