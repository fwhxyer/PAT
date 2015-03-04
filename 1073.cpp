#include<iostream>
#include<sstream>
#include<string>
using namespace std;

int main(){
    char c;
    while(cin>>c){
        if (c=='-') cout<<c;
        string s;
        cin>>s;
        int i=s.length()-1,t;
        while (s[i]!='E') i--;
        c=s[i+1];
        stringstream ss;
        ss<<s.substr(i+2,s.length()-i-2);
        ss>>t;
        s=s.substr(0,i);
        //cout<<s<<"E"<<c<<t<<endl;
        if (c=='+'){
            int i=0;
            while (i<s.length()&&s[i]!='.') i++;
            s=s.substr(0,i)+s.substr(i+1,s.length()-i-1);
            t+=i;
            i=0;
            while (t--){
                if (i<s.length()) cout<<s[i++];
                else cout<<"0";
            }
            if (i<s.length()) cout<<'.';
            while (i<s.length()) cout<<s[i++];
            cout<<endl;
        }
        else if (c=='-'){
            if (t==0) cout<<s;
            else{
                cout<<"0.";t--;
                while (t--){
                    cout<<"0";
                }
                int i=0;
                while (i<s.length()&&s[i]!='.') i++;
                s=s.substr(0,i)+s.substr(i+1,s.length()-i-1);
                cout<<s;
            }
            cout<<endl;
        }
    }
    return 0;
}
