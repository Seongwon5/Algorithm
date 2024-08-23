#include<iostream>
#include<vector>
using namespace std;

/*vector<int> postOrder(vector<int>&preOrdered){
    //cout<<"함수의 시작점"<<endl;
    if(preOrdered.size()==0){
        vector<int> postOrder;
        return postOrder;
    }
    int key=preOrdered[0];
    vector<int> postOrdered;
    if(preOrdered.size()==1){
        postOrdered.push_back(key);
        return postOrdered;
    }
    //cout<<"key 값은"<<key<<endl;
    vector<int> left;
    vector<int> right;
    for(int i=1;i<preOrdered.size();i++){
        if(preOrdered[i]<key){//키보다 작으면 왼쪽
            //cout<<preOrdered[i]<<"는 키보다 작으므로 left"<<endl;
            left.push_back(preOrdered[i]);
        }
        else{
           // cout<<preOrdered[i]<<"는 키보다 크므로 right"<<endl;
            right.push_back(preOrdered[i]);//키보다 크면 오른쪽
        }
    }    
    left=postOrder(left);
    right=postOrder(right);

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
*/
void postOrder(vector<int>&preOrdered, int start, int end)//start부터 end이전까지의 원소들을 preOrdered에서 postOrdered로 바꾼다.
{
    if(start==end)return;//기저 사례.
    int key=preOrdered[start];
    int marker=start+1;
    for(int i=start+1;i<end;i++){
        if(preOrdered[marker]>key){
            break;
        }
        marker++;
    }
    postOrder(preOrdered,start+1,marker);
    postOrder(preOrdered,marker,end);
    //key를 제외한 왼쪽, 오른쪽 자식의 후위순회 결과가 도출된 상태임.
    //key의 위치만 마지막으로 옮겨주면 됨.
    preOrdered.erase(preOrdered.begin()+start);
    preOrdered.insert(preOrdered.begin()+end-1,key);
}
int main(){
    //이진 검색 트리를 전위 순회한 결과가 주어질 때
    //그것을 후위 순회한 결과로 변환하여 한 줄에 하나씩 출력한다.
    vector<int> preOrdered;

    while(!cin.eof()){
        int a;
        cin>>a;
        if(cin.eof()) break;
        preOrdered.push_back(a);
    }
    //cout<<"mmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmm"<<endl;
    postOrder(preOrdered,0,preOrdered.size());

    for(int i=0;i<preOrdered.size();i++){
        cout<<preOrdered[i]<<endl;
    }
}