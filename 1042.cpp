#include<iostream>
#include<sstream>
#include<string>
using namespace std;

const int maxn=54;
string getStatusCard(int n){
    string s;
    switch (n/13){
    case 0:
        s="S";
        break;
    case 1:
        s="H";
        break;
    case 2:
        s="C";
        break;
    case 3:
        s="D";
        break;
    default:
        s="J";
    }
    stringstream ss;
    ss<<s;
    ss<<n%13+1;
    ss>>s;
    return s;
}
int change[maxn];
int order[maxn];
int order1[maxn];

int main(){
    int n;
    while (cin>>n){
        for (int i=0;i<maxn;i++){
            cin>>change[i];
            order[i]=i;
        }
        for (int j=0;j<n;j++){
            for (int i=0;i<maxn;i++){
                order1[change[i]-1]=order[i];
            }
            for (int i=0;i<maxn;i++){
                order[i]=order1[i];
            }
        }
        for (int i=0;i<maxn-1;i++){
            cout<<getStatusCard(order[i])<<" ";
        }
        cout<<getStatusCard(order[maxn-1])<<endl;
    }
    return 0;
}
