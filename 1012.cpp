#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;

struct Stu{
    int name;
    int c;
    int m;
    int e;
    int a;
    int r[4];
    Stu(){}
};

bool cmp1(Stu a,Stu b){
    if (a.a>b.a) return true;
    return false;
}
bool cmp2(Stu a,Stu b){
    if (a.c>b.c) return true;
    return false;
}
bool cmp3(Stu a,Stu b){
    if (a.m>b.m) return true;
    return false;
}
bool cmp4(Stu a,Stu b){
    if (a.e>b.e) return true;
    return false;
}

Stu stu[2010];

int main(){
    int n,m;
    cin>>n>>m;
    for (int i=0;i<n;i++)
    {
        cin>>stu[i].name>>stu[i].c>>stu[i].m>>stu[i].e;
        stu[i].a=floor((stu[i].c+stu[i].m+stu[i].e)/3.0+0.5);
    }
    sort(stu,stu+n,cmp1);
    //cout<<endl;
    for (int i=0;i<n;i++){
        //cout<<stu[i].name<<" "<<stu[i].c<<" "<<stu[i].m<<" "<<stu[i].e<<" "<<stu[i].a<<endl;
        if (i&&stu[i].a==stu[i-1].a) stu[i].r[0]=stu[i-1].r[0];
        else stu[i].r[0]=i+1;
    }
    sort(stu,stu+n,cmp2);
    //cout<<endl;
    for (int i=0;i<n;i++){
        //cout<<stu[i].name<<" "<<stu[i].c<<" "<<stu[i].m<<" "<<stu[i].e<<" "<<stu[i].a<<" "<<stu[i].r[0]<<endl;
        if (i&&stu[i].c==stu[i-1].c) stu[i].r[1]=stu[i-1].r[1];
        else stu[i].r[1]=i+1;
    }
    sort(stu,stu+n,cmp3);
    //cout<<endl;
    for (int i=0;i<n;i++){
        //cout<<stu[i].name<<" "<<stu[i].c<<" "<<stu[i].m<<" "<<stu[i].e<<" "<<stu[i].a<<endl;
        if (i&&stu[i].m==stu[i-1].m) stu[i].r[2]=stu[i-1].r[2];
        else stu[i].r[2]=i+1;
    }
    sort(stu,stu+n,cmp4);
    //cout<<endl;
    for (int i=0;i<n;i++){
        //cout<<stu[i].name<<" "<<stu[i].c<<" "<<stu[i].m<<" "<<stu[i].e<<" "<<stu[i].a<<endl;
        if (i&&stu[i].e==stu[i-1].e) stu[i].r[3]=stu[i-1].r[3];
        else stu[i].r[3]=i+1;
    }
    int tmp;
    for (int j=0;j<m;j++){
        cin>>tmp;
        int i;
        for (i=0;i<n;i++)
            if (stu[i].name==tmp) {break;}
        if (i==n) cout<<"N/A"<<endl;
        else{
            int mint=3000,ans=0;
            for (int k=0;k<4;k++)
                if (stu[i].r[k]<mint) {mint=stu[i].r[k];ans=k;}
            switch (ans){
            case 0:
                cout<<stu[i].r[0]<<" A"<<endl;
                break;
            case 1:
                cout<<stu[i].r[1]<<" C"<<endl;
                break;
            case 2:
                cout<<stu[i].r[2]<<" M"<<endl;
                break;
            case 3:
                cout<<stu[i].r[3]<<" E"<<endl;
                break;
            }
        }
    }
    return 0;
}
