#include<algorithm>
#include<vector>
#include<cstdio>
using namespace std;

struct Stu{
    int a,b;
    int c[5];
    int r;
    int num;
}stu[40010];
bool cmp(Stu a,Stu b){
    if (a.a+a.b>b.a+b.b) return true;
    else if (a.a+a.b==b.a+b.b) {
        if (a.a>b.a) return true;
    }
    return false;
}
bool cmp1(Stu a,Stu b){
    if (a.num<b.num) return true;
    return false;
}
int ssize[110];
vector<Stu> sch[110];

int main(){
    int n,m,mk;
    scanf("%d %d %d",&n,&m,&mk);
    for (int i=0;i<m;i++)
        scanf("%d",&ssize[i]);
    for (int i=0;i<n;i++){
        scanf("%d %d",&stu[i].a,&stu[i].b);
        for (int j=0;j<mk;j++)
        {
            scanf("%d",&stu[i].c[j]);
        }
        stu[i].num=i;
    }
    sort(stu,stu+n,cmp);
    stu[0].r=1;
    for (int i=1;i<n;i++)
        if ((stu[i].a+stu[i].b)/2==(stu[i-1].a+stu[i-1].b)/2&&stu[i].a==stu[i-1].a)
            stu[i].r=stu[i-1].r;
        else
            stu[i].r=i+1;
    for (int i=0;i<n;i++)
    {
        int apply=stu[i].c[0];
        if ((mk>0)&&(sch[apply].size()<ssize[apply]||
            (ssize[apply]&&sch[apply][sch[apply].size()-1].r==stu[i].r)))
            sch[apply].push_back(stu[i]);
        else{
            apply=stu[i].c[1];
            if ((mk>1)&&(sch[apply].size()<ssize[apply]||
                (ssize[apply]&&sch[apply][sch[apply].size()-1].r==stu[i].r)))
                sch[apply].push_back(stu[i]);
            else{
                apply=stu[i].c[2];
                if ((mk>2)&&(sch[apply].size()<ssize[apply]||
                    (ssize[apply]&&sch[apply][sch[apply].size()-1].r==stu[i].r)))
                    sch[apply].push_back(stu[i]);
                else{
                    apply=stu[i].c[3];
                    if ((mk>3)&&(sch[apply].size()<ssize[apply]||
                        (ssize[apply]&&sch[apply][sch[apply].size()-1].r==stu[i].r)))
                        sch[apply].push_back(stu[i]);
                    else{
                        apply=stu[i].c[4];
                        if ((mk>4)&&(sch[apply].size()<ssize[apply]||
                            (ssize[apply]&&sch[apply][sch[apply].size()-1].r==stu[i].r)))
                            sch[apply].push_back(stu[i]);
                    }
                }
            }
        }
    }
    for (int i=0;i<m;i++)
    {
        if (sch[i].size()>0){
            sort(sch[i].begin(),sch[i].end(),cmp1);
            for (int j=0;j<sch[i].size()-1;j++)
                printf("%d ",sch[i][j].num);
            printf("%d\n",sch[i][sch[i].size()-1].num);
        } else
            printf("\n");
    }
    return 0;
}
