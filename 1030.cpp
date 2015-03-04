#include<iostream>
using namespace std;

int dis[505][505],cos[505][505],mid[505][505];

void printpath(int a,int b){
    if (mid[a][b]>=0){
        printpath(a,mid[a][b]);
        printpath(mid[a][b],b);
    } else if (mid[a][b]==-1)
        cout<<b<<" ";
}

int main(){
    int n,m,s,d,a,b,c,l;
    cin>>n>>m>>s>>d;
    for (int i=0;i<505;i++)
        for (int j=0;j<505;j++){
            dis[i][j]=1000000000;
            cos[i][j]=1000000000;
            mid[i][j]=-2;
        }
    for (int i=0;i<m;i++){
        cin>>a>>b>>l>>c;
        dis[a][b]=dis[b][a]=l;
        cos[a][b]=cos[b][a]=c;
        mid[a][b]=mid[b][a]=-1;
    }
    for (int k=0;k<n;k++)
        for (int i=0;i<n;i++)
            for (int j=0;j<n;j++)
                if (i!=j&&j!=k&&i!=k){
                    if (dis[i][j]>dis[i][k]+dis[j][k]){
                        dis[i][j]=dis[i][k]+dis[j][k];
                        cos[i][j]=cos[i][k]+cos[j][k];
                        mid[i][j]=k;
                    }
                    else if (dis[i][j]==dis[i][k]+dis[j][k]){
                        if (cos[i][j]>cos[i][k]+cos[j][k]){
                            dis[i][j]=dis[i][k]+dis[j][k];
                            cos[i][j]=cos[i][k]+cos[j][k];
                            mid[i][j]=k;
                        }
                    }
                }
    cout<<s<<" ";
    printpath(s,d);
    cout<<dis[s][d]<<" "<<cos[s][d]<<endl;
    return 0;
}
