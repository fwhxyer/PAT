#include<iostream>
#include<string>
using namespace std;

string ch[]={"ling","yi","er","san","si","wu","liu","qi","ba","jiu","shi"};
string ans="";

string printmy(int a,bool t){
    string res;
    if (a>=1000) {res+=" "+ch[a/1000]+" Qian";t=1;} else if (t&&a>=100) res+=" ling";
    a%=1000;
    if (a>=100) {res+=" "+ch[a/100]+" Bai";t=1;} else if (t&&a>=10) res+=" ling";
    a%=100;
    if (a>=10) res+=" "+ch[a/10]+" Shi"; else if (t&&a) res+=" ling";
    a%=10;
    if (a)
        res+=" "+ch[a];
    return res;
}

int main(){
    int n,t;
    cin>>n;
    if (n<0) {ans+=" Fu";n=-n;}
    else if (!n) {cout<<"ling"<<endl;return 0;}
    bool isYi=0,isWan=0;
    if (n>=100000000) {
        ans=ans+" "+ch[n/100000000]+" Yi";
        isYi=1;
        n%=100000000;
    }
    if (n>=10000) {
        t=n/10000;
        n%=10000;
        isWan=1;
        ans+=printmy(t,isYi);
        ans+=" Wan";
    } else if (isYi&&n) {
        ans+=" ling";
    }
    ans+=printmy(n,isWan);
    cout<<ans.substr(1,ans.size()-1)<<endl;
    return 0;
}
