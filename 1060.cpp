#include<iostream>
#include<string>

using namespace std;

int main()
{
    int n,tp=0,s1r=0,s2r=0;
    string s1,s2;
    cin>>n>>s1>>s2;
    while (s1.length()&&(s1[0]=='0'||s1[0]=='.')){
        //s1=s1.substr(0,tp)+s1.substr(tp+1,s1.length()-1-tp);
        s1=s1.substr(1,s1.length()-1);
        if (tp) s1r--;
        if(s1[0]=='.')
            tp++;
    }
    tp=0;
    while (s2.length()&&(s2[0]=='0'||s2[0]=='.')){
        //s2=s2.substr(0,tp)+s2.substr(tp+1,s2.length()-1-tp);
        s2=s2.substr(1,s2.length()-1);
        if (tp) s2r--;
        if(s2[0]=='.')
            tp++;
    }
    if (s1=="") s1r=0;
    if (s2=="") s2r=0;
    s1r++;s2r++;
    //cout<<s1<<" "<<s2<<endl<<s1r<<" "<<s2r<<endl;
    if (s1r==1){
        for (s1r=0;s1r<s1.length();s1r++)
            if (s1[s1r]=='.') break;
        if (s1r!=s1.length()) s1=s1.substr(0,s1r)+s1.substr(s1r+1,s1.length()-1);
    }
    if (s2r==1){
        for (s2r=0;s2r<s2.length();s2r++)
            if (s2[s2r]=='.') break;
        if (s2r!=s2.length()) s2=s2.substr(0,s2r)+s2.substr(s2r+1,s2.length()-1);
    }
    bool t=true;
    if (s1r!=s2r){
        t=false;
    } else {
        while (s1.length()<n) s1+='0';
        while (s2.length()<n) s2+='0';
        for (int i=0;i<n;i++){
            if (s1[i]!=s2[i]) {
                t=false;
                break;
            }
        }
    }
    if (t) {
        cout<<"YES ";
        /*
        tp=1;
        for (int i=0;i<s1.length();i++) if (s1[i]!='0') tp=0;
        while(s1.length()<n) s1+='0';
        if (tp) s1=s1.substr(0,s1.length()-1);
            */
            cout<<"0.";
            s1=s1.substr(0,n);
            cout<<s1;
            cout<<"*10^"<<s1r;
            cout<<endl;
        /*}else
            cout<<"0"<<endl;*/
    }else {
        cout<<"NO ";
        /*
        tp=1;
        for (int i=0;i<s1.length();i++) if (s1[i]!='0') tp=0;
        while(s1.length()<n) s1+='0';
        if (tp) s1=s1.substr(0,s1.length()-1);
            */
            cout<<"0.";
            s1=s1.substr(0,n);
            cout<<s1;
            cout<<"*10^"<<s1r;
            cout<<" ";
        /*}else
            cout<<"0 ";*/
        tp=0;
        /*
        if (s2=="") tp=1;
        while(s2.length()<n) s2+='0';
        if (tp) s2=s2.substr(0,s2.length()-1);*/
            cout<<"0.";
            s2=s2.substr(0,n);
            cout<<s2;
            cout<<"*10^"<<s2r;
            cout<<endl;
        /*}else
            cout<<"0"<<endl;*/
    }
    return 0;
}
