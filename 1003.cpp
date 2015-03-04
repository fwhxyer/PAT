#include<iostream>
using namespace std;

int num[505];
int mp[505][505];
int mp1[505][505];
int mp2[505][505];
int mp3[505][505];

int main(){
    int n,m,st,en,a,b,c;
    cin>>n>>m>>st>>en;
    for (int i=0;i<n;i++)
        for (int j=0;j<n;j++){
            mp[i][j]=mp1[i][j]=2100000000;
            mp2[i][j]=mp3[i][j]=0;
        }
    for (int i=0;i<n;i++)
        cin>>num[i];
    for (int i=0;i<m;i++){
        cin>>a>>b>>c;
        mp[a][b]=mp[b][a]=c;
        mp1[a][b]=mp1[b][a]=c;
        mp2[a][b]++;mp2[b][a]++;
        mp3[a][b]=num[a];mp3[b][a]=num[b];
    }
    for (int i=0;i<n;i++)
        for (int k=0;k<n;k++)
            for (int j=0;j<n;j++)
                if (i!=j&&i!=k&&j!=k)
                    if (mp1[i][j]+mp1[j][k]<mp1[i][k]){
                        mp1[i][k]=mp1[i][j]+mp1[j][k];
                        mp2[i][k]=1;
                        mp3[i][k]=mp3[i][j]+mp3[j][k];
                    }else if (mp1[i][j]+mp1[j][k]==mp1[i][k]){
                        mp2[i][k]++;
                        mp3[i][k]=mp3[i][j]+mp3[j][k];
                    }
    cout<<mp2[st][en]<<" "<<mp3[st][en]+num[en]<<endl;
    return 0;
}
