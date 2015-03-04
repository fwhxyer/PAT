#include<algorithm>
#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;

struct PA{
    int first;
    int second;
    int third;
};
vector<PA> v,vv;
bool cmp(PA a,PA  b){
    if (a.first<b.first) return true;
    return false;
}

int main(){
    int n,valu,tmp;
    int addr,next,head,headt;
    //cin>>n>>head;
    scanf("%d %d",&n,&head);
    headt=head;
    for (int i=0;i<n;i++){
        //cin>>addr>>valu>>next;
        scanf("%d %d %d",&addr,&valu,&next);
        PA pa;pa.first=valu;pa.second=addr;pa.third=next;
        vv.push_back(pa);
    }
   // for (int i=0;i<vv.size();i++)
      //  cout<<vv[i].first<<" "<<vv[i].second.first<<" "<<vv[i].second.second<<endl;
    while (head!=-1){
        int i;
        for (i=0;i<vv.size();i++)
            if (vv[i].second==head){
                head=vv[i].third;
                vv[i].third=-2;
                break;
            }
        if (i>=vv.size()) break;
    }
    for (int i=0;i<vv.size();i++)
        if (vv[i].third==-2){
            v.push_back(vv[i]);
        }
    if (v.size()){
        sort(v.begin(),v.end(),cmp);
        /*
        cout<<v.size()<<" ";
        for (int i=0;i<v.size();i++)
            cout<<v[i].second.first<<endl<<v[i].second.first<<" "<<v[i].first<<" ";
        cout<<"-1"<<endl;
        */
        printf("%d ",v.size());
        for (int i=0;i<v.size();i++)
            printf("%05d\n%05d %d ",v[i].second,v[i].second,v[i].first);
        printf("-1\n");
    }else{
        //cout<<"0 "<<headt<<endl;
        printf("0 -1\n");
    }
    return 0;
}
