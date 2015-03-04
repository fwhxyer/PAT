#include<iostream>
#define maxx 2100000000
using namespace std;


int num[505];
bool check[505];
int mp[505][505];
int n,m,st,en,a,b,c,anslen=maxx,anssum=0,anscnt=0;

void dfs(int st,int en,int len,int sum){
    if (st==en){
        if (len<anslen){
            anslen=len;
            anssum=sum;
            anscnt=1;
        }else if (len=anslen){
            if (sum>anssum) anssum=sum;
            anscnt++;
        }
    }else{
        for (int i=0;i<n;i++)
            if (mp[st][i]&&!check[i]){
                check[i]=1;
                dfs(i,en,len+mp[st][i],sum+num[i]);
                check[i]=0;
            }
    }
}

int main(){
    cin>>n>>m>>st>>en;
    for (int i=0;i<n;i++){
        for (int j=0;j<n;j++){
            mp[i][j]=1000000000;
        }
        check[i]=0;
    }
    for (int i=0;i<n;i++)
        cin>>num[i];
    for (int i=0;i<m;i++){
        cin>>a>>b>>c;
        mp[a][b]=mp[b][a]=c;
    }
    check[st]=1;
    dfs(st,en,0,num[st]);
    cout<<anscnt<<" "<<anssum<<endl;
    return 0;
}
