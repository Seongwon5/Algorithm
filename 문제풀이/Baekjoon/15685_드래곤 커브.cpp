#include<iostream>
#include<vector>
#include<stack>

using namespace std;
int N;

const int dx[4]={1,0,-1,0};//순서대로 방향 0,1,2,3, 스택에 넣었다 뺄 때는 숫자가 1씩 감소함.
const int dy[4]={0,-1,0,1};
bool board[101][101];
int main(){
    int count=0;
    cin>>N;
    for(int i=0;i<N;i++){
        int x,y,d,g;//순서대로 시작점, 시작 방향, 세대.

        cin>>x>>y>>d>>g;

        stack<int> direction;
        vector<int> dragonCurve;

        dragonCurve.push_back(d);//0세대 드래곤커브
        for(int k=0;k<g;k++){//세대만큼 반복함.
            for(int j=0;j<dragonCurve.size();j++){
                //k-1세대 드래곤커브의 모든 요소를 스택에 집어넣음.
                direction.push(dragonCurve[j]);
            }

            //스택의 위에서부터 빼면서 왼쪽으로 90도 회전시켜 벡터의 끝에 추가시킨다.

            while(!direction.empty()){
                int dir=direction.top();
                direction.pop();
                dragonCurve.push_back((dir+4+1)%4);
            }
        }
        //시작 방향 d를 토대로 세대를 구축함.
        //0세대를 기반으로 g번 스택에 넣었다 빼며 g세대를 구축함.

        //g세대를 구축한 이후에는 시작점을 기반으로 움직이며 점들을 찍어줌.
        board[x][y]=true;//시작점을 찍어줌.
        for(int k=0;k<dragonCurve.size();k++){
            x+=dx[dragonCurve[k]];
            y+=dy[dragonCurve[k]];
            //다음 점이 보드 안에 있다면 찍음

            if(x>=0&&x<=100&&y>=0&&y<=100){//보드판 안에 있는 경우
                board[x][y]=true;
            }
        }


    }

    //모든 드래곤커브를 다 그린 다음 보드판 안에 몇 개의 1x1정사각형이 있는지 검사함.

    for(int i=0;i<100;i++){
        for(int j=0;j<100;j++){
            if(board[i][j]==true&&board[i+1][j]==true&&board[i][j+1]==true&&board[i+1][j+1]==true){
                ++count;
            }
        }
    }



    
    cout<<count<<endl;
}