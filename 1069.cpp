#include<iostream>
#include<algorithm>
#include<sstream>
#include<string>
using namespace std;

void ssort(string &s){
    char a[5];
    for (int i=0;i<4;i++)
        a[i]=s[i];
    sort(a,a+4);
    for (int i=0;i<4;i++)
        s[i]=a[i];
}
int main(){
    string s;
    while(cin>>s){
        do{
            while (s.length()<4) s="0"+s;
            string s1=s,s2;
            ssort(s);
            int a,b;
            for (int i=0;i<s.length();i++)
                s1[i]=s[s.length()-i-1];
            stringstream ss1,ss2,ss3;
            ss1<<s1;
            ss1>>a;
            ss2<<s;
            ss2>>b;
            ss3<<a-b;
            ss3>>s2;
            while (s2.length()<4) s2="0"+s2;
            cout<<s1<<" - "<<s<<" = "<<s2<<endl;
            s=s2;
        }while (s!="6174"&&s!="0000");
    }
    return 0;
}
