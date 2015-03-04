#include<iostream>
#include<stack>
using namespace std;

int a[1005];
stack<int> s;

int main(){
    int m,n,k;
    cin>>m>>n>>k;
    for (int i=0;i<k;i++){
        while (!s.empty()) s.pop();
        for (int i=0;i<n;i++)
            cin>>a[i];
        int j=1;
        bool ans=true;
        for (int i=0;i<n;i++){
            while (j<=a[i]) s.push(j++);
            if (s.size()>m) {ans=false;break;}
            //cout<<s.top()<<endl;
            if (s.top()==a[i]) {s.pop();}
            else {ans=false;break;}
        }
        if (ans) cout<<"YES"; else cout<<"NO";
        cout<<endl;
    }
    return 0;
}
