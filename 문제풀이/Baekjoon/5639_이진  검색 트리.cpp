#include<iostream>
#include<vector>
using namespace std;

vector<int> postOrder(vector<int>&preOrdered){
    if(preOrdered.size()==0){
        vector<int> postOrder;
        return postOrder;
    }
    int key=preOrdered[0];
    vector<int> left;
    vector<int> right;
    vector<int> postOrdered;
    for(int i=1;i<preOrdered.size();i++){
        if(preOrdered[i]<key){//키보다 작으면 왼쪽
            left.push_back(preOrdered[i]);
        }
        else{
            right.push_back(preOrdered[i]);//키보다 크면 오른쪽
        }
        
        postOrder(left);
        postOrder(right);

        for(int i=0;i<left.size();i++){//left 의 변환결과, right의 변환결과, 
        //key 순으로 집어넣어 후위순회된 결과를 만들어 리턴한다.
            postOrdered.push_back(left[i]);
        }
        for(int i=0;i<right.size();i++){
            postOrdered.push_back(right[i]);
        }
        postOrdered.push_back(key);

        return postOrdered;
    }
}
int main(){
    //이진 검색 트리를 전위 순회한 결과가 주어질 때
    //그것을 후위 순회한 결과로 변환하여 한 줄에 하나씩 출력한다.
    vector<int> preOrdered;

    while(!cin.eof()){
        int a;
        cin>>a;
        preOrdered.push_back(a);
    }
    vector<int> answer=postOrder(preOrdered);

    for(int i=0;i<answer.size();i++){
        cout<<answer[i]<<endl;
    }
}