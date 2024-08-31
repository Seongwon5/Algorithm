#include<iostream>
#include<queue>
#include<vector>
struct doc{
    int pir;
    int index;
};
using namespace std;
int T;
int main(){
    cin>>T;
    for(int i=0;i<T;i++){
        vector<doc> que;
        int N, M;
        cin>>N>>M;
        for(int i=0;i<N;i++){
            doc x;
            x.index=i;
            cin>>x.pir;
            que.push_back(x);
        }
        int ans=0;
        while(true){
            int count=0;
            doc x=que.front();
            for(int i=1;i<que.size();i++){
                if(que[i].pir>x.pir){
                    count++;
                    que.erase(que.begin());
                    que.push_back(x);
                    break;
                }
            }
            if(count==0){//x의 우선순위가 가장 높은 경우
                ans++;
                if(x.index==M){
                    que.erase(que.begin());
                    break;
                }
                else{
                    que.erase(que.begin());
                }
            }
        }
        cout<<ans<<endl;
    }
}