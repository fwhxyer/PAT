#include<iostream>
#include<cstdio>
using namespace std;

int pre[100010];
double pr[100010]={0};
int n,ansn;
double p,perc,ans=-1;

double get(int a){
    if (pre[a]==-1) return pr[a];
    if (pr[a]) return pr[a];
    return pr[a]=get(pre[a])*(1+perc/100.0);
}

int main(){
    cin>>n>>p>>perc;
    for (int i=0;i<n;i++){
        cin>>pre[i];
        if (pre[i]==-1) pr[i]=p;
    }
    for (int i=0;i<n;i++){
        double t=get(i);
        if (t>ans) {ans=t;ansn=1;}
        else if (t==ans) ansn++;
    }
    printf("%0.2lf %d\n",ans,ansn);
    return 0;
}
