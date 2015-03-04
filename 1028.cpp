#include<algorithm>
#include<iostream>
#include<string>
#include<cstdio>
using namespace std;
struct Stu {
    char id[7];
    char name[9];
    int grade;
}stu[100010];

bool cmp(char a[],char b[]){
    int i=0;
    while (a[i]!='\0'&&b[i]!='\0'){
        if (a[i]<b[i]) return true;
        i++;
    }
    if (a[i]=='\0'&&b[i]) return true;
    return false;
}
bool cmp1(Stu a,Stu b){
    if (cmp(a.id,b.id)) return true;
    return false;
}
bool cmp2(Stu a,Stu b){
    if (cmp(a.name,b.name)) return true;
    if (a.name==b.name&&a.id<b.id) return true;
    return false;
}
bool cmp3(Stu a,Stu b){
    if (a.grade<b.grade) return true;
    if (a.grade==b.grade&&a.id<b.id) return true;
    return false;
}
int main()
{
    int n,m;
    scanf("%d %d",&n,&m);
    for (int i=0;i<n;i++)
        scanf("%s %s %d",stu[i].id,stu[i].name,&stu[i].grade);
    switch (m){
    case 1:
        sort(stu,stu+n,cmp1);
        break;
    case 2:
        sort(stu,stu+n,cmp2);
        break;
    case 3:
        sort(stu,stu+n,cmp3);
    break;
    default:
        break;
    }
    for (int i=0;i<n;i++)
        printf("%s %s %d\n",stu[i].id,stu[i].name,stu[i].grade);
    return 0;
}
