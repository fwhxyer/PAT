#include<iostream>
#include<sstream>
#include<string>

using namespace std;

int main(){
    int a,b;
    cin>>a>>b;
    string s;
    a=a+b;
    stringstream ss;
    ss<<a;
    ss>>s;
    if (a>=0)
    for (int i=s.length()-3;i>0;i-=3)
    {
        s=s.substr(0,i)+","+s.substr(i,s.length()-i);
    }
    else
    for (int i=s.length()-3;i>1;i-=3)
    {
        s=s.substr(0,i)+","+s.substr(i,s.length()-i);
    }
    cout<<s<<endl;
}
