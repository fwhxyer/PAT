#include<iostream>
#include<algorithm>
using namespace std;

int minn(int a,int b){return a<b?a:b;}
int pow2[]={1,2,4,8,16,32,64,128,256,512,1024};
int a[1010],tree[1010],l[1010],r[1010],q[1010];
int build(int h,int t){
    if (h==t) return h;
	if (h>t) return -1;
    int i=0;
    while (pow2[i]-1<(t-h+1)) i++;
    i--;
    int me=minn(pow2[i-1],t-h+1-pow2[i]+1)+pow2[i]/2+h-1;
    tree[me]=a[me];
    l[me]=build(h,me-1);
    r[me]=build(me+1,t);
    return me;
}
void bfs(int n){
    q[0]=n;
    int a=0,b=1;
    while (a<b){
        if (l[q[a]]!=-1) q[b++]=l[q[a]];
        if (r[q[a]]!=-1) q[b++]=r[q[a]];
        a++;
    }
    cout<<q[0];
    for (int i=1;i<a;i++)
        cout<<" "<<q[i];
    cout<<endl;
}

int main(){
    fill(l,l+1010,-1);
    fill(r,r+1010,-1);
    int n;
    cin>>n;
    for (int i=0;i<n;i++)
        cin>>a[i];
    sort(a,a+n);
    int head;
    head=build(0,n-1);
    bfs(head);
    return 0;
}
