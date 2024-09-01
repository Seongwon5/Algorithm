#include<iostream>
#include<vector>
using namespace std;
typedef pair<int,int> rectangle;
vector<pair<int,int>> rectSizeInfo[45001];
int main(){
    for(int i=1;i<=150;i++){
        for(int j=i+1;j<=150;j++){
            int diagSq=i*i+j*j;
            rectangle rect;
            rect.first=i;//세로
            rect.second=j;//가로
            rectSizeInfo[diagSq].push_back(rect);
        }
    }

    int h,w;
    cin>>h>>w;
    while(h!=0||w!=0){
        
        int diagSq=h*h+w*w;    
        rectangle answer;
        bool found=false;
        int index=diagSq;

        int minH=987654321;
        int minIndex=0;
        for(int i=0;i<rectSizeInfo[index].size();i++){//대각선이 같은 경우
            if(rectSizeInfo[index][i].first>h){//조건을 만족하는경우
                found=true;
                if(minH>rectSizeInfo[index][i].first){
                    minH=rectSizeInfo[index][i].first;
                    minIndex=i;
                }
            }
        }
        if(found){//같은 대각선 길이에서 답을 찾은 경우
            cout<<rectSizeInfo[index][minIndex].first<<' '<<rectSizeInfo[index][minIndex].second<<endl;
        }
        while(!found){//아직 못찾은 경우
            minH=98765432;
            index++;
            for(int i=0;i<rectSizeInfo[index].size();i++){              
                found=true;
                if(minH>rectSizeInfo[index][i].first){
                    minH=rectSizeInfo[index][i].first;
                    minIndex=i;
                }
            }
            if(found){
                cout<<rectSizeInfo[index][minIndex].first<<' '<<rectSizeInfo[index][minIndex].second<<endl;
            }
        }
        
        cin>>h>>w;
    }
}