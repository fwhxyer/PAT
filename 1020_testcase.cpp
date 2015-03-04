#include<iostream>
#include<sstream>
#include<cstdlib>
#include<cstring>
#include<string>
using namespace std;

int bt[100],sum=0;
int ans1[100],ans2[100];
bool bo[100];
stringstream icout;

int rando(int r){
    int ans=rand()%r;
    while (bo[ans%r])
        ans=rand()%r;
    bo[ans]=true;
    return ans;
}
void cnt(int a,int n){
    if (bt[a-1]==-1) return;
    if (a*2<=n)
        cnt(a*2,n);
    if (bt[a-1]!=-1) sum++;
    if (a*2+1<=n)
        cnt(a*2+1,n);
}
void ino(int a,int n,int t=0){
    if (bt[a-1]==-1) t=1;
    if (a*2<=n)
        ino(a*2,n,t);
    if (t) bt[a-1]=-1;
    if (bt[a-1]!=-1) {icout<<bt[a-1]<<" ";cout<<bt[a-1]<<" ";}
    if (a*2+1<=n)
        ino(a*2+1,n,t);
}
void poo(int a,int n){
    if (bt[a-1]==-1) return;
    if (a*2<=n)
        poo(a*2,n);
    if (a*2+1<=n)
        poo(a*2+1,n);
    if (bt[a-1]!=-1) {icout<<bt[a-1]<<" ";cout<<bt[a-1]<<" ";}
}
void inoScreen(int a,int n){
    if (a*2<=n)
        ino(a*2,n);
    if (bt[a-1]!=-1) cout<<bt[a-1]<<" ";
    if (a*2+1<=n)
        ino(a*2+1,n);
}
void pooScreen(int a,int n){
    if (a*2<=n)
        poo(a*2,n);
    if (a*2+1<=n)
        poo(a*2+1,n);
    if (bt[a-1]!=-1) cout<<bt[a-1]<<" ";
}
//---------------------------
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
    ans2[0]=a;
    p++;
    while (p<q){
        if (no[qu[p]].l) qu[q++]=no[qu[p]].l;
        if (no[qu[p]].r) qu[q++]=no[qu[p]].r;
        cout<<" "<<qu[p];
        ans2[p]=qu[p];
        p++;
    }
    cout<<endl;
}
void bfsScreen(int a){
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
//---------------------------
int main(){
    string st;
    do {
        icout.clear();
        icout.sync();
        memset(bo,0,sizeof(bo));
        int x=5;
        int maxx=41;
        int n=rand()%(maxx+1-x)+x;
        for (int i=0;i<n;i++)
        {
            bt[i]=rando(n)+1;
        }
        int i=rand()%(maxx)+1;
        while (i<maxx){
            bt[i]=-1;
            i+=rand()%(maxx+1);
        }
        sum=0;
        cnt(1,n);
        icout<<sum<<endl;cout<<sum<<endl;
        poo(1,n);icout<<endl;cout<<endl;
        ino(1,n);icout<<endl;cout<<endl;
        for (int i=0;i<n;i++)
        {
            if (bt[i]!=-1) {
                cout<<bt[i]<<" ";
                ans1[i]=bt[i];
            }
        }
        int tmp=n;
        cout<<endl;


//---------------------------
        icout>>n;
		for (int i=0;i<40;i++)
			po[i]=io[i]=qu[i]=no[i].l=no[i].r=0;
        for (int i=0;i<n;i++) icout>>po[i];
        for (int i=0;i<n;i++) icout>>io[i];
        dfs(n-1,0,n-1,0,n-1);
        bfs(po[n-1]);
//---------------------------
        /*
        for (int i=0;i<n;i++)
            if (ans1[i]!=ans2[i]){
                cout<<"Wrong Answer!\ntest case:\n";

                cout<<tmp<<endl;
                pooScreen(1,tmp);cout<<endl;
                inoScreen(1,tmp);cout<<endl;
                cout<<"Answer1:\n";
                for (int i=0;i<tmp;i++)
                {
                    if (bt[i]!=-1)
                        cout<<bt[i]<<" ";
                }
                cout<<"\nAnswer2:\n";
                bfsScreen(po[n-1]);
                cout<<endl;
                break;
            }
        */
    }while (getline(cin,st));
}
