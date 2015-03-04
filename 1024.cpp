#include<iostream>
#include<cstring>
#include<string>
using namespace std;

int main(){
    string s;
    int s1[100];
    int s2[100];
    int s3[100];
    memset(s1,0,sizeof(s1));
    memset(s2,0,sizeof(s2));
    memset(s3,0,sizeof(s3));
    int k,kk=0,n;
    cin>>s>>k;

    bool flag=true;
    for (int i=0;i<s.length()/2;i++)
        if (s[i]!=s[s.length()-i-1]) {flag=false;break;}
    if (!flag) {
        n=s.length();
        for (int i=0;i<n;i++){
            s1[i]=s[i]-'0';
            s2[i]=s[s.length()-i-1]-'0';
        }
        bool flag1=false;
        while (k--){
            kk++;
            int tmp=0;
            for (int i=0;i<n;i++){
                s3[i]=s1[i]+s2[i];
            }
            for (int i=0;i<n;i++){
                s3[i+1]+=s3[i]/10;
                s3[i]%=10;
            }
            if (s3[n]) n++;
            for (int i=0;i<n;i++){
                s1[i]=s3[i];
                s2[i]=s3[n-i-1];
            }
            /*
                for (int i=0;i<n;i++) cout<<s1[i];
                cout<<endl<<kk<<endl;
                for (int i=0;i<n;i++) cout<<s2[i];
                cout<<endl<<kk<<endl;
            */
            bool flag=true;
            for (int i=0;i<n/2;i++)
                if (s3[i]!=s3[n-i-1]) {flag=false;break;}
            if (flag){
                for (int i=0;i<n;i++) cout<<s3[i];
                cout<<endl<<kk<<endl;
                flag1=true;
                break;
            }
        }
        if (!flag1) {
            for (int i=n-1;i>=0;i--) cout<<s3[i];
            cout<<endl<<kk<<endl;
        }
    } else  {
        cout<<s<<endl<<0<<endl;
    }
    return 0;
}
