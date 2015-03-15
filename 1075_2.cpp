#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;

struct Stu{
    int id;
    int score[6];
    int r;
    int cnt;
}stu[10010];
int p[6];
bool cmp(Stu a,Stu b){
    if (a.score[0]>b.score[0]) return true;
    else if (a.score[0]==b.score[0]){
        if (a.cnt>b.cnt) return true;
        else if (a.cnt==b.cnt)
            if (a.id<b.id) return true;
    }
    return false;
}

int main(){
    int n,k,m;
    cin>>n>>k>>m;
    for (int i=1;i<=n;i++){
        stu[i].id=i;
        for (int j=0;j<=k;j++)
            stu[i].score[j]=-2;
    }
    for (int i=1;i<=k;i++)
        cin>>p[i];
    int id,t,s;
    for (int i=0;i<m;i++){
        cin>>id>>t>>s;
        if (stu[id].score[t]<s) stu[id].score[t]=s;
    }
    for (int i=1;i<=n;i++){
        stu[i].score[0]=stu[i].cnt=0;
        for (int j=1;j<=k;j++){
            if (stu[i].score[j]>0)
                stu[i].score[0]+=stu[i].score[j];
            if (stu[i].score[j]==p[j])
                stu[i].cnt++;
        }
    }
    sort(stu+1,stu+1+n,cmp);
    stu[1].r=1;
    for (int i=2;i<=n;i++){
        if (stu[i].score[0]==stu[i-1].score[0])
            stu[i].r=stu[i-1].r;
        else
            stu[i].r=i;
    }
    for (int i=1;i<=n;i++){
        bool t=1;
        if (stu[i].score[0]==0){
            for (int j=1;j<=k;j++)
                if (stu[i].score[j]>=0)
                    t=0;
        } else
            t=0;
        if (t) continue;
        printf("%d %05d %d",stu[i].r,stu[i].id,stu[i].score[0]);
        for (int j=1;j<=k;j++)
            if (stu[i].score[j]>=0)
                printf(" %d",stu[i].score[j]);
            else if (stu[i].score[j]==-2)
                printf(" -");
            else if (stu[i].score[j]==-1)
                printf(" 0");
        printf("\n");
    }
    return 0;
}
