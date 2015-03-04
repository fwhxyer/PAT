#include<iostream>
using namespace std;

int main(){
    long long a,b,c,t;
    int T,TT=0;
    cin>>T;
    while(T--){
        cin>>a>>b>>c;
        cout<<"Case #"<<++TT<<": ";

        t=a+b;
        if (a>0&&b>0&&t<0)
            cout<<"true";
        else if (a<0&&b<0&&t>0)
            cout<<"false";
        else
            if (a+b>c) cout<<"true";
        else
            cout<<"false";

        cout<<endl;
    }
}
