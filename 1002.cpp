#include<iostream>
#include<cstring>
#include<cstdio>
#include<cmath>
using namespace std;

double poly[1010];
int main(){
    int n,a;
    double b;
    memset(poly,0,sizeof(poly));
    cin>>n;
    for (int i=0;i<n;i++){
        cin>>a>>b;
        poly[a]+=b;
    }
    cin>>n;
    for (int i=0;i<n;i++){
        cin>>a>>b;
        poly[a]+=b;
    }
    int ansn=0;
    for (int i=0;i<1001;i++){
        if (fabs(poly[i])>=0.0000000001) ansn++;
    }
    printf("%d",ansn);
    for (int i=1000;i>=0;i--){
        if (fabs(poly[i])>=0.0000000001){
            printf(" %d %0.1lf",i,poly[i]);
        }
    }
    return 0;
}
