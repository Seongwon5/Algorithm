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
            for(int k=0;k<N;k++){
                ret[i][j]+=P[i][k]*Q[k][j];
            }
        }
    }
}
int main(){
    //입력부
    cin>>N>>B;
    vector<vector<long long>> A(N,vector<long long>(N));    
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cin>>A[i][j];
        }
    }


/////////////////////////////////////////////////////////////



}