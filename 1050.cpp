#include<iostream>
#include<string>
#include<cstring>
using namespace std;

bool check[512];

int main(){
    string s,s1;
    while (getline(cin,s)){
        memset(check,0,sizeof(check));
        getline(cin,s1);
        for (int i=0;i<s1.length();i++)
            check[s1[i]]=1;
        s1="";
        for (int i=0;i<s.length();i++)
            if (!check[s[i]]) s1+=s[i];
        cout<<s1<<endl;
    }
    return 0;
}
