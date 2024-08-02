//RGB거리에는 집이 N개 있다. 거리는 선분으로 나타낼 수 있고, 1번 집부터 N번 집이 순서대로 있다.
//집은 빨강, 초록, 파랑 중 하나의 색으로 칠해야 한다. 각각의 집을 빨강, 초록, 파랑으로 칠하는 비용이 주어졌을 때, 아래 규칙을 만족하면서 모든 집을 칠하는 비용의 최솟값을 구해보자.
//1번 집의 색은 2번 집의 색과 같지 않아야 한다.
//N번 집의 색은 N-1번 집의 색과 같지 않아야 한다.
//i(2 ≤ i ≤ N-1)번 집의 색은 i-1번, i+1번 집의 색과 같지 않아야 한다.


#include<iostream>
#include<vector>
using namespace std;
int cache[1000][3];
int N;
int solve(vector<vector<int>> &rgbPrice, int currentHouse, int currentColor){
    //currentHouse를 currentColor로 칠할 때, 이후 집까지를 포함하여
    //전체 RGB 거리를 칠하는 비용의 최솟값
    //집에 칠해진 색깔은 0, 1, 2로 구분한다.
    int& ret=cache[currentHouse][currentColor];
    if(ret!=-1) return ret;
    if(currentHouse==N-1){//최소 문제의 해답: 끝 집에 도착했을 경우
        return ret=rgbPrice[currentHouse][currentColor];
    }
    int minAnswer=99999999;
    //일반적인 경우의 해답: 현재 집의 색깔과 다른 두 개의 색깔을 다음 집에 칠하고,
    //두 경우 중 최솟값을 반환하여 이 함수의 반환값으로 한다.
    for(int i=0;i<3;i++){
        if(i!=currentColor){
            minAnswer=min(minAnswer,rgbPrice[currentHouse][currentColor]+solve(rgbPrice, currentHouse+1, i));
        }
    }
    return ret=minAnswer;
}
int main(){
    cin>>N;
    vector<vector<int>> rgbPrice;
    for(int i=0;i<1000;i++){
        for(int j=0;j<3;j++){
            cache[i][j]=-1;
        }
    }
    for(int i=0;i<N;i++){
        int r,g,b;
        cin>>r>>g>>b;
        vector<int>rgb={r, g, b};
        rgbPrice.push_back(rgb);
    }
    int minAnswer=99999999;
    for(int i=0;i<3;i++){
        minAnswer=min(minAnswer, solve(rgbPrice,0,i));
    }
    cout<<minAnswer;
}