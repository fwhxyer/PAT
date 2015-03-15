#include<map>
#include<cstdio>
#include<vector>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

struct User{
    string id;
    int score[10]={0};
    int scoreall=0;
    int r=0;
    int cnt=0;
    User(){
        fill(score,score+10,0); id="";r=cnt=scoreall=0;
    }
};

vector<User> user;
map<string,User> mp;

bool cmp(User a,User b){
    if (a.scoreall>b.scoreall) return true;
    else if (a.scoreall==b.scoreall){
        if (a.cnt>b.cnt) return true;
        else if (a.cnt==b.cnt){
            if (a.id<b.id) return true;
        }
    }
    return false;
}
int isEqu(User a,User b){
    if (a.scoreall==b.scoreall)
       // if (a.cnt==b.cnt)
            return true;
    return false;
}

int p[6];

int main(){
    int n,k,m,t,sc;
    //cin>>n>>k>>m;
    scanf("%d %d %d",&n,&k,&m);
    for(int i=1;i<=k;i++)
        scanf("%d",&p[i]);
    string id;
    for(int i=0;i<m;i++){
        cin>>id;
        scanf("%d %d",&t,&sc);
        if (mp.count(id)){
            if (sc>0){
                if (mp[id].score[t]<sc)
                    mp[id].score[t]=sc;
            }
            else
                mp[id].score[t]=sc-1;
        }else{
            User us;
            us.id=id;
            if (sc>0)
                us.score[t]=sc;
            else
                us.score[t]=sc-1;
            //cout<<us.id<<endl;
            mp.insert(make_pair(id,us));
        }
    }
    map<string,User>::iterator it;
    for (it=mp.begin();it!=mp.end();it++){
        user.push_back(it->second);
    }
    for (int i=0;i<user.size();i++){
        user[i].scoreall=user[i].cnt=0;
        for (int j=1;j<=k;j++){
            if (user[i].score[j]>0){
                user[i].scoreall+=user[i].score[j];
            }
            if (user[i].score[j]==p[j]) user[i].cnt++;
        }
    }
    /*
    for (int i=0;i<user.size();i++){
        printf("%d %s %d",user[i].r,user[i].id,user[i].scoreall);
        for (int j=1;j<=k;j++)
            printf(" %d",user[i].score[j]);
        printf("\n");
    }*/
    sort(user.begin(),user.end(),cmp);
    user[0].r=1;
    for (int i=1;i<user.size();i++)
        if (isEqu(user[i-1],user[i]))
            user[i].r=user[i-1].r;
        else
            user[i].r=i+1;
    for (int i=0;i<user.size();i++){
        bool t=0;
        if (user[i].scoreall==0){
            t=1;
            for (int j=1;j<=k;j++){
                if (user[i].score[j]==-1){
                    t=0;
                    break;
                }
            }
        }
        if (t) continue;
        printf("%d %s %d",user[i].r,user[i].id.c_str(),user[i].scoreall);
        for (int j=1;j<=k;j++)
            if (user[i].score[j]>0)
                printf(" %d",user[i].score[j]);
            else if (user[i].score[j]==0)
                printf(" -");
            else if (user[i].score[j]<0)
                printf(" 0");
        printf("\n");
    }
    return 0;
}

