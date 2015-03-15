#include<algorithm>
#include<iostream>
#include<cstdio>
using namespace std;

long long a[100010];

int main(){
    int n,p,ans=-1;
    scanf("%d %d",&n,&p);
    for (int i=0;i<n;i++)
        scanf("%d",&a[i]);
    sort(a,a+n);
    for (int i=0;i<n;i++){
        long long t=a[i]*p;
        int anst=upper_bound(a,a+n,t)-a;
        //cout<<anst<<" "<<i<<endl;
        if (ans<anst-i) ans=anst-i;
    }
    printf("%d\n",ans);
    return 0;
}
