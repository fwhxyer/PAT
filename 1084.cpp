#include<iostream>
#include<cstring>
#include<string>
using namespace std;

bool check[513];

int main(){
    string s1,s2;
    while (cin>>s1>>s2){
        memset(check,0,sizeof(check));
        for (int i=0;i<s1.length();i++)
            if (s1[i]>='a'&&s1[i]<='z') s1[i]=s1[i]+'A'-'a';
        for (int i=0;i<s2.length();i++)
            if (s2[i]>='a'&&s2[i]<='z') s2[i]=s2[i]+'A'-'a';
        for (int i=0;i<s1.length();i++)
            if (s1[i]!=s2[i]){
                if (!check[s1[i]]){
                    check[s1[i]]=true;
                    s2=s2.substr(0,i)+"a"+s2.substr(i,s2.length()-i);
                }else
                    s2=s2.substr(0,i)+"b"+s2.substr(i,s2.length()-i);
            }
        //cout<<s1<<endl<<s2<<endl;
        for (int i=0;i<s1.length();i++)
            if (s2[i]=='a') cout<<s1[i];
        cout<<endl;
    }
    return 0;
}
