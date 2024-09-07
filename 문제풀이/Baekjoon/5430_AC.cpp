#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

int main(){
    //대괄호 안에 쉼표로 구분되어 주어진 수열을 어떻게 수의 배열로 분리하지?
    int T;
    cin>>T;

    for(int i=0;i<T;i++){
        string com;
        cin>>com;//명령어를 입력받는다
        int num;
        cin>>num;//원소의 개수를 입력받는다.
        int* arr= new int[num];//num개의 수를 저장할 배열
        string strArr;
        cin>>strArr;//[a,b,c,...]형태로 된 수열을 입력받는다.

        //strArr을 arr에 옮겨 담는 과정
        string buffer;
        int curIndex=0;
        for(int i=0;i<strArr.size();i++){
            if(i==0) continue;//괄호 제거
            if(strArr[i]==','||strArr[i]==']'){//쉼표 등장 시 현재까지 완성된 수를 배열에 추가
                //buffer에 완성된 수가 들어있음.
                int x=0;//배열에 들어갈 정수 원소
                int power=0;
                while(!buffer.empty()){
                    int c=buffer.back()-'0';
                    x+=c*pow(10,power);
                    power++;
                    buffer.pop_back();
                }
                arr[curIndex]=x;
                curIndex++;
            }
            else{
                buffer.push_back(strArr[i]);
            }
        }
        //arr에 있는 수들에 포인터를 이용해서 연산을 적용하는 과정
        bool reverse=false;
        int* start=arr;//첫 번째 원소를 가리키는 포인터
        int* end=arr+num-1;//마지막 원소를 가리키는 포인터
        int count=num;//남아있는 원소의 개수
        bool error=false;
        for(int i=0;i<com.size();i++){
            if(com[i]=='R'){//뒤집기
                int*temp=start;
                start=end;
                end=temp;
                reverse= !reverse;//반전 여부를 뒤집음
            }
            else if(com[i]=='D'){
                if(count==0){//남은 개수가 0개인데 제거하려고 함.
                    error=true;
                    break;
                }
                else{
                    if(reverse){//start가 뒤에 있음
                        --start;
                        count--;
                    }
                    else{//start가 앞에 있음
                        ++start;
                        count--;
                    }
                }
            }
        }
        //연산이 완료된 arr을 출력하는 과정

        if(error){
            cout<<"error"<<endl;
        }
        else{//오류 없음
            if(reverse){//start가 더 뒤에 있는 경우
                cout<<"[";
                for(int*i=start;i>=end;i--){
                    if(i==end){
                        cout<<*i;
                    }
                    else{
                        cout<<*i<<',';
                    }
                }
                cout<<"]";
                cout<<endl;
            }
            else{//start가 더 앞에 있는 경우
                cout<<"[";
                for(int*i=start;i<=end;i++){
                    if(i==end){
                        cout<<*i;
                    }
                    else{
                        cout<<*i<<',';
                    }
                }
                cout<<"]";
                cout<<endl;
            }
        }
    }
}