#include<iostream>
#define maxn 2020
using namespace std;

int fa[maxn],fi[maxn*maxn],la[maxn*maxn];
bool cnt[maxn];
int find_f(int b){
    int a=b;
    while (fa[a]!=a) a=fa[a];
    fa[b]=a;
    return a;
}
void union_f(int a,int b){
    fa[find_f(b)]=find_f(a);
}

int main(){
    int n,m,k;
    cin>>n>>m>>k;
    for (int i=0;i<n;i++) fa[i]=i;
    for (int i=0;i<m;i++){
        cin>>fi[i]>>la[i];
        //fi[i]--;la[i]--;
    }
    for (int i=0;i<k;i++){
        for (int i=0;i<=n;i++) fa[i]=i;
        for (int i=0;i<maxn;i++) cnt[i]=0;
        int t;
        cin>>t;
        //t--;
        for (int i=0;i<m;i++)
        {
            if (fi[i]!=t&&la[i]!=t)
                union_f(fi[i],la[i]);
        }
        for (int i=1;i<=n;i++)
            cnt[find_f(i)]=1;
        int ans=0;
        for (int i=1;i<maxn;i++)
            if (i!=t&&cnt[i]) ans++;
        cout<<ans-1<<endl;
        /*for (int i=0;i<n;i++)
            cout<<" "<<fa[i];
        cout<<endl;*/
    }
}
