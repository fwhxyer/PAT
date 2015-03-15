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
    Note tt=note[h];
    note[h].pre=-1;
    while (tt.nex!=-1){
        note[tt.nex].pre=tt.addr;
        tt=note[tt.nex];
    }
	int t1=h;
    tt=note[h];
    int cnt=0;
    while (tt.nex!=-1){
        cnt++;
        if (cnt==m){
            h1=tt.addr;
            break;
        }
        tt=note[tt.nex];
    }
    tt=note[h];
	t1=h;
    int pret=h,nextp=-1,nextarch;
    nexta=h;
    cnt=0;
    while (tt.nex!=-1){
        if (!cnt) {
            note[t1].pre=note[t1].nex;
            tt=note[note[t1].nex];
			t1=tt.addr;
            cnt++;

			nextarch=tt.addr;
            continue;
			/*
            nexta=note[t1].addr;
            nextp=note[t1].pre;
            note[t1].pre=note[t1].nex;
            //t.nex=tmp;
            tt=note[note[t1].nex];
			t1=tt.addr;
            cnt++;
            continue;
			*/
        }
        cnt++;
        if (cnt>=m) {
			cnt=0;
            int tmp=note[t1].pre;
            note[t1].pre=nextp;
            note[nexta].nex=note[t1].nex;
            int tmp1=note[t1].nex;
            note[t1].nex=tmp;
            tt=note[tmp1];
			t1=tt.addr;
            continue;
        }
        int tmp=note[t1].pre;
        note[t1].pre=note[t1].nex;
        note[t1].nex=tmp;
        tt=note[note[t1].pre];
		t1=tt.addr;
    }
    int tmp=note[t1].pre;
    note[t1].pre=nextp;
    note[t1].nex=tmp;

    tt=note[h1];
    while (tt.nex!=-1){
        printf("%05d %d %05d\n",tt.addr,tt.val,tt.nex);
        tt=note[tt.nex];
    }
	system("pause");
    return 0;
}
