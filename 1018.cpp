#include<iostream>
#include<vector>
#define maxint 2100000000
using namespace std;

int s[505];
vector<int> mp[505];
bool check[505];
int c,n,d,m,x,y,z;
int minans=maxint,mintake=maxint,mincarry=0;
vector<vector<int> > pre;

int dfs(int st,int de,int len,int take,int carry,int prep){
    if (len>minans) return 0;
    if (st==de){
        int tmp;
        if (len<minans){
            vector<int> p;
            pre.push_back(p);
            tmp=p.size()-1;
            pre[tmp].push_back(prep);
            minans=len;mintake=take;mincarry=carry;
            return tmp;
        }else if (len==minans&&take<mintake){
            vector<int> p;
            pre.push_back(p);
            tmp=p.size()-1;
            pre[tmp].push_back(prep);
            mintake=take;mincarry=carry;
            return tmp;
        }
        return 0;
    }
    for (int i=0;i<mp[st].size();i+=2){
        if (!check[mp[st][i]]){
            check[mp[st][i]]=1;
            int carryt,taket;
            if (carry>s[mp[st][i]]) carryt=carry-s[mp[st][i]];
            else {
                carryt=0;taket=taket+s[mp[st][i]]-carry;
            }
            pre[dfs(mp[st][i],de,len+mp[st][i+1],taket,carryt,st)].push_back(prep);
            check[mp[st][i]]=0;
        }
    }
}

int main(){
    cin>>c>>n>>d>>m;
    for (int i=1;i<=n;i++){
        cin>>s[i];
    }
    for (int i=0;i<m;i++){
        cin>>x>>y>>z;
        mp[x].push_back(y);
        mp[x].push_back(z);
        mp[y].push_back(x);
        mp[y].push_back(z);
    }
    fill(check,check+505,0);
    check[0]=1;
    vector<int> p;
    pre.push_back(p);
    dfs(0,d,0,0,0,0);
    cout<<mintake<<" 0";
    for (int i=pre[pre.size()-1].size()-1;i>=0;i--)
        cout<<"->"<<pre[pre.size()-1][i];
    cout<<" "<<mincarry<<endl;
    return 0;
}
