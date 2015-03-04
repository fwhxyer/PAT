#include<iostream>
using namespace std;

int main(){
    int a,b,c,d,e,f,g,h,i;
    char t;
    while(cin>>a){
        cin>>t>>b>>t>>c;
        cin>>d>>t>>e>>t>>f;
        i=c+f;
        h=b+e+i/29;
        i%=29;
        g=a+d+h/17;
        h%=17;
        cout<<g<<"."<<h<<"."<<i<<endl;
    }
    return 0;
}
