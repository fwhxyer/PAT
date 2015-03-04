#include<iostream>
using namespace std;

int a[1001],b[1001],c[1001],r[1001];
int main(){
    int n,m,nn;
    fill(r,r+1001,0);
    cin>>n>>m;nn=n;
    for (int i=0;i<n;i++)
        cin>>a[i];
    for (int i=0;i<n;i++){
        cin>>c[i];
        b[i]=a[c[i]];
    }
    cout<<endl;
    for (int i=0;i<nn-1;i++)
        cout<<a[i]<<" ";
    cout<<a[nn-1]<<endl;
    for (int i=0;i<nn-1;i++)
        cout<<b[i]<<" ";
    cout<<b[nn-1]<<endl;
    for (int i=0;i<nn-1;i++)
        cout<<c[i]<<" ";
    cout<<c[nn-1]<<endl;
    cout<<endl;
    while (n>0){
        int ra=(n-1)/m+1+1;
        int maxt=-1,maxp=0;
        for (int i=n-1;i>=0;i--){
            if (b[i]>maxt) {maxt=b[i];maxp=i;}
            if (i%m==0){
                r[c[maxp]]=ra;
                d[ra-1]=b[maxp];
                n=ra-1;
                maxt=-1;maxp=0;
            }
        }
        cout<<endl<<ra<<endl;
        for (int i=0;i<n-1;i++)
            cout<<b[i]<<" ";
        cout<<b[n-1]<<endl;
        for (int i=0;i<nn-1;i++)
            cout<<r[i]<<" ";
        cout<<r[nn-1]<<endl;
        cout<<endl;
    }
    for (int i=0;i<nn-1;i++)
        cout<<r[i]<<" ";
    cout<<r[nn-1]<<endl;
}
