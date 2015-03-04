#include<iostream>
#include<string>
using namespace std;
string week[7]={"MON","TUE","WED","THU","FRI","SAT","SUN"};

int main(){
    string s1,s2,s3,s4;
    while(cin>>s1>>s2>>s3>>s4){
        while(s1.length()<s2.length()) s1+=".";
        while(s1.length()>s2.length()) s2+=".";
        int tmplength=s1.length();
        s1+=s3;
        s2+=s4;
        if (s1.length()>s2.length()) s1=s1.substr(0,s2.length());
        if (s1.length()<s2.length()) s2=s2.substr(0,s1.length());
        int t=0;
        for (int i=0;i<s1.length();i++)
        {
            if (s1[i]==s2[i]){
                if (t==0){
                    if (s1[i]>='A'&&s1[i]<='G'){
                        cout<<week[s1[i]-'A']<<" ";
                        t++;
                    }
                }else if (t==1){
                    if (s1[i]>='A'&&s1[i]<='N'){
                        cout<<s1[i]-'A'+10<<":";
                        t++;
                    }else
                    if (s1[i]>='0'&&s1[i]<='9'){
                        cout<<"0"<<s1[i]<<":";
                        t++;
                    }
                }else if (t==2){
                    if (s1[i]>='a'&&s1[i]<='z'||s1[i]>='A'&&s1[i]<='Z'){
                        if (i-tmplength<10)
                            cout<<"0";
                        cout<<i-tmplength;
                        t++;
                    }
                }else if (t>=3){
                    cout<<endl;
                    break;
                }
            }
        }
    }
    return 0;
}
