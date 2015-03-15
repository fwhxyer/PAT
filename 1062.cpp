#include<cstdio>
#include<algorithm>
using namespace std;

struct Stu{
    int id;
    int tal;
    int vir;
}sa[100010],no[100010],fo[100010],sm[100010];

bool cmp(Stu a,Stu b){

    if (a.tal+a.vir>b.tal+b.vir) return true;
    else if (a.tal+a.vir==b.tal+b.vir){
        if (a.vir>b.vir)
            return true;
        else if (a.vir==b.vir){
            if (a.id<b.id) return true;
        }
    }
    return false;
    /*
    if (a.id>b.id) return 1;
    else if(a.id<b.id) return -1;
    return 0;
    */
}

int main(){
    int n,l,h,a,b,c,sal=0,nol=0,fol=0,sml=0;
    scanf("%d %d %d",&n,&l,&h);
    for (int i=0;i<n;i++){
        scanf("%d %d %d",&a,&b,&c);
        if (b>=h&&c>=h){
            sa[sal].id=a;
            sa[sal].vir=b;
            sa[sal++].tal=c;
        }else if (b>=h&&c>=l){
            no[nol].id=a;
            no[nol].vir=b;
            no[nol++].tal=c;
        }else if (b>=c&&b>=l&&c>=l){
            fo[fol].id=a;
            fo[fol].vir=b;
            fo[fol++].tal=c;
        }else if (b>=l&&c>=l){
            sm[sml].id=a;
            sm[sml].vir=b;
            sm[sml++].tal=c;
        }
    }
    sort(sa,sa+sal,cmp);
    sort(no,no+nol,cmp);
    sort(fo,fo+fol,cmp);
    sort(sm,sm+sml,cmp);
    //printf("%d %d %d %d %d\n",sal+nol+fol+sml,sal,nol,fol,sml);
    printf("%d\n",sal+nol+fol+sml);
    for (int i=0;i<sal;i++)
        printf("%d %d %d\n",sa[i].id,sa[i].vir,sa[i].tal);
    for (int i=0;i<nol;i++)
        printf("%d %d %d\n",no[i].id,no[i].vir,no[i].tal);
    for (int i=0;i<fol;i++)
        printf("%d %d %d\n",fo[i].id,fo[i].vir,fo[i].tal);
    for (int i=0;i<sml;i++)
        printf("%d %d %d\n",sm[i].id,sm[i].vir,sm[i].tal);
    return 0;
}
