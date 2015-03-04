#include<iostream>
using namespace std;

int times(int b,int a){//return b^a;
    int ans=1;
    for (int i=0;i<a;i++)
        ans*=b;
    return ans;
}
const int maxp=100000;
bool notpri[maxp+10]={0};

int main(){
    notpri[0]=notpri[1]=1;
    int p=2,q;
    for (int i=2;i<317;i++)
        if (!notpri[i])
        for (int j=2;j<maxp/i;j++)
        {
            notpri[i*j]=1;
        }
        /*
    for (int i=0;i<100;i++)
        if (!notpri[i]) cout<<i<<"\t";
    cout<<endl;
    */
    //get_prime-----------------
    int n=0,n2=0,d;
    int s[20];
    while (cin>>n){
        if (n<0) break;
        cin>>d;
        if (notpri[n]) {
            cout<<"No"<<endl;
            continue;
        }
        int m=0;
        while (n){
            s[m++]=n%d;
            n/=d;
        }
        n2=0;
        for (int i=0;i<m;i++)
            n2+=times(d,m-i-1)*s[i];
        //cout<<n2<<" ";
        if (notpri[n2]) cout<<"No"<<endl;
        else cout<<"Yes"<<endl;
    }
    return 0;
}
