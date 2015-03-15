#include<iostream>
#include<cstdio>
using namespace std;

int pre[100010]={0};
double pr[100010]={0};
int cnt[100010]={0};
double perc,ans=0;

double getpr(int i){
    if (pr[i]) return pr[i];
    return pr[i]=getpr(pre[i])/100.0*(100+perc);
}

int main(){
    int n;
    cin>>n>>pr[0]>>perc;
    pre[0]=0;
    for (int i=0;i<n;i++)
    {
        int k,t;
        cin>>k;
        for (int j=0;j<k;j++){
            cin>>t;
            pre[t]=i;
        }
        if (!k){
            cin>>t;
            cnt[i]=t;
        }
    }
    /*
    for (int i=0;i<n;i++)
        cout<<pre[i]<<" ";
    cout<<endl;
    for (int i=0;i<n;i++)
        cout<<cnt[i]<<" ";
    cout<<endl;
    for (int i=0;i<n;i++)
        cout<<pr[i]<<" ";
    cout<<endl;
    */
    for (int i=0;i<n;i++){
        if (!cnt[i])
            getpr(i);
        else
            ans+=cnt[i]*getpr(i);
        //for (int i=0;i<n;i++)
        //    cout<<pr[i]<<" ";
        //cout<<endl;
    }
    printf("%0.1lf\n",ans);
    return 0;
}
