#include<iostream>
using namespace std;

int pre[100010];
int cnt[100010]={0};
int ansp;

void dfs(int t,int s){
    ansp++;
    cnt[s]=t;
    if (!cnt[pre[s]])
        dfs(t,pre[s]);
}

int main(){
    int n;
    cin>>n;
    for (int i=0;i<n;i++)
        cin>>pre[i];
    int t=1,ans=0;
    for (int i=0;i<n;i++)
        if (!cnt[i])
            if (pre[i]!=i){
                ansp=0;
                dfs(t++,i);
                ans+=ansp+1;
            }
    if (pre[0]!=0) ans-=2;
    cout<<ans<<endl;
    return 0;
}
