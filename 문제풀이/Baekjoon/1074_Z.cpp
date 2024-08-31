#include<iostream>
using namespace std;

int pow2[16];//배열의 가로, 세로 크기
int N;

long long int solve(int N,int i,int j,int x, int y, int p, int q){
    int size=pow2[N];
    int total=pow2[N]*pow2[N];
    int mid=pow2[N]/2;
    int rowmid=(x+p)/2;
    int colmid=(y+q)/2;
    

    if(i<rowmid&&j<colmid){//1사분면
        if(N==1){return 0;}
        //cout<<0*total/4<<endl;
        return solve(N-1,i,j,x,y,rowmid,colmid);
    }
    else if(i<rowmid&&j>=colmid){//2사분면
        if(N==1){return 1;}  
       // cout<<1*total/4<<endl;
        return (total/4)+solve(N-1,i,j,x,colmid,rowmid,q);
    }
    else if(i>=rowmid&&j<colmid){//3사분면
        if(N==1){return 2;}
        //cout<<2*total/4<<endl;
        return 2*(total/4)+solve(N-1,i,j,rowmid,y,p,colmid);
    }
    else if(i>=rowmid&&j>=colmid){//4사분면
        if(N==1){return 3;}
        //cout<<3*total/4<<endl;
        return 3*(total/4)+solve(N-1,i,j,rowmid,colmid,p,q);
    }
    else{
        return -1;
    }
}
int main(){
    cin>>N;
    pow2[0]=1;
    for(int i=1;i<16;i++){
        pow2[i]=pow2[i-1]*2;
    }

    int i, j;
    cin>>i>>j;

    cout<<solve(N, i, j,0,0,pow2[N],pow2[N])<<endl;
}