#include<algorithm>
#include<iostream>
#include<cstdio>
#include<vector>
#include<string>
#include<map>
using namespace std;

vector<pair<int,pair<string,string> > > v,vv;
bool cmp(pair<int,pair<string,string> > a,pair<int,pair<string,string> > b){
    if (a.first<b.first) return true;
    return false;
}

int main(){
    int n,valu,tmp;
    char addrt[6],nextt[6];
    string addr,next,head,headt;
    //cin>>n>>head;
    scanf("%d %s",&n,addrt);
    head=string(addrt);
    headt=head;
    for (int i=0;i<n;i++){
        //cin>>addr>>valu>>next;
        scanf("%s %d %s",addrt,&valu,nextt);
        addr=string(addrt);
        next=string(nextt);
        vv.push_back(make_pair(valu,make_pair(addr,next)));
    }
    while (head!="-1"){
        int i;
        for (i=0;i<vv.size();i++)
            if (vv[i].second.first==head){
                head=vv[i].second.second;
                vv[i].second.second="-2";
                break;
            }
        if (i>=vv.size()) break;
    }
    for (int i=0;i<vv.size();i++)
        if (vv[i].second.second=="-2"){
            v.push_back(vv[i]);
        }
    if (v.size()){
        sort(v.begin(),v.end(),cmp);
        cout<<v.size()<<" ";
        for (int i=0;i<v.size();i++)
            cout<<v[i].second.first<<endl<<v[i].second.first<<" "<<v[i].first<<" ";
        cout<<"-1"<<endl;
    }else{
        cout<<"0 "<<headt<<endl;
    }
    return 0;
}
