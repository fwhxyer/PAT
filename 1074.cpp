#include<iostream>
#include<cstdio>
using namespace std;

struct Note{
    int val;
    int pre;
    int nex;
    int addr;
}note[100010];
int main(){
    int h,h1,n,m,v,nexta,addr;
    cin>>h>>n>>m;
    for (int i=0;i<n;i++){
        cin>>addr>>v>>nexta;
        note[addr].val=v;
        note[addr].nex=nexta;
        note[addr].addr=addr;
    }
    if (h==-1) return 0;
    Note t=note[h];
    t.pre=-1;
    while (t.nex!=-1){
        note[t.nex].pre=t.addr;
        t=note[t.nex];
    }
    t=note[h];
    int cnt=0;
    while (t.nex!=-1){
        cnt++;
        if (cnt==m){
            h1=t.addr;
            break;
        }
        t=note[t.nex];
    }
    t=note[h];
    int pret=h,nextp;
    nexta=h;
    cnt=0;
    while (t.nex!=-1){
        if (!cnt) {
            nexta=t.addr;
            nextp=t.pre;
            t.pre=t.nex;
            //t.nex=tmp;
            t=note[t.nex];
            cnt++;
            continue;
        }
        cnt++;
        if (cnt>=m) {
            int tmp=t.pre;
            t.pre=nextp;
            note[nexta].nex=t.nex;
            int tmp1=t.nex;
            t.nex=tmp;
            t=note[tmp1];
            continue;
        }
        int tmp=t.pre;
        t.pre=t.nex;
        t.nex=tmp;
        t=note[t.pre];
    }
    int tmp=t.pre;
    t.pre=nextp;
    t.nex=tmp;

    t=note[h1];
    while (t.nex!=-1){
        printf("%05d %d %05d\n",t.addr,t.val,t.nex);
        t=note[t.nex];
    }
    return 0;
}
