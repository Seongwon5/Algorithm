#include<iostream>
#include<vector>
using namespace std;
typedef pair<int,int> chicken;
typedef pair<int,int> house;
int N, M;
int minAns=98765432;
vector<chicken> chickens;
vector<house> houses;
vector<chicken> picked;
int board[50][50];
void solve(vector<chicken>&picked,int lastIndex, int topick){
    if(topick==0){//치킨집을 M개 고른 후에 도시의 치킨 거리를 계산하는 과정
        int cityChickenDist=0;//도시의 치킨 거리
        for(int i=0;i<houses.size();i++){
            int minChickenDist=98765432;
            for(int j=0;j<picked.size();j++){
                int xDiff=abs(houses[i].first-picked[j].first);
                int yDiff=abs(houses[i].second-picked[j].second);
                int dist=xDiff+yDiff;
                minChickenDist=min(minChickenDist, dist);
            }
            cityChickenDist+=minChickenDist;
        }
        minAns=min(minAns,cityChickenDist);
        return;
    }
    //아직 뽑을 원소가 남아있는 경우
    for(int i=lastIndex+1; i<=chickens.size()-topick;i++){
        chicken now=chickens[i];//치킨집을 하나 고름.
        picked.push_back(now);
        solve(picked, i, topick-1);//다음 상태를 호출함.
        picked.pop_back();//한 가지 상태를 만든 후에 다음 상태를 만들기 위해
        //pop을 해줌.
    }

}
//치킨집들의 정보는 벡터에 저장한다.


int main(){
    cin>>N>>M;//입력부 시작
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cin>>board[i][j];
            if(board[i][j]==1){
                houses.push_back(house(i,j));
            }
            else if(board[i][j]==2){
                chickens.push_back(chicken(i,j));
            }
        }
    }
    //입력부 끝.
    solve(picked, -1, M);
    cout<<minAns<<endl;
}