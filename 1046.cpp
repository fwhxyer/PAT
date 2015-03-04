#include<iostream>
using namespace std;

int dis[100010];

int main(){
    int n;
    while (cin>>n){
        int t;
        dis[0]=0;
        for (int i=1;i<=n;i++){
            cin>>t;
            dis[i]=dis[i-1]+t;
        }
        int m,a,b;
        cin>>m;
        for (int i=0;i<m;i++)
        {
            cin>>a>>b;
            a--;b--;
            if (a>b) {t=a;a=b;b=t;}
            t=dis[b]-dis[a];
            cout<<((t>dis[n]-t)?dis[n]-t:t)<<endl;
        }
    }
}
