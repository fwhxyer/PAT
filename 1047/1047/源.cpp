#include<iostream>
#include<algorithm>
#include<cstdio>
#include<vector>
#include<cstring>
using namespace std;

vector<char*> v[2510];
bool cmp(char *a,char *b){
    if (strcmp(a,b)<0) return 1;
    return 0;
}

int main(){
    int n,m,k,t;
    scanf("%d %d",&n,&k);
    for (int i=0;i<n;i++){
		char *name=new char[5];
        scanf("%s %d",name,&m);
        for (int j=0;j<m;j++){
            scanf("%d",&t);
            v[t].push_back(name);
        }
    }
    for (int i=1;i<=k;i++){
		v[i].push_back("");
        sort(&v[i][0],&v[i][v[i].size()-1],cmp);
        printf("%d %d\n",i,v[i].size()-1);
        for (int j=0;j<v[i].size()-1;j++)
            printf("%s\n",v[i][j]);
    }
	system("pause");
    return 0;
}
