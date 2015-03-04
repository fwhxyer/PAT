#include<iostream>
using namespace std;

long long gcd(long long a,long long b){while(b^=a^=b^=a%=b);return a;}
long long lcm(long long a,long long b){return a/gcd(a,b)*b;}

void myprint(long long a,long long b){
    //cout<<"testmyprint a:"<<a<<" b:"<<b<<endl;
    if (b==0) {cout<<"Inf";return;}
    if (a==0) {cout<<"0";return;}
    long long t,p1=0;
    t=gcd(a,b);
    a/=t;b/=t;
    if (b<0) {a=-a;b=-b;}
    if (a/b) {p1=a/b;a=a%b;}
    if (p1&&a==0)
        cout<<p1;
    else if (p1<0&&a!=0)
        cout<<p1<<" "<<a<<"/"<<b;
    else if (p1&&a!=0)
        cout<<p1<<" "<<a<<"/"<<b;
    else
        cout<<a<<"/"<<b;
}

int main(){
    int n;char tt;long long a,b,t,c,d;
    while(cin>>n) {
        a=0;b=1;
        for (int i=0;i<n;i++){
            cin>>c>>tt>>d;
            t=lcm(b,d);
            a*=t/b;c*=t/d;b=d=t;
            a=a+c;b=t;
            t=gcd(a,b);
            a/=t;b/=t;
        }
        myprint(a,b);
        cout<<endl;
    }
    return 0;
}
