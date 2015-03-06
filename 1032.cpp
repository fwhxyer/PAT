#include<iostream>
#include<cstdio>
using namespace std;

bool check[100100];
int  nextt[100100];
char value[100100];

int main(){
    fill(check,check+100100,0);
    int a,b,n,x,z;char y;
    cin>>a>>b>>n;
    for (int i=0;i<n;i++){
        cin>>x>>y>>z;
        nextt[x]=z;
        value[x]=y;
    }
    int ta=a,tb=b;
    while (ta!=-1){
        check[ta]=1;
        ta=nextt[ta];
    }
    bool t=0;
    while (tb!=-1){
        if (check[tb]==1) {printf("%05d",tb);t=1;break;}
        tb=nextt[tb];
    }
    if (!t)
        printf("-1");
    return 0;
}
