#include<iostream>
using namespace std;

int main(){
    int n,b;
    int s[40];
    while (cin>>n>>b){
        if (n==0) {cout<<"Yes\n0\n";continue;}
        int ss=0;
        while (n){
            s[ss++]=n%b;
            n/=b;
        }
        bool flag=true;
        for (int i=0;i<ss/2;i++){
            if (s[i]!=s[ss-i-1]) {flag=false;break;}
        }
        if (flag) cout<<"Yes\n";else cout<<"No\n";
        for (int i=0;i<ss-1;i++)
            cout<<s[ss-i-1]<<" ";
        cout<<s[0]<<endl;
    }
    return 0;
}
