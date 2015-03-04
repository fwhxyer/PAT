#include<iostream>
#include<cstdio>
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
    bool flag=0;
    if (a<0) flag=1;
    if (flag) cout<<"(";
    if (a/b) {p1=a/b;a=a%b;}
    if (p1&&a==0)
        cout<<p1;
    else if (p1<0&&a!=0)
        cout<<p1<<" "<<-a<<"/"<<b;
    else if (p1&&a!=0)
        cout<<p1<<" "<<a<<"/"<<b;
    else
        cout<<a<<"/"<<b;
    if (flag) cout<<")";
}

int main(){
    long long a,b,c,d,e,f,t,aa,bb,cc,dd;
    char tt;
    while(cin>>aa>>tt>>bb>>cc>>tt>>dd){

        a=aa;b=bb;c=cc;d=dd;
        t=lcm(b,d);
        a*=t/b;c*=t/d;b=d=t;
        e=a+c;f=t;
        t=gcd(e,f);
        e/=t;f/=t;
        myprint(a,b);
        cout<<" + ";
        myprint(c,d);
        cout<<" = ";
        myprint(e,f);
        cout<<endl;

        a=aa;b=bb;c=cc;d=dd;
        t=lcm(b,d);
        a*=t/b;c*=t/d;b=d=t;
        e=a-c;f=t;
        t=gcd(e,f);
        e/=t;f/=t;
        myprint(a,b);
        cout<<" - ";
        myprint(c,d);
        cout<<" = ";
        myprint(e,f);
        cout<<endl;

        a=aa;b=bb;c=cc;d=dd;
        myprint(a,b);
        cout<<" * ";
        myprint(c,d);
        cout<<" = ";
        if (a==0||c==0){
            e=0;f=1;
        }else {
            t=gcd(a,b);
            a/=t;b/=t;
            t=gcd(a,d);
            a/=t;d/=t;
            t=gcd(c,b);
            c/=t;b/=t;
            t=gcd(c,d);
            c/=t;d/=t;
            e=a*c;f=b*d;
            t=gcd(e,f);
            e/=t;f/=t;
        }
        myprint(e,f);
        cout<<endl;

        a=aa;b=bb;c=cc;d=dd;
        myprint(a,b);
        cout<<" / ";
        myprint(c,d);
        cout<<" = ";
        c=dd;d=cc;
        if (a==0){
            e=0;f=1;
        }else if (d==0){
            e=0;f=0;
        }else {
            t=gcd(a,b);
            a/=t;b/=t;
            t=gcd(a,d);
            a/=t;d/=t;
            t=gcd(c,b);
            c/=t;b/=t;
            t=gcd(c,d);
            c/=t;d/=t;
            e=a*c;f=b*d;
            t=gcd(e,f);
            e/=t;f/=t;
        }
        myprint(e,f);
        cout<<endl;
    }
}
