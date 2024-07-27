#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
using namespace std;
int N;
int M;
void makeSequence(vector<int> &orderedNumbers, vector<int> &sequence,int lastPicked,int toPick);
int main(){
    cin>>N>>M;
    vector<int> orderedNumbers;
    vector<int> sequence;
    for(int i=0;i<N;i++){
        int x;
        cin>>x;
        orderedNumbers.push_back(x);
    }
    sort(orderedNumbers.begin(),orderedNumbers.end());

    makeSequence(orderedNumbers, sequence,0,M);
  
}

void makeSequence(vector<int> &orderedNumbers, vector<int> &sequence,int lastPicked, int toPick)
{
    if(toPick==0){
        for(int i=0;i<sequence.size();i++){
            cout<<sequence[i]<<' ';
        }
        cout<<'\n';
        return;
    }
    map<int,bool> selected;
    for(int i=0;i<orderedNumbers.size();i++){
        selected[orderedNumbers[i]]=false;
    }
    //사전 순으로 된 답을 만들도록 한다.
    for(int i=lastPicked;i<orderedNumbers.size();i++){
        if(selected[orderedNumbers[i]]==false){
        selected[orderedNumbers[i]]=true;
        sequence.push_back(orderedNumbers[i]);
        makeSequence(orderedNumbers, sequence,i,toPick-1);
        sequence.pop_back();    
        }
        
    }
}
