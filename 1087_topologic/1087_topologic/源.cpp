#include<iostream>
#include<string>
#include<map>
using namespace std;

map<string,int> mp1;
string mp2[210];
int mp[210][210]={0};
int topoArray[210]={0};
int topoArrayR[210]={0};
int topoSize=0;
int n,m,happiness,cost;
int d[210]={0};
bool topologic(int s){
	d[s]=-1;
    for (int i=0;i<n;i++)
		if (mp[s][i]){
			if (!d[i]) {
				if (!topologic(i)) return false;
			}else if (d[i]<0)
				return false;
		}
	d[s]=1;
    topoArray[--topoSize]=s;
    return true;
}
bool topologicR(int s){
	d[s]=-1;
    for (int i=0;i<n;i++)
		if (mp[i][s]){
			if (!d[i]) {
				if (!topologicR(i)) return false;
			}else if (d[i]<0)
				return false;
		}
	d[s]=1;
    topoArrayR[--topoSize]=s;
    return true;
}
bool topoSort(){
	topoSize=n;
	fill(d,d+n,0);
	for (int i=0;i<n;i++){
		if (!d[i])
			if (!topologic(i)) return false;
	}
	return true;
}
bool topoSortR(){
	topoSize=n;
	fill(d,d+n,0);
	for (int i=0;i<n;i++){
		if (!d[i])
			if (!topologicR(i)) return false;
	}
	return true;
}
int ve[210]={0},vl[210]={0};

int main(){
    string hname,name,name1;
    cin>>n>>m>>hname;
    mp1.insert(make_pair(hname,0));
    for (int i=1;i<n;i++){
        cin>>name>>happiness;
        mp1.insert(make_pair(name,i));
    }
    for (int i=0;i<m;i++)
    {
        cin>>name>>name1>>cost;
        mp[mp1[name]][mp1[name1]]=cost;
        //mp[mp1[name1]][mp1[name]]=cost;
    }
    if (!topoSort())
		cout<<"has circle!"<<endl;
	else{
		for (int i=0;i<n;i++)
			cout<<topoArray[i]<<" ";
		cout<<endl;
	}
    if (!topoSortR())
		cout<<"has circle!"<<endl;
	else{
		for (int i=0;i<n;i++)
			cout<<topoArrayR[i]<<" ";
		cout<<endl;
	}
	fill(ve,ve+n,0);
	fill(vl,vl+n,2100000000);
	ve[topoArray[0]]=0;
	for (int i=1;i<n;i++){
		for (int j=0;j<i;j++)
			if (mp[topoArray[j]][topoArray[i]]
			&&ve[topoArray[i]]<ve[topoArray[j]]+mp[topoArray[j]][topoArray[i]])
				ve[topoArray[i]]=ve[topoArray[j]]+mp[topoArray[j]][topoArray[i]];
	}
	for (int i=0;i<n;i++)
		cout<<ve[i]<<" ";
	cout<<endl;
	vl[topoArrayR[0]]=ve[topoArray[n-1]];
	for (int i=1;i<n;i++){
		for (int j=0;j<i;j++)
			if (mp[topoArrayR[i]][topoArrayR[j]]
			&&vl[topoArrayR[i]]>vl[topoArrayR[j]]-mp[topoArrayR[i]][topoArrayR[j]])
				vl[topoArrayR[i]]=vl[topoArrayR[j]]-mp[topoArrayR[i]][topoArrayR[j]];
	}
	for (int i=0;i<n;i++)
		cout<<vl[i]<<" ";
	cout<<endl;
	for (int i=0;i<n;i++)
		if (ve[topoArray[i]]==vl[topoArray[i]]) cout<<topoArray[i]<<endl;
	system("pause");
}
