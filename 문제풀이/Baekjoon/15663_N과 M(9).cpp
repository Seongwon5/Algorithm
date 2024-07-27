#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
using namespace std;
//N개의 자연수와 자연수 M이 주어졌을 때, 아래 조건을 만족하는 길이가
//M인 수열을 모두 구하는 프로그램을 작성하시오.
//이 문제는 중복된 수들이 제공될 수 있다는 점에서 문제가 생긴다.
//중복된 수들은 수열에 모두 포함될 수는 있지만, 같은 수열이 여러 개 생길 수 있다는 점이 문제이다.
//따라서 각 단계에서 사용했던 수들을 모두 저장하고
//한 번의 함수 호출에서 한 가지 숫자는 한 번만 사용되도록 해야 한다.
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
    map<int,bool> selected;
    for(int i=0;i<orderedNumbers.size();i++){
        selected[orderedNumbers[i]]=false;
    }
    //사전 순으로 된 답을 만들도록 한다.
    for(int i=0;i<orderedNumbers.size();i++){
        if(picked[i]==false&&selected[orderedNumbers[i]]==false){
        selected[orderedNumbers[i]]=true;
        sequence.push_back(orderedNumbers[i]);
        picked[i]=true;
        makeSequence(orderedNumbers, sequence, toPick-1);
        picked[i]=false;
        sequence.pop_back();    
        }
        
    }
}
