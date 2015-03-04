#include<iostream>
#include<string>
using namespace std;

long long getdigit(char a){
    if (a>='a'&&a<='z') return a-'a'+10;
    return a-'0';
}
long long pow(long long a,long long b)
{
    long long r=1,base=a;
    while(b!=0)
    {
        if(b&1)
            r*=base;
        base*=base;
        b>>=1;
    }
    return r;
}

long long num2dec(string num,long long radix){
    long long ans=0;
    for (long long i=num.length()-1;i>=0;i--){
        ans+=getdigit(num[i])*pow(radix,num.length()-i-1);
    }
    return ans;
}

int main(){
    string a,b,t;
    long long tag,radix;
    long long tmp=0;
    while (cin>>a>>b>>tag>>radix){
        if (a==b&&a=="1") cout<<2<<endl;
        else if (a==b) cout<<radix<<endl;
        else{
            if (tag==2) {t=a;a=b;b=t;}
            tmp=num2dec(a,radix);
            int n=0;
            for (int i=0;i<b.length();i++)
                if (n<getdigit(b[i])) n=getdigit(b[i]);
            n++;
            bool flag=false;
            long long i;
            for (i=n;num2dec(b,i)<=tmp&&i<=1000;i++){
                if (tmp==num2dec(b,i)){
                    cout<<i;flag=true;break;
                }
            }
            if (i>1000){
                long long p=2,q=tmp,mid;
                while (p<=q){
                    mid=(p+q)>>1;
                    if (tmp==num2dec(b,mid)){
                        cout<<mid;flag=true;break;
                    }
                    else if (tmp>num2dec(b,mid))
                        p=mid+1;
                    else if (tmp<num2dec(b,mid))
                        q=mid-1;
                }
            }

            if (!flag) cout<<"Impossible";
            cout<<endl;
        }
    }
    return 0;
}
