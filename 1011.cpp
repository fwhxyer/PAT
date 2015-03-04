#include<cstdio>
#include<iostream>
using namespace std;

int main(){
    double a,b,c,p;
    char flag;
    while (cin>>a>>b>>c){
        flag='W';
        if (a<b) {a=b;flag='T';}
        if (a<c) {a=c;flag='L';}
        p=a;
        cout<<flag<<" ";
        cin>>a>>b>>c;
        flag='W';
        if (a<b) {a=b;flag='T';}
        if (a<c) {a=c;flag='L';}
        p=a*p;
        cout<<flag<<" ";
        cin>>a>>b>>c;
        flag='W';
        if (a<b) {a=b;flag='T';}
        if (a<c) {a=c;flag='L';}
        p=a*p*0.65;
        p--;
        cout<<flag<<" ";
        printf("%0.2lf\n",p*2);
    }

}
