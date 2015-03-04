#include<algorithm>
#include<iostream>
#include<cstdio>
#include<vector>
#include<string>
#include<ctime>
#include<map>
using namespace std;

struct List{
	int mo,dd,hh,mm;
	time_t t;
	bool flag;
};
double cost[24];
map<string,vector<List> > mp;
bool cmp(List a,List b){
	if (a.t<b.t) return true;
	return false;
}
double getCost(List a,List b){
	double t=0,tmp=0;
	if (a.mm!=0) {
		t+=(60-a.mm)*cost[a.hh];
		a.hh++;
	}
	if (a.hh!=24) {
		for (int i=a.hh;i<24;i++)
			t+=60*cost[i];
	}
	a.dd++;

	for (int i=0;i<24;i++)
		tmp+=cost[i];
	tmp*=60;
	t+=tmp*(b.dd-a.dd);
	
	for (int i=0;i<b.hh;i++)
		t+=60*cost[i];
	t+=b.mm*cost[b.hh];
	
	return t;
}

int main(){
	int n;
	for (int i=0;i<24;i++){
		cin>>cost[i];
		cost[i]/=100;
	}
	cin>>n;
	string name,sflag;
	char ctmp;
	int mo,dd,hh,mm;
	for (int i=0;i<n;i++){
		cin>>name>>mo>>ctmp>>dd>>ctmp>>hh>>ctmp>>mm>>sflag;
		
		List list;
		tm tmm;
		tmm.tm_year=2015-1900;
		tmm.tm_mon=mo-1;
		tmm.tm_mday=dd;
		tmm.tm_hour=hh;
		tmm.tm_min=mm;
		tmm.tm_sec=0;
		list.mo=mo;list.dd=dd;list.hh=hh;list.mm=mm;
		list.t=mktime(&tmm);
		if (sflag=="on-line") list.flag=1;
		else list.flag=0;
		
		if (!mp.count(name)){
			vector<List> ls;
			ls.push_back(list);
			ls.push_back(list);
			mp.insert(make_pair(name,ls));
		}else 
			mp[name].push_back(list);
	}
	/*
	for (map<string,vector<List> >::iterator it=mp.begin();it!=mp.end();it++)
	{
		printf("%s %d\n",it->first.c_str(),it->second.size());
		for (int i=0;i<it->second.size();i++)
			cout<<it->second[i].t<<" "<<it->second[i].flag<<endl;
		printf("\n");
	}
	*/
	for (map<string,vector<List> >::iterator it=mp.begin();it!=mp.end();it++)
	{
		sort((it->second).begin()+1,(it->second).end(),cmp);
		bool b=1;int t;
		for (int i=it->second.size()-1;i>=1;i--){
			if (b&&it->second[i].flag)
				it->second.erase(it->second.begin()+i);
			else if (b&&!(it->second[i].flag)) {
				b=0;t=i;
			}
			else if (!b&&(it->second[i].flag)) {
				b=1;
			}
			else if (!b&&!(it->second[i].flag)) {
				it->second.erase(it->second.begin()+t);
				t=i;
			}
		}
		if (!b)
			it->second.erase(it->second.begin()+t);
	}
	for (map<string,vector<List> >::iterator it=mp.begin();it!=mp.end();it++)
	{
		if (it->second.size()>1){
			printf("%s %02d\n",it->first.c_str(),it->second[0].mo);

			double ans=0,ans1=0;
			for (int i=2;i<it->second.size();i++){
				if (!(it->second[i].flag)) {
					ans1=getCost(it->second[i-1],it->second[i]);
					printf("%02d:%02d:%02d %02d:%02d:%02d %d",
						it->second[i-1].dd,it->second[i-1].hh,it->second[i-1].mm,
						it->second[i].dd,it->second[i].hh,it->second[i].mm,
						((it->second[i].t-it->second[i-1].t)/60));
					printf(" $%0.2lf\n",ans1);
					ans+=ans1;
				}
			}
		
			printf("Total amount: $%0.2lf\n",ans);
		}
	}
	system("pause");
	return 0;
}
