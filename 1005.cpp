#include<iostream>
#include<sstream>
#include<string>
using namespace std;

string n2e[10]={"zero","one","two","three","four","five","six","seven","eight","nine"};

int main(){
    string s;
    while(cin>>s){
        int sum=0;
        for (int i=0;i<s.length();i++)
        {
            sum+=s[i]-'0';
        }
        string sums;
        stringstream ss;
        ss<<sum;
        ss>>sums;
        for (int i=0;i<sums.length()-1;i++){
            cout<<n2e[sums[i]-'0']<<" ";
        }
        cout<<n2e[sums[sums.length()-1]-'0']<<endl;
    }
    return 0;
}
