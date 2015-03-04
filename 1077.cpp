#include<iostream>
#include<string>
#include<sstream>
using namespace std;

string s[109];

int main(){
    int n;
    while (getline(cin,s[108])){
        stringstream ss;
        ss<<s[108];
        ss>>n;
        for (int i=0;i<n;i++)
            getline(cin,s[i]);
        int maxt=355;
        for (int k=0;k<n-1;k++){
            int i=s[k].length()-1,j=s[k+1].length()-1,t=0;
            while(i>=0&&j>=0&&s[k][i]==s[k+1][j]) {i--;j--;t++;}
            if (t<maxt) maxt=t;
        }
        if (maxt)
            cout<<s[0].substr(s[0].length()-maxt,maxt)<<endl;
        else
            cout<<"nai"<<endl;
    }
    return 0;
}
