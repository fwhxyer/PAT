#include<iostream>
#include<sstream>
#include<string>
#include<map>
using namespace std;

map<string,int> mp;

int main(){
    string s,t;
    getline(cin,s);
    for (int i=0;i<s.length();i++)
        if (!(s[i]>='a'&&s[i]<='z'||s[i]>='A'&&s[i]<='Z'||s[i]>='0'&&s[i]<='9')) s[i]=' ';
    stringstream ss;
    ss<<s;
    while (ss>>t){
        for (int i=0;i<t.size();i++)
            if (t[i]>='A'&&t[i]<='Z')
                t[i]+='a'-'A';
        if (mp.count(t))
            mp[t]++;
        else
            mp.insert(make_pair(t,1));
    }
    map<string,int>::iterator it;
    int maxt=-1;
    string ans;
    for (it=mp.begin();it!=mp.end();it++)
    if (it->second>maxt) {
        maxt=it->second;
        ans=it->first;
    }
    cout<<ans<<" "<<maxt<<endl;
    return 0;
}
