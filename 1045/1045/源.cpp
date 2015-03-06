#include<iostream>

using namespace std;

int x[10010];
int y[210];
int f[10010][210];

int main(){
    int nc;
    int n,m;
    cin>>nc>>m;
    for (int i=1;i<=m;i++)
        cin>>y[i];
    cin>>n;
    for (int i=1;i<=n;i++)
        cin>>x[i];
    f[0][0]=0;
    f[0][1]=0;
    for (int i=1;i<=n;i++)
        for (int j=1;j<=(i<m?i:m);j++)
            if (x[i]==y[j]){
                f[i][j]=(f[i-1][j]>f[i-1][j-1]?f[i-1][j]:f[i-1][j-1])+1;
            }else
                f[i][j]=f[i-1][j];
    int ans=0;
    for (int i=1;i<=m;i++)
        if (ans<f[n][i]) ans=f[n][i];
    cout<<ans<<endl;
    for (int i=1;i<=n;i++) {
        for (int j=1;j<=m;j++)
            cout<<f[i][j]<<" ";
            cout<<endl;
    }
    return 0;
}
