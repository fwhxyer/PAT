#include<algorithm>
#include<iostream>
#include<cstdio>
#include<vector>
#include<map>
using namespace std;

vector<pair<double,double> > v;
//double mint[505]={0};

int main(){
    double capa,dist,davg,ans=0;
    int n;
    cin>>capa>>dist>>davg>>n;
    for (int i=0;i<n;i++){
        double pt,dt;
        cin>>pt>>dt;
        v.push_back(make_pair(dt,pt));
    }
    v.push_back(make_pair(dist,0));n++;
    sort(v.begin(),v.end());
    /*
    for (int i=0;i<n;i++)
        cout<<v[i].second<<"\t"<<v[i].first<<endl;
    */
    double maxdist=capa*davg;
    if (!v.size()||v[0].first>0) {printf("The maximum travel distance = 0\n");return 0;}
    double capanow=0;int th=0;
    while (th<n){
        //cout<<th<<" "<<ans<<endl;
        double mint=v[th].second;
        int minp=th;bool b1=true;
        for (int i=th;i<n&&maxdist>=v[i].first-v[th].first;i++){
            b1=false;
            if (v[i].second<mint){mint=v[i].second;minp=i;break;}
        }
        if (minp==th) {
            ans+=(capa-capanow)*v[th].second;capanow=capa;
            mint=2100000000;
            for (int i=th+1;i<n&&maxdist>=v[i].first-v[th].first;i++)
                if (v[i].second<mint){mint=v[i].second;minp=i;}
            if (mint==2100000000){
                printf("The maximum travel distance = %0.2lf\n",v[th].first+maxdist);
                return 0;
            }else{
                capanow-=(v[minp].first-v[th].first)/davg;
                th=minp;
            }
        }else if (b1){
            printf("The maximum travel distance = %0.2lf\n",v[th].first+maxdist);
            return 0;
        }else{
            if (capanow>=(v[minp].first-v[th].first)/davg){
                capanow-=(v[minp].first-v[th].first)/davg;
                th=minp;
            }else{
                ans+=((v[minp].first-v[th].first)/davg-capanow)*v[th].second;
                capanow=0;
                th=minp;
            }
        }
    }
    printf("%0.2lf\n",ans);
    /*
    fill(mint,mint+n,2100000000);
    mint[0]=0;
    for (int j=1;j<n;j++){
        for (int i=j-1;i>=0&&maxdist>=v[j].first-v[i].first;i--)
            if (mint[j]>mint[i]+(v[j].first-v[i].first)/davg*v[i].second)
                mint[j]=mint[i]+(v[j].first-v[i].first)/davg*v[i].second;
        if (mint[j]==2100000000) break;
    }
    for (int i=0;i<n;i++)
        cout<<v[i].second<<"\t"<<v[i].first<<endl;
    for (int i=0;i<n;i++)
        cout<<mint[i]<<endl;
    if (mint[n-1]!=2100000000)
        printf("%0.2lf\n",mint[n-1]);
    else{
        int i;
        for (i=n-1;i>=0;i--)
            if (mint[i]!=2100000000) break;
        printf("The maximum travel distance = %0.2lf\n",v[i].first+maxdist);
    }
    */
    return 0;
}
