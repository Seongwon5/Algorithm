#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int L;
int C;
char* arr;
bool* isVowel;//정렬된 배열 안의 원소가 모음인지?
bool* picked;
void makeSequence(int last, int topick){//i번 이후의 수들로 만들 수 있는 모든 경우의수
    if(topick==0){
        int vowel=0;
        int consonant=0;
        for(int i=0;i<C;i++){
            if(picked[i]){
                if(isVowel[i]){
                    vowel++;
                }
                else{
                    consonant++;
                }
            }
        }
        if(vowel>=1&&consonant>=2){
            for(int i=0;i<C;i++){
                if(picked[i]){
                    cout<<arr[i];
                }
            }
            cout<<endl;
            return;
        }
        else{
            return;
        }
    }
    else{
        for(int i=last+1;i<=C-topick;i++){
            picked[i]=true;
            makeSequence(i,topick-1);
            picked[i]=false;
        }
    }
}
int main(){
    cin>>L>>C;

    arr=new char[C];
    isVowel=new bool[C];
    picked=new bool[C];
    for(int i=0;i<C;i++){
        cin>>arr[i];
        picked[i]=false;
    }

    sort(arr,arr+C);

    for(int i=0;i<C;i++){
        if(arr[i]=='a'||arr[i]=='e'||arr[i]=='i'||arr[i]=='o'||arr[i]=='u'){
            isVowel[i]=true;
        }
        else{
            isVowel[i]=false;
        }
    }

    makeSequence(-1,L);

    
}