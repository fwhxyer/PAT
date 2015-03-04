#include<iostream>
#include<algorithm>
#include<string>
using namespace std;

struct Stu{
    string name;
    int local;
    int score;
    int frank;
    int lrank;
}s[310],fs[30010];

bool cmp(Stu a,Stu b){
    if (a.score>b.score) return true;
    else if (a.score==b.score)
        if (a.name<b.name) return true;
    return false;
}

int main(){
    int n,m[101],fm=0;
    cin>>n;
    for (int i=0;i<n;i++){
        cin>>m[i];
        for (int j=0;j<m[i];j++){
            cin>>s[j].name>>s[j].score;
            s[j].local=i+1;
        }
        sort(s,s+m[i],cmp);
        s[0].lrank=1;
        for (int j=1;j<m[i];j++){
            if (s[j].score==s[j-1].score) s[j].lrank=s[j-1].lrank;
            else s[j].lrank=j+1;
        }
        for (int j=0;j<m[i];j++)
            fs[fm+j]=s[j];
        fm+=m[i];
    }
    sort(fs,fs+fm,cmp);
    fs[0].frank=1;
    for (int i=1;i<fm;i++){
        if (fs[i].score==fs[i-1].score) fs[i].frank=fs[i-1].frank;
        else fs[i].frank=i+1;
    }
    cout<<fm<<endl;
    for (int i=0;i<fm;i++)
        cout<<fs[i].name<<" "<<fs[i].frank<<" "<<fs[i].local<<" "<<fs[i].lrank<<endl;
    return 0;
}
