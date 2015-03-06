#include<algorithm>
#include<iostream>
#include<vector>
#include<cstdio>
#define maxn 10010
using namespace std;

vector<int> v[maxn];
int ans[maxn],ans1[maxn];
bool check[maxn];
bool checkdeep[maxn];
int tmpans=0,tmppos=0,ansn=0,ansn1=0;

void dfs(int st,int deep){
    check[st]=1;
    if (deep>tmpans) {tmpans=deep;tmppos=st;ansn1=1;ans1[ansn1-1]=st;}
    else if (deep==tmpans) {ansn1++;ans1[ansn1-1]=st;}
    for (int i=0;i<v[st].size();i++)
    if (!checkdeep[v[st][i]]){
        checkdeep[v[st][i]]=1;
        dfs(v[st][i],deep+1);
        checkdeep[v[st][i]]=0;
    }
}
void dfs1(int st,int deep){
    if (deep>tmpans) {tmpans=deep;ansn=1;ans[ansn-1]=st;}
    else if (deep==tmpans) {ansn++;ans[ansn-1]=st;}
    for (int i=0;i<v[st].size();i++)
    if (!checkdeep[v[st][i]]){
        checkdeep[v[st][i]]=1;
        dfs1(v[st][i],deep+1);
        checkdeep[v[st][i]]=0;
    }
}

int main(){
    int n,a,b;
    scanf("%d",&n);
    fill(check+1,check+n,0);
    fill(checkdeep+1,checkdeep+n,0);
    for (int i=0;i<n-1;++i){
        scanf("%d %d",&a,&b);
        v[a].push_back(b);
        v[b].push_back(a);
    }
    int t=0;
    for (int i=1;i<=n;i++){
        if (!check[i]) {
            checkdeep[i]=1;
            tmpans=tmppos=ansn1=0;
            dfs(i,1);
            checkdeep[i]=0;
            tmpans=0;
            if (!t) {
                checkdeep[tmppos]=1;
                dfs1(tmppos,1);
                checkdeep[tmppos]=0;
            }
            t++;
        }
    }
    if (t>1)
        printf("Error: %d components\n",t);
    else{
        for (int i=0;i<ansn1;i++){
            ans[ansn+i]=ans1[i];
        }
        ansn+=ansn1;
        sort(ans,ans+ansn);
        for (int i=0;i<ansn;i++)
            printf("%d\n",ans[i]);
    }
    return 0;
}
