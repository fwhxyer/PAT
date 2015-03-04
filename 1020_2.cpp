#include<iostream>
using namespace std;

struct Node{
    int l;
    int r;
    Node():l(0),r(0){}
};
int po[40],io[40],qu[40];
Node no[40];
int n;

int findp(int a,int l=0,int r=n-1){
    for (int i=l;i<=r;i++)
        if (po[i]==a) return i;
    return -1;
}
int findi(int a,int l=0,int r=n-1){
    for (int i=l;i<=r;i++)
        if (io[i]==a) return i;
    return -1;
}
void dfs(int nn,int lp,int rp,int li,int ri){
    if (lp>=rp||li>=ri) return;
    int mid=findi(po[nn]);
    if (nn>li){
        int tmp=findi(po[nn-1]);
        if (tmp>mid){
            no[po[nn]].r=po[nn-1];
            dfs(nn-1,nn-1-(ri-mid-1)+1,nn-1,mid+1,ri);
            no[po[nn]].l=po[nn-1-(ri-mid-1)];
            dfs(nn-1-(ri-mid-1),lp,nn-1-(ri-mid-1),li,mid-1);
        }else{
            no[po[nn]].l=po[nn-1];
            dfs(nn-1,nn-1-(mid-1-li)+1,nn-1,li,mid-1);
            no[po[nn]].r=po[nn-1-(mid-1-li)];
            dfs(nn-1-(mid-1-li),lp,nn-1-(mid-1-li),li,mid-1);
        }
    }
}
void bfs(int a){
    int p=0;int q=1;
    qu[0]=a;
    if (no[a].l) qu[q++]=no[a].l;
    if (no[a].r) qu[q++]=no[a].r;
    cout<<a;
    p++;
    while (p<q){
        if (no[qu[p]].l) qu[q++]=no[qu[p]].l;
        if (no[qu[p]].r) qu[q++]=no[qu[p]].r;
        cout<<" "<<a;
        p++;
    }
    cout<<endl;
}

int main(){
    while (cin>>n){
        for (int i=0;i<n;i++) cin>>po[i];
        for (int i=0;i<n;i++) cin>>io[i];
        dfs(n-1,0,n-1,0,n-1);
        bfs(po[n-1]);
    }
    return 0;
}
