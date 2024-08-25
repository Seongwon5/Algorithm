#include<iostream>

using namespace std;
int N;//줄 수
int rowLevelSize[11];//레벨 별로 필요한 배열의 한 변의 길이를 저장한 배열
int colLevelSize[11];
void star(char**arr, int row, int col, int mlevel){
    //기저 사례: 0단계 그리기
    if(mlevel==0){
        arr[row][col]='*';
        arr[row+1][col-1]='*';
        arr[row+1][col+1]='*';
        for(int i=col-2;i<=col+2;i++){
            arr[row+2][i]='*';
        }
        return;
    }
    //재귀호출
    star(arr, row, col, mlevel-1);
    star(arr, row+rowLevelSize[mlevel-1], col+(colLevelSize[mlevel-1]+1)/2, mlevel-1);
    star(arr, row+rowLevelSize[mlevel-1], col-(colLevelSize[mlevel-1]+1)/2, mlevel-1);
}
int main(){
    rowLevelSize[0]=3;
    colLevelSize[0]=5;
    for(int i=1;i<11;i++){
        rowLevelSize[i]=rowLevelSize[i-1]*2;
        colLevelSize[i]=colLevelSize[i-1]*2+1;
    }
    cin>>N;
    N/=3;
    int level=0;
    while(N/2>0){
        N/=2;
        level++;
    }
    //이로써 level도 구했다.
    int rowSize=rowLevelSize[level];
    int colSize=colLevelSize[level];
    char** arr=new char*[rowSize];
    for(int i=0;i<rowSize;i++){
        arr[i]=new char[colSize];
    }//2차원 배열의 저장과 출력을 위한 size*size 배열이 완성되었다.

    for(int i=0;i<rowSize;i++){
        for(int j=0;j<colSize;j++){
            arr[i][j]=' ';
        }
    }
    star(arr, 0, (colSize-1)/2, level);
    for(int i=0;i<rowSize;i++){
        for(int j=0;j<colSize;j++){
            cout<<arr[i][j];
        }
        cout<<endl;
    }
}

