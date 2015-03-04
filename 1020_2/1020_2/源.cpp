#include<iostream>
using namespace std;

struct Node{
    int l;
    int r;
    Node():l(0),r(0){}
};
int po[40],io[40],qu[40];
Node no[50];
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
    int mid=findi(po[nn],li,ri);
    if (nn-1>=lp){
        int tmp=findi(po[nn-1],li,ri);
        if (tmp>mid){
            no[po[nn]].r=po[nn-1];
            dfs(nn-1,nn-(ri-mid),nn-1,mid+1,ri);
			if (nn-1-(ri-mid)>=lp){
				no[po[nn]].l=po[nn-1-(ri-mid)];
				dfs(nn-1-(ri-mid),lp,nn-1-(ri-mid),li,mid-1);
			}
        }else{
            no[po[nn]].l=po[nn-1];
            dfs(nn-1,nn-(mid-li),nn-1,li,mid-1);
			if (nn-1-(mid-li)>=lp){
				no[po[nn]].r=po[nn-1-(mid-li)];
				dfs(nn-1-(mid-li),lp,nn-1-(mid-li),mid+1,ri);
			}
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
        cout<<" "<<qu[p];
        p++;
    }
    cout<<endl;
}

int main(){
    while (cin>>n){
		for (int i=0;i<40;i++)
			po[i]=io[i]=qu[i]=no[i].l=no[i].r=0;
        for (int i=0;i<n;i++) cin>>po[i];
        for (int i=0;i<n;i++) cin>>io[i];
        dfs(n-1,0,n-1,0,n-1);
        bfs(po[n-1]);
    }
    return 0;
}
