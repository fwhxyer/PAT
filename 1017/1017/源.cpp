#include<algorithm>
#include<iostream>
#include<cstdio>
#include<ctime>
#include<map>
#define maxn 10010
using namespace std;

pair<time_t,int> q[maxn];
int main(){
    int n,m,hh,mm,ss,ww,ans=0;
    tm *tmm,*bopentm,*bclosetm;
	time_t bopen,bclose,tm1,tm2,tm3;
	tm1=tm2=tm3=time(NULL);
	double ansd;
    char c;
    cin>>n>>m;
	bopentm=localtime(&tm1);
    bopentm->tm_hour=8;
	bopentm->tm_min=0;
	bopentm->tm_sec=0;
	bopen=mktime(bopentm);
	bclosetm=localtime(&tm2);
	bclosetm->tm_hour=17;
	bclosetm->tm_min=0;
	bclosetm->tm_sec=0;
	bclose=mktime(bclosetm);
	int j=0;
    for (int i=0;i<n;i++){
        cin>>hh>>c>>mm>>c>>ss>>ww;
		tmm=localtime(&tm3);
        tmm->tm_hour=hh;
		tmm->tm_min=mm;
		tmm->tm_sec=ss;
		time_t tmp=mktime(tmm);
		if (tmp<=bclose)
			q[j++]=make_pair(tmp,ww*60);
    }
	n=j;
    sort(q,q+n);
	for (int i=0;i<n;i++)
		if (q[i].first<bopen){
			ans+=bopen-q[i].first;
			q[i].first=bopen;
		}
		else break;
	int w[101];
	for (int i=0;i<m;i++)
		w[i]=bopen;
	for (int i=0;i<n;i++){
		int mint=2100000000,minp=-1;
		for (int j=0;j<m;j++)
			if (mint>w[j]){
				mint=w[j];minp=j;
			}
		if (w[minp]>q[i].first) {ans+=w[minp]-q[i].first;}
		else w[minp]=q[i].first;
		w[minp]+=q[i].second;
	}
	ansd=ans/60.0/n;
	printf("%0.1lf\n",ansd);
	system("pause");
    return 0;
}
