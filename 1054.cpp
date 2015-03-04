#include<iostream>
#include<map>
using namespace std;

map<int,int> mp;

int main(){
    int m,n,t;
    while (cin>>m>>n){
        mp.clear();
        for (int i=0;i<n;i++)
            for (int j=0;j<m;j++){
                cin>>t;
                mp[t]++;
            }
        map<int,int>::iterator it;
        int max=0,ans=0,i=0;
        for (it=mp.begin();it!=mp.end();++it){
            //cout<<i++<<"   "<<it->first<<" "<<it->second<<endl;
            if (it->second>max)
                {max=it->second;ans=it->first;}
        }
        cout<<ans<<endl;
    }
    return 0;
}
