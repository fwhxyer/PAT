#include<iostream>
#include<cstdio>
using namespace std;

int mp[1010][1010];
int check[1010];
int check2[1010];
int check3[1010];
int qu[1010];
int qu1[1010];
int n,l,t,m,ans;
void dfs(int s,int l){
    //cout<<s<<" ";
    if (check3[s]&&check3[s]<=l) return;
    if (check3[s]>l) check3[s]=l;
    if (!check2[s]) {ans++;check2[s]=1;}
    if (l<=0) return;
    for (int i=1;i<=n;i++){
        if (!check[i]&&mp[s][i]){
            check[i]=1;
            dfs(i,l-1);
            check[i]=0;
        }
    }
}
void bfs(int s,int l){
    int p=0,q=1;
    qu[0]=s;
    qu1[0]=0;
    while(p<q){
        if (qu1[p]>=l) break;
        for (int i=1;i<=n;i++)
            if (!check[i]&&mp[qu[p]][i]){
                check[i]=1;
                qu[q]=i;
                qu1[q++]=qu1[p]+1;
            }
        p++;
        /*
        cout<<q<<endl;
        for (int i=0;i<q;i++)
            cout<<qu[i]<<" ";
        cout<<endl;
        */
    }
    ans=q;
}

int main(){
    //cin>>n>>l;
    scanf("%d %d",&n,&l);
    for (int i=1;i<=n;i++){
        //cin>>m;
        scanf("%d",&m);
        for (int j=0;j<m;j++){
            //cin>>t;
            scanf("%d",&t);
            mp[t][i]=1;
        }
    }
    //cin>>m;
    scanf("%d",&m);
    //fill(check,check+n+1,0);
    for (int i=0;i<m;i++){
        //cin>>t;
        scanf("%d",&t);
        ans=0;
        fill(check,check+n+1,0);
        check[t]=1;
        bfs(t,l);
        /*fill(check2,check2+n+1,0);
        fill(check3,check3+n+1,0);
        check[t]=1;
        dfs(t,l);
        check[t]=0;
        */
        //cout<<endl;
        //cout<<ans-1<<endl;
        printf("%d\n",ans-1);
    }
    return 0;
}
