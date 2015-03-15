#include<iostream>
#include<cstdio>
#include<set>
#include<algorithm>
using namespace std;

set<int > s[55];
int main(){
    int n,m,a,b,t;
    cin>>n;
    for (int i=0;i<n;i++){
        cin>>m;
        for (int j=0;j<m;j++){
            cin>>t;
            s[i].insert(t);
        }
    }
    cin>>m;
    for (int i=0;i<m;i++){
        cin>>a>>b;a--;b--;
        s[53].clear();
        set_intersection(s[a].begin(),s[a].end(),s[b].begin(),s[b].end(),
                         insert_iterator<set<int> >(s[53],s[53].end()));
        int t1=s[53].size();
        int t2=s[a].size()+s[b].size();
        int t3=t2-t1;
        /*
        set_union(s[a].begin(),s[a].end(),s[b].begin(),s[b].end(),
                  insert_iterator<set<int> >(s[53],s[53].end()));
                         */
        double ans=(double)t1/(double)t3*100.0;
        printf("%0.1lf%%\n",ans);
    }
}
