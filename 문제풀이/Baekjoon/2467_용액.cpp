#include<algorithm>
#include<iostream>
using namespace std;
int main(){
    int left=0;//출력할 왼쪽 값
    int right=0;//출력할 오른쪽 값
    int hap=2100000000;
    int nearZeroIndex=-1;//0과 가장 가까운 인덱스의 값;
    int nearZeroValue=2100000000;
    int N;
    cin>>N;
    
    int* arr= new int[N];//용액의 정보를 저장할 배열
    for(int i=0;i<N;i++){
        cin>>arr[i];
    }

    sort(arr,arr+N);//배열을 크기순으로 정렬

    for(int i=0;i<N;i++){
        int value=abs(arr[i]);//절댓값을 구함
        if(value<nearZeroValue){//절댓값의 최솟값이 갱신되는 경우
            nearZeroValue=value;
            nearZeroIndex=i;
        }
    }

    //0과 가장 가까운 인덱스가 정해짐. 이 값은 배열의 끝일 수도 있음.
    int leftIndex=nearZeroIndex;
    int rightIndex=nearZeroIndex;
    if(nearZeroIndex==0){
        left=nearZeroIndex;
        right=nearZeroIndex+1;
    }
    else if(nearZeroIndex==N-1){
        left=nearZeroIndex-1;
        right=nearZeroIndex;
    }
    //0과 가장 가까운 값이 맨 오른쪽이나 왼쪽에 있지 않은 경우
    else{
        if(abs(arr[nearZeroIndex-1]<abs(arr[nearZeroIndex+1]))){
            leftIndex--;
        }
        else{
            rightIndex++;
        }
        while(true){
        //cout<<arr[leftIndex]<<","<<arr[rightIndex]<<"의 경우 확인"<<endl;
        int sumAbx=abs(arr[leftIndex]+arr[rightIndex]);
        if(sumAbx<hap){
            left=leftIndex;
            right=rightIndex;
            hap=sumAbx;
        }


        if(abs(arr[leftIndex])<=abs(arr[rightIndex])){//오른쪽 절댓값이 더 큰 경우
            if(leftIndex-1<0) break;
            else leftIndex--;
        }
        else{//왼쪽 절댓값이 더 큰 경우
            if(rightIndex+1>=N) break;
            else rightIndex++;
        }
    }
    }
    
   

    cout<<arr[left]<<' '<<arr[right]<<endl;


}