#include<iostream>
#include<vector>
#include<string>

using namespace std;

string str;
bool* visited;
int N;
void pickNext(int current){
    
    while(true){
        char minChar='Z'+1;
        int next=-1;
        for(int i=current+1;i<N;i++){
            if(str[i]<minChar&&!visited[i]){
                minChar=str[i];
                next=i;
            }
        }
        if(next==-1)break;
        //다음으로 고를 원소를 선택한 상태이다.
        //그 원소를 방문처리하고 현재까지 선택된 원소들을 출력한다.
        visited[next]=true;
        for(int i=0;i<str.size();i++){
            if(visited[i]){
                cout<<str[i];
            }
        }
        cout<<endl;

        //재귀호출하여 다음 원소를 찾는다.
        pickNext(next);
    }

}
int main(){
    cin>>str;
    if(str.size()!=0){
        N=str.size();//문자열의 길이
    }
    else{
        exit(0);
    }
    visited= new bool[N];
    
    for(int i=0;i<N;i++){
        visited[i]=false;
    }

    pickNext(-1);
    



}