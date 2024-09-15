#include<iostream>
#include<vector>
using namespace std;

//크기가 N*N인 행렬 A가 주어질 때, A의 B제곱을 구하는 프로그램을 작성하라


///B는 1 이상 100억 이하, N은 2이상 6이하
long long N;
long long B;

vector<vector<long long>> mul(vector<vector<long long>>&P,vector<vector<long long>>&Q){
    //각 행렬은 N*N 행렬이다.
    vector<vector<long long>> ret(N,vector<long long>(N,0));
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            //현재 i,j 원소의 값을 결정하고 있음. 이 경우 P의 i행과 Q의 j열 원소들을 1대1로 대응시킴.
            //행렬의 각 원소는 그것을 1000으로 나눈 나머지이다.
            for(int k=0;k<N;k++){
                ret[i][j]+=(P[i][k]*Q[k][j])%1000000;
            }
            ret[i][j]%=1000000;
        }
    }
    return ret;
}
vector<vector<long long>> power(vector<vector<long long>>&A, long long B){
    if(B==1){//기저 사례: A의 1승
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                A[i][j]%=1000000;
            }
        }
        return A;
    }
    if(B%2==0){//짝수승: 정확히 반 크기로 가른다.
        vector<vector<long long>> multiplied= power(A,B/2);
        return mul(multiplied,multiplied);
    }
    else{//홀수승: 1개를 떼어내고 반 크기로 가른다.
        vector<vector<long long>> multiplied= power(A,(B-1)/2);
        vector<vector<long long>> mid= mul(multiplied,multiplied);
        return mul(mid,A);
    }
}
int main(){
    //입력부
    N=2;
    cin>>B;
    vector<vector<long long>> A(N,vector<long long>(N));
    A[0][0]=1;A[0][1]=1;
    A[1][0]=1;A[1][1]=0; 
    vector<vector<long long>> ret= power(A,B);
    cout<<ret[0][1]<<endl;


/////////////////////////////////////////////////////////////

}