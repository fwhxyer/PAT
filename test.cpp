#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<string>
#include<map>
#include<algorithm>
#include<queue>
#include<stack>
#include<vector>
#include<set>
using namespace std;
//powered by fwhxyer

int main(){
    set<int> s1,s2,s3,s4;
    s1.insert(2);
    s1.insert(3);
    s2.insert(2);
    s2.insert(4);
    set_union(s1.begin(),s1.end(),s2.begin(),s2.end(),
              insert_iterator<set<int> >(s3,s3.end()));
    cout<<s3.size()<<endl;
}
