#include<algorithm>
#include<iostream>
#include<cstring>
#include<string>
#include<cstdio>
using namespace std;
struct Stu {
    char id[7];
    char name[9];
    int grade;
}stu[100010];

bool cmp(char a[10],char b[10]){
    int i=0;
    while (i<10&&a[i]!='\0'&&b[i]!='\0')
	{
        if (a[i]<b[i]) return true;
		else if (a[i]>b[i]) return false;
        i++;
    }
    if ((a[i]=='\0')&&(b[i]!='\0')) return true;
    return false;
}
bool cmp1(Stu a,Stu b){
    if (strcmp(a.id,b.id)<0) return true;
    return false;
}
bool cmp2(Stu a,Stu b){
    if (strcmp(a.name,b.name)<0) return true;
    if (strcmp(a.name,b.name)==0&&strcmp(a.id,b.id)<0) return true;
    return false;
}
bool cmp3(Stu a,Stu b){
    if (a.grade<b.grade) return true;
    if (a.grade==b.grade&&strcmp(a.id,b.id)<0) return true;
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
	system("pause");
    return 0;
}
