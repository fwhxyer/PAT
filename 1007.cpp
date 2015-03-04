#include<iostream>

using namespace std;

int a[10010],b[10010],c[10010],d[10010];
int main(){
    int n,ans=0,aa,bb;
    cin>>n;
    for (int i=0;i<n;i++)
        cin>>a[i];
    d[0]=b[0]=c[0]=a[0];
    for (int i=1;i<n;i++)
        if (a[i]>b[i-1]+a[i])
            c[i]=d[i]=b[i]=a[i];
        else{
            b[i]=b[i-1]+a[i];
            c[i]=c[i-1];
            d[i]=a[i];
        }
    ans=-1;aa=a[0];bb=a[n-1];
    for (int i=0;i<n;i++)
        if (b[i]>ans){
            ans=b[i];aa=c[i];bb=d[i];
        }
    if (ans==-1) ans=0;
    cout<<ans<<" "<<aa<<" "<<bb<<endl;
    return 0;
}
