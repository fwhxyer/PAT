#include<iostream>
#include<map>
#include<string>
#define INF 2100000000
using namespace std;

map<string,int> mp1;
string mp2[210];
int mp[210][210];
int happiness[210];
bool v[210]={0};
int d[210][5]={0};

void coutPath(int n)
{
	if (n){
		coutPath(d[n][4]);
		cout<<"->"<<mp2[n];
	}else
		cout<<mp2[n];
}

int main(){
	int n,m,score,cost,mint,minp;
	string hname,name,name2;
	cin>>n>>m>>hname;
	mp1.insert(make_pair(hname,0));
	//mp2.insert(make_pair(0,hname));
	mp2[0]=hname;
	for (int i=1;i<=n-1;i++){
		cin>>name;
		mp1.insert(make_pair(name,i));
		//mp2.insert(make_pair(i,name));
		mp2[i]=name;
		cin>>happiness[mp1[name]];
	}
	for (int i=0;i<n;i++)
		for (int j=0;j<n;j++)
			mp[i][j]=INF;
	for (int i=0;i<m;i++){
		cin>>name>>name2>>cost;
		mp[mp1[name]][mp1[name2]]=cost;
		mp[mp1[name2]][mp1[name]]=cost;
	}
	for (int i=1;i<n;i++) d[i][0]=INF;
	d[0][3]=1;
	for (int i=0;i<n;i++){
		/*
		cout<<endl;
		for (int i=0;i<5;i++){
			for (int j=0;j<n;j++)
				cout<<d[j][i]<<" ";
			cout<<endl;
		}*/
		mint=INF;minp=-1;
		for (int j=0;j<n;j++)
			if (!v[j]&&mint>d[j][0]) mint=d[minp=j][0];
		if (minp==-1) break;
		v[minp]=1;
		for (int j=0;j<n;j++){
			if (d[j][0]>d[minp][0]+mp[minp][j]){
				d[j][0]=d[minp][0]+mp[minp][j];
				d[j][1]=d[minp][1]+happiness[j];
				d[j][2]=d[minp][2]+1;
				d[j][3]=d[minp][3];
				d[j][4]=minp;
			}else if (d[j][0]==d[minp][0]+mp[minp][j]){
				d[j][3]+=d[minp][3];
				if (d[j][1]<d[minp][1]+happiness[j]){
					d[j][1]=d[minp][1]+happiness[j];
					d[j][2]=d[minp][2]+1;
					d[j][4]=minp;
				}else if (d[j][1]==d[minp][1]+happiness[j]){
					if (d[j][2]>d[minp][2]+1){
						d[j][2]=d[minp][2]+1;
						d[j][4]=minp;
					}
				}
			}
		}
	}
	cout<<d[mp1["ROM"]][3]<<" "<<d[mp1["ROM"]][0]<<" "<<d[mp1["ROM"]][1]
		<<" "<<d[mp1["ROM"]][1]/d[mp1["ROM"]][2]<<endl;
	coutPath(mp1["ROM"]);
	cout<<endl;
	system("pause");
	return 0;
}