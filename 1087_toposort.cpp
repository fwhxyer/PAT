#include<iostream>
#include<string>
#include<map>
using namespace std;

map<string,int> mp1;
string mp2[210];
int mp[210][210]={0};
int topoArray[210]={0};
int topoSize=0;
int n,m,happiness,cost;
int d[210]={0};
bool topologic(int s){
    for (int i=0;i<n;i++)
		if (mp[s][i]){
			if (!d[i]) {
				d[i]=-1;
				if (!topologic(i)) return false;
				d[i]=1;
			}else if (d[i]<0)
				return false;
		}
    topoArray[topoSize--]=s;
    return true;
}
bool topologicR(int s){
    for (int i=0;i<n;i++)
		if (mp[i][s]){
			if (!d[i]) {
				d[i]=-1;
				if (!topologic(i)) return false;
				d[i]=1;
			}else if (d[i]<0)
				return false;
		}
    topoArray[topoSize--]=s;
    return true;
}

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
    topoSize=n-1;
	d[5]=1;
    if (!topologic(5))
		cout<<"has circle!"<<endl;
	else{
		for (int i=0;i<n;i++)
			cout<<topoArray[i]<<" ";
		cout<<endl;
	}
	system("pause");
}
