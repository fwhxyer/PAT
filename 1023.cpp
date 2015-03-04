#include<iostream>
#include<string>
#include<cstring>
using namespace std;

int main(){
    string s;
    int num[10],s1[25];
    while(cin>>s){
        memset(num,0,sizeof(num));
        memset(s1,0,sizeof(s1));
        for (int i=0;i<s.length();i++){
            num[s[i]-'0']++;
            s1[i]=s[s.length()-1-i]-'0';
        }
       /* for (int i=0;i<s.length();i++){
            cout<<s1[i];
        } cout<<endl;*/
        int tmp=0;
        for (int i=0;i<s.length();i++){
            int a=s1[i]*2+tmp;
            s1[i]=a%10;
            tmp=a/10;
        }
        if (tmp) s1[s.length()]=tmp;
       /* for (int i=0;i<=s.length();i++){
            cout<<s1[i];
        } cout<<endl;*/
        if (s1[s.length()]) {
            cout<<"No\n";
            for (int i=0;i<=s.length();i++)
                cout<<s1[s.length()-i];
            cout<<endl;
        }else{
            for (int i=0;i<s.length();i++)
                num[s1[i]]--;
            bool flag=false;
            for (int i=0;i<10;i++)
                if (num[i]){
                    flag=true;break;
                }
            if (flag) cout<<"No\n";else cout<<"Yes\n";
            for (int i=0;i<s.length();i++)
                cout<<s1[s.length()-i-1];
            cout<<endl;
        }
    }
    return 0;
}
