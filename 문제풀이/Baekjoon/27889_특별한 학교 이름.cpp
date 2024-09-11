#include<iostream>
#include<string>

using namespace std;
int main(){
    string input;
    cin>>input;

    if(input=="NLCS"){
        cout<<"North London Collegiate School"<<endl;
    }
    else if(input=="BHA"){
        cout<<"Branksome Hall Asia"<<endl;
    }
    else if(input=="KIS"){
        cout<<"Korea International School"<<endl;
    }
    else if(input=="SJA"){
        cout<<"St. Johnsbury Academy"<<endl;
    }
    else{
        cout<<"no"<<endl;
    }
}