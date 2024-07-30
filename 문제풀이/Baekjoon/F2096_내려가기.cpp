#include<iostream>

using namespace std;

int N;

int main(){
    //메모이제이션 배열의 초기화
    //입력부
    cin>>N;
    //게임 보드의 생성
   char board[100000][3];
    //입력부2
   for(int i=0;i<N;i++){
        for(int j=0;j<3;j++){
            char x;
            cin>> x;
            board[i][j]= x -'0';
        } 
   }
   int currentMinAnswer[3];//N
   int nextMinAnswer[3];//N-1

   int currentMaxAnswer[3];//N
   int nextMaxAnswer[3];//N-1
   for(int i=0;i<3;i++){
        nextMinAnswer[i]=board[N-1][i];
        nextMaxAnswer[i]=board[N-1][i];
   }
   for(int i=N-1;i>=1;i--){
    for(int j=0;j<3;j++){
        currentMaxAnswer[j]=nextMaxAnswer[j];
        nextMaxAnswer[j]=-1;
        currentMinAnswer[j]=nextMinAnswer[j]; 
        nextMinAnswer[j]=98765432;     
    }
    for(int j=0;j<3;j++){
        if(j==0){
            nextMinAnswer[0]=min(nextMinAnswer[0],currentMinAnswer[0]+board[i-1][j]);
            nextMinAnswer[0]=min(nextMinAnswer[0],currentMinAnswer[1]+board[i-1][j]);

            nextMaxAnswer[0]=max(nextMaxAnswer[0],currentMaxAnswer[0]+board[i-1][j]);
            nextMaxAnswer[0]=max(nextMaxAnswer[0],currentMaxAnswer[1]+board[i-1][j]);
        }
        else if(j==1){
            nextMinAnswer[1]=min(nextMinAnswer[1],currentMinAnswer[0]+board[i-1][j]);
            nextMinAnswer[1]=min(nextMinAnswer[1],currentMinAnswer[1]+board[i-1][j]);
            nextMinAnswer[1]=min(nextMinAnswer[1],currentMinAnswer[2]+board[i-1][j]);

            nextMaxAnswer[1]=max(nextMaxAnswer[1],currentMaxAnswer[0]+board[i-1][j]);
            nextMaxAnswer[1]=max(nextMaxAnswer[1],currentMaxAnswer[1]+board[i-1][j]);
            nextMaxAnswer[1]=max(nextMaxAnswer[1],currentMaxAnswer[2]+board[i-1][j]);
        }
        else{//j==2
            nextMinAnswer[2]=min(nextMinAnswer[2],currentMinAnswer[1]+board[i-1][j]);
            nextMinAnswer[2]=min(nextMinAnswer[2],currentMinAnswer[2]+board[i-1][j]);

            nextMaxAnswer[2]=max(nextMaxAnswer[2],currentMaxAnswer[1]+board[i-1][j]);
            nextMaxAnswer[2]=max(nextMaxAnswer[2],currentMaxAnswer[2]+board[i-1][j]);
        }      
    }
   }
    int minAnswer=98765432;
    int maxAnswer=-1;
   for(int i=0;i<3;i++){
     minAnswer=min(minAnswer,nextMinAnswer[i]);
     maxAnswer=max(maxAnswer,nextMaxAnswer[i]);
   }
   cout<<maxAnswer<<' '<<minAnswer;

}