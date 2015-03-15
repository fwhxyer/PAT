#include<iostream>
#include<cstdio>
using namespace std;

int node[100010][2];
int listf[100010][2];

int main(){
    int h,n,m,ad,va,ne;
    cin>>h>>n>>m;
    for (int i=0;i<n;i++){
        cin>>ad>>va>>ne;
        node[ad][0]=va;
        node[ad][1]=ne;
    }
    int t=h,l=0;
    while (t!=-1){
        listf[l][0]=node[t][0];
        listf[l++][1]=t;
        t=node[t][1];
    }
    bool first=1;
    int i;
    for (i=0;i+m<=l;i+=m){
        for (int j=i+m-1;j>=i;j--){
            if (!first) printf("%05d\n",listf[j][1]);
            first=0;
            printf("%05d %d ",listf[j][1],listf[j][0]);
        }
    }
    for (;i<l;i++){
        printf("%05d\n",listf[i][1]);
        first=0;
        printf("%05d %d ",listf[i][1],listf[i][0]);
    }
    printf("-1\n");
    return 0;
}
