#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;

struct Mc{
    double a;
    double b;
    double p;
}mc[1010];
bool cmp(Mc a,Mc b){
    if (a.p>b.p) return true;
    return false;
}

int main(){
    int n;
    double d,ans=0;
    cin>>n>>d;
    for (int i=0;i<n;i++)
        cin>>mc[i].a;
    for (int i=0;i<n;i++){
        cin>>mc[i].b;mc[i].p=mc[i].b/mc[i].a;
    }
    sort(mc,mc+n,cmp);
    for (int i=0;i<n;i++){
        //cout<<mc[i].a<<" "<<mc[i].b<<" "<<mc[i].p<<endl;
        if (d>=mc[i].a) {
            d-=mc[i].a;
            ans+=mc[i].b;
        } else {
            ans+=mc[i].p*d;
            d=0;
        }
    }
    printf("%0.2lf\n",ans);
    return 0;
}
