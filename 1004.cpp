#include<iostream>
#include<cstring>
#include<vector>
using namespace std;

vector <int> mp[105];
int lv[105];
int cnt[105];
int maxx=0;

void dfs(int n,int c){
    lv[n]=c;
    if (c>maxx) maxx=c;
    for (int i=0;i<mp[n].size();i++)
        dfs(mp[n][i],c+1);
}

int main(){
    int n,m,t,tt;
    cin>>n>>m;
    for(int i=0;i<m;i++){
        cin>>t;
        int k;
        cin>>k;
        for (int j=0;j<k;j++){
            cin>>tt;
            mp[t].push_back(tt);
        }
    }
    dfs(1,0);
    memset(cnt,0,sizeof(cnt));
    for (int i=1;i<=n;i++)
        if (mp[i].size()==0)
            cnt[lv[i]]++;
    cout<<cnt[0];
    for (int i=1;i<=maxx;i++)
        cout<<" "<<cnt[i];
    cout<<endl;
    return 0;
}
