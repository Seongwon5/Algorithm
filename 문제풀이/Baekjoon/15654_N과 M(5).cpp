#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
//N개의 자연수와 자연수 M이 주어졌을 때, 아래 조건을 만족하는 길이가
//M인 수열을 모두 구하는 프로그램을 작성하시오.
//N개의 자연수는 모두 다른 수이다.
//N개의 자연수 중에서 M개를 고른 수열

//수열은 사전 순으로 증가하는 순서대로 출력해야 한다.

//수열을 만들기 전에 미리 수들을 정렬해놓는다.
bool picked[8];
int N;
int M;
void makeSequence(vector<int> &orderedNumbers, vector<int> &sequence,int toPick);
int main(){
    cin>>N>>M;
    vector<int> orderedNumbers;
    vector<int> sequence;
    for(int i=0;i<N;i++){//N개의 수열을
        int x;
        cin>>x;
        orderedNumbers.push_back(x);
    }
    for(int i=0;i<8;i++){
        picked[i]=false;
    }
    sort(orderedNumbers.begin(),orderedNumbers.end());

    makeSequence(orderedNumbers, sequence, M);
  
}

void makeSequence(vector<int> &orderedNumbers, vector<int> &sequence, int toPick)
{
    if(toPick==0){
        for(int i=0;i<sequence.size();i++){
            cout<<sequence[i]<<' ';
        }
        cout<<'\n';
        return;
    }
    //사전 순으로 된 답을 만들도록 한다.
    for(int i=0;i<orderedNumbers.size();i++){
        if(picked[i]==false){
        sequence.push_back(orderedNumbers[i]);
        picked[i]=true;
        makeSequence(orderedNumbers, sequence, toPick-1);
        picked[i]=false;
        sequence.pop_back();    
        }
        
    }
}
