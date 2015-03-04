#include<iostream>
#include<cstring>
#include<cstdio>
#include<cmath>
using namespace std;

double coe[2020];
double poly[2020];
int main(){
    int n,m,t;
    double tt;
    memset(coe,0,sizeof(coe));
    memset(poly,0,sizeof(poly));
    cin>>n;
    for (int i=0;i<n;i++){
        cin>>t>>tt;
        poly[t]+=tt;
    }
    cin>>n;
    for (int i=0;i<n;i++){
        cin>>t>>tt;
        for (int j=0;j<1010;j++){
            if (fabs(poly[j])>0.000000001)
                coe[t+j]+=tt*poly[j];
        }
    }
    int cnt=0;
    for (int i=0;i<2020;i++){
        if (fabs(coe[i])>0.000000001)
            cnt++;
    }
    printf("%d",cnt);
    for (int i=2019;i>=0;i--){
        if (fabs(coe[i])>0.000000001)
            printf(" %d %0.1lf",i,coe[i]);
    }
    printf("\n");
    return 0;
}

