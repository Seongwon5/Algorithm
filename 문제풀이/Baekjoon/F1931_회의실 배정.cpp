#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
struct meeting{
    int start;
    int end;
};
bool compare(meeting&a, meeting&b){
    if(a.end<b.end){
       return true;
    }
    else if(a.end==b.end){
        if(a.start<b.start){
            return true;
        }
        else{
            return false;
        }
    }
    return false;
    
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int N;
    cin>>N;
    vector<meeting> meetings;
    meeting m;
    for(int i=0;i<N;i++){
        cin>>m.start>>m.end;
        meetings.push_back(m);
    }
    sort(meetings.begin(),meetings.end(),compare);

    int lastend=0;
    int count=0;
    for(int i=0;i<N;i++){
        if(meetings[i].start>=lastend){
            lastend=meetings[i].end;
            count++;
        }
    }

    cout<<count;
}