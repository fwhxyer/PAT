#include<iostream>
#include<string>
using namespace std;

int main(){
    string s;
    while(cin>>s){
        int n=s.length()+2;
        int n1=n/3;
        int n2=n-2*n1;
        for (int i=0;i<n1-1;i++)
        {
            cout<<s[i];
            for (int i=0;i<n2-2;i++)
                cout<<" ";
            cout<<s[n-3-i]<<endl;
        }
        cout<<s.substr(n1-1,n2)<<endl;
    }
    return 0;
}
