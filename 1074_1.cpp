#include<iostream>
#include<cstdio>
using namespace std;

struct Node{
    int val;
    int nex;
    int pre;
    int addr;
}note[100010];

int main(){
    int h,n,m;
    cin>>h>>n>>m;
    int nex,addr,val;
    for (int i=0;i<n;i++)
    {
        cin>>addr>>val>>nex;
        note[addr].val=val;
        note[addr].nex=nex;
        note[addr].addr=addr;
    }
    if (h==-1) return 0;
    int t=h;
    note[t].pre=-1;
    while(note[t].nex!=-1){
        note[note[t].nex].pre=note[t].addr;
        t=note[t].nex;
    }
    int s1=-1,s2=-1,s3=-1,s4=-1;
    int cnt=0,ss=0;t=h;
    bool firsts2=1,firsts1=1,firsts4=1;
    while(note[t].nex!=-1){
        if (cnt%m==0) {
            if (!ss) {
                s1=t;
                if (!firsts1) {note[s3].nex=t;}
                firsts1=false;
            }
            else {s3=t;}
        } else
        if (cnt%m==m-1) {
            if (!ss) {s2=t;ss=1;if (firsts2) {firsts2=false;h=t;}}
            else {
                if (firsts4){
                    note[s2].pre=-1;
                    firsts4=0;
                }else
                    note[s2].pre=note[s4].addr;
                note[s2].nex=note[s1].addr;
                s4=t;ss=0;
                note[s1].pre=note[s2].addr;
                note[s1].nex=note[s4].addr;
                note[s4].pre=note[s1].addr;
                note[s4].nex=note[s3].addr;
                note[s3].pre=note[s4].addr;
            }
        } else {
            int tmp=note[t].pre;
            note[t].pre=note[t].nex;
            note[t].nex=tmp;
        }
        cnt++;
        t=note[t].nex;
    }
    if (firsts4){
        if (firsts2){
            s2=t;
            note[s2].pre=-1;
            h=s2;
            note[s2].nex=s1;
            note[s1].pre=s2;
            note[s1].nex=-1;
        }else if (!ss&&cnt%m==0){
            h=t;
            note[t].pre=note[t].nex=-1;
        }else if (cnt%m==0){
            note[s2].pre=-1;
            h=s2;
            note[s2].nex=s1;
            note[s1].pre=s2;
            note[s1].nex=t;
            note[t].pre=s1;
            note[t].nex=-1;
        }else{
            note[s2].pre=-1;
            h=s2;
            note[s2].nex=s1;
            note[s1].pre=s2;
            note[s1].nex=t;
            note[t].pre=s1;
            note[t].nex=s3;
            note[s3].pre=t;
            note[s3].nex=-1;
        }
    }else{
        if (!ss){
            if (cnt%m!=0){
                s2=t;
                note[s3].nex=s2;
                note[s2].pre=note[s3].addr;
                note[s2].nex=note[s1].addr;
                note[s1].pre=note[s2].addr;
                note[s1].nex=-1;
            }else {
                note[s3].nex=t;
                note[t].pre=s3;
                note[t].nex=-1;
            }
        }else {
            if (cnt%m!=0){
                note[s2].pre=note[s4].addr;
                note[s2].nex=note[s1].addr;
                s4=t;ss=0;
                note[s1].pre=note[s2].addr;
                note[s1].nex=note[s4].addr;
                note[s4].pre=note[s1].addr;
                note[s4].nex=note[s3].addr;
                note[s3].pre=note[s4].addr;
            }else{
                note[s2].pre=note[s4].addr;
                note[s2].nex=note[s1].addr;
                note[s1].pre=note[s2].addr;
                note[s1].nex=t;
                note[t].pre=s1;
                note[t].nex=-1;
            }
        }
    }
    t=h;
    while(note[t].nex!=-1){
        printf("%05d %d %05d\n",note[t].addr,note[t].val,note[t].nex);
        t=note[t].nex;
    }
    return 0;
}
