#include<algorithm>
#include<iostream>
#include<string>

using namespace std;

struct Stu{
    string name;
    string id;
    int grade;
};
bool cmp(Stu a,Stu b){
    if (a.grade>b.grade) return true;
    return false;
}
Stu st[100000];
int main(){
    int n,l,r;
    cin>>n;
    for (int i=0;i<n;i++){
        cin>>st[i].name>>st[i].id>>st[i].grade;
    }
    sort(st,st+n,cmp);
    cin>>l>>r;
    bool boo=false;
    for (int i=0;i<n;i++){
        if (st[i].grade<=r&&st[i].grade>=l){
            boo=true;
            cout<<st[i].name<<" "<<st[i].id<<endl;
        }
    }
    if (!boo) cout<<"NONE"<<endl;
    return 0;
}
