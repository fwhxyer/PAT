#include<iostream>
#include<string>
using namespace std;

string tohex="0123456789ABC";

int main(){
    int a,b,c;
    while (cin>>a){
        cout<<"#";
        if (a>13){
            b=a/13;
            a=a%13;
        }else
            b=0;
        cout<<tohex[b]<<tohex[a];
        cin>>a;
        if (a>13){
            b=a/13;
            a=a%13;
        }else
            b=0;
        cout<<tohex[b]<<tohex[a];
        cin>>a;
        if (a>13){
            b=a/13;
            a=a%13;
        }else
            b=0;
        cout<<tohex[b]<<tohex[a]<<endl;
    }
    return 0;
}
