#include<iostream>
#include<cstdio>
#include<queue>
using namespace std;

queue<int> q[1010];
int qout[1010];
int cost[1010];
bool busy[1010];
int ans[1010];
int n,m,nk,nq;

bool isqempty(){
    for (int i=0;i<n;i++)
        if (q[i].size()<m) return true;
    return false;
}
int qempty(){
    int mint=1010,minp=0;
    for (int i=0;i<n;i++)
        if (q[i].size()<mint) {
            mint=q[i].size();
            minp=i;
        }
    return minp;
}

int main(){
    fill(busy,busy+1010,0);
    fill(ans,ans+1010,-1);
    cin>>n>>m>>nk>>nq;
    for(int i=0;i<nk;i++)
        cin>>cost[i];
    int cus=0,time=0,nnk=nk;
    while (time<540){
		for (int j=0;j<2;j++){
			while (nk&&isqempty()){
				q[qempty()].push(cus++);
				nk--;
			}
			for (int i=0;i<n;i++){
				if (!busy[i]&&!q[i].empty()){
					qout[i]=time+cost[q[i].front()];
					busy[i]=true;
				}else if(busy[i]){
					if (time==qout[i]){
						qout[i]=0;
						busy[i]=false;
						ans[q[i].front()]=time;
						q[i].pop();
					}
				}
			}
		}
        time++;
    }
	for (int i=0;i<n;i++)
		if (busy[i]){
			ans[q[i].front()]=qout[i];
		}
    int t;
    for (int i=0;i<nq;i++){
        cin>>t;
        if (ans[t-1]==-1)
            printf("Sorry\n");
        else
            printf("%02d:%02d\n",ans[t-1]/60+8,ans[t-1]%60);
    }
    return 0;
}
