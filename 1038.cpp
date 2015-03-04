#include<algorithm>
#include<iostream>
#include<sstream>
#include<string>
#include<stack>
using namespace std;

pair<string,int> a[10010];
stack<pair<string,int> > sta;
int minn(int a,int b){return a<b?a:b;}
int main(){
    int n;
    cin>>n;
    string s;
    int j=0,cnt,maxt=0,maxp;
    for (int i=0;i<n;i++){
        cin>>s;
        cnt=0;
        for (int i=0;i<s.length();i++){
            if (s[i]=='0') cnt++;
            else break;
        }
        if (cnt!=s.length()){
            stringstream ss;
            if (cnt>maxt) {maxt=cnt;maxp=j;}
            a[j].first=s;
            ss<<s;
            ss>>a[j++].second;
            //cout<<a[j-1].first<<" "<<a[j-1].second<<endl;
        }
    }
    if (maxt) {
        cout<<a[maxp].second;
        a[maxp]=a[j-1];
        j--;
    }
    sort(a,a+j);
    for (int i=0;i<j;i++){
        if (a[i].first==a[i+1].first.substr(0,minn(a[i].first.length(),a[i+1].first.length()))
            &&a[i+1].first.length()>a[i].first.length()
            &&a[i+1].first[a[i].first.length()]<)
            sta.push(a[i]);

        cout<<a[i].first;
    }
    cout<<endl;
    return 0;
}
