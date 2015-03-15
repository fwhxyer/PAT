#include<iostream>
#include<vector>
#include<string>
#include<map>
#define INF 2100
using namespace std;

map<string,int> mp;
int v[210][210];
bool vv[210]={0};
int d[210][4];
int happiness[210];
int fa[210];

void coutroute(int n){
    if (fa[n]!=0)
        coutroute(fa[n]);
    cout<<"->"<<n;
}
int main(){
    int n,m,cost,t=0,startT=0,endT=0;
    string h,name,hname,name2;
    cin>>n>>m>>hname;
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            v[i][j]=INF;
    for(int i=0;i<n;i++)
        v[i][i]=0;
    mp.insert(make_pair(name,t++));
    for (int i=1;i<n;i++){
        cin>>name;
        mp.insert(make_pair(name,t++));
        cin>>happiness[mp[name]];
    }
    endT=mp["ROM"];
    for (int i=0;i<m;i++){
        cin>>name>>name2>>cost;
        v[mp[name]][mp[name2]]=v[mp[name2]][mp[name]]=cost;
    }
    vv[0]=1;
    d[0][0]=d[0][1]=d[0][2]=d[0][3]=0;
    for (int i=1;i<=n-1;i++){
        d[i][0]=v[0][i];
        if (d[i][0]!=INF) d[i][1]=happiness[i]; else d[i][1]=0;
        if (d[i][0]!=INF) d[i][2]=1; else d[i][2]=INF;
        if (d[i][0]!=INF) d[i][3]=1; else d[i][3]=0;
        fa[i]=0;
    }
    int mint=INF,minp=0;
    for (int i=1;i<=n-1;i++){
		mint=INF,minp=0;
        for (int j=1;j<n;j++)
            if (!vv[j]&&d[j][0]<mint) mint=d[minp=j][0];
        vv[minp]=1;
        for (int j=1;j<n;j++){
            if (d[j][0]==d[minp][0]+v[minp][j]) d[i][3]++;
            if (d[j][0]>d[minp][0]+v[minp][j]) {
                d[j][0]=d[minp][0]+v[minp][j];
                d[j][1]=d[minp][1]+happiness[minp];
                d[j][2]=d[minp][2]+1;
                d[i][3]=1;
                fa[j]=minp;
            } else if (d[j][0]==d[minp][0]+v[minp][j]
                    &&d[j][1]<d[minp][1]+happiness[j]){
                d[j][1]=d[minp][1]+happiness[minp];
                d[j][2]=d[minp][2]+1;
                fa[j]=minp;
            } else if (d[j][0]==d[minp][0]+v[minp][j]
                    &&d[j][1]==d[minp][1]+happiness[minp]
                    &&d[j][2]>d[minp][2]+1){
                d[j][2]=d[minp][2]+1;
                fa[j]=minp;
            }
        }
    }
    cout<<d[endT][3]<<" "<<d[endT][0]<<" "<<d[endT][1]<<" "<<d[endT][1]/(d[endT][2]-1)<<endl<<hname;
    coutroute(endT);
    return 0;
}
