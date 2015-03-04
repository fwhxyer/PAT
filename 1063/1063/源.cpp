#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;

vector<int> v[55];

int main(){
    int n,m,t,a,b;
    //cin>>n;
    scanf("%d",&n);
    for (int i=0;i<n;i++)
    {
        //cin>>m;
        scanf("%d",&m);
        for (int j=0;j<m;j++)
        {
            //cin>>t;
            scanf("%d",&t);
            v[i].push_back(t);
        }
        sort(v[i].begin(),v[i].end());
		for (int j=v[i].size()-1;j>0;j--)
			if (v[i][j]==v[i][j-1]) v[i].erase(v[i].begin()+j);
    }
    //cin>>m;
    scanf("%d",&m);
    for (int i=0;i<m;i++)
    {
        //cin>>a>>b;
        scanf("%d %d",&a,&b);
		a--;b--;
		if (v[a].size()==0&&v[b].size()==0) {printf("100.0%%\n");continue;}
        vector<int > t;
        int aa=0,bb=0;
        while (aa<v[a].size()&&bb<v[b].size()){
            if (v[a][aa]<v[b][bb])
                t.push_back(v[a][aa++]);
            else
                t.push_back(v[b][bb++]);
        }
        while (aa<v[a].size()) t.push_back(v[a][aa++]);
        while (bb<v[b].size()) t.push_back(v[b][bb++]);
        int ans=0;
        for (int j=1;j<t.size();j++){
            if (t[j]==t[j-1]) ans++;
        }
        double ansd=(100.0*ans/double(v[a].size()+v[b].size()-ans));
        printf("%0.1lf%%\n",ansd);
    }
	system("pause");
    return 0;
}
