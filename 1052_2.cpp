#include<algorithm>
#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;

struct Node{
    int value;
    int addr;
    int next;
}vv[100010];
vector<Node> v;
bool cmp(Node a,Node b){
    if (a.value<b.value) return true;
    return false;
}

int main(){
    int n,head,addr,valu,next,t;
    scanf("%d %d",&n,&head);
    for (int i=0;i<=n;i++)
        vv[i].addr=vv[i].next=-1;
    for (int i=0;i<n;i++){
        scanf("%d %d %d",&addr,&valu,&next);
        vv[addr].value=valu;
        vv[addr].addr=addr;
        vv[addr].next=next;
    }
    t=head;
    while (t!=-1&&vv[t].addr!=-1){
        //out<<t<<endl;
        v.push_back(vv[t]);
        t=vv[t].next;
    }
    sort(v.begin(),v.end(),cmp);
    if (!v.size())
        printf("0 -1\n");
    else{
        printf("%d ",v.size());
        for (int i=0;i<v.size();i++) {
            printf("%05d\n%05d %d ",v[i].addr,v[i].addr,v[i].value);
        }
        printf("-1\n");
    }
    return 0;
}
