#include<iostream>
#include<cmath>
using namespace std;

bool isPrime(int a){
    for (int i=2;i<sqrt(a);i++)
        if (a%i==0) return false;
    return true;
}
int main(){
    int n;
    cin>>n;
    cout<<n<<"=";
    int i=2,cnt;
    bool flag=false;
    if (n==0||n==1) cout<<n;
    while (n>1){
        cnt=0;
        while (n%i==0){
            cnt++;
            n/=i;
        }
        if (cnt){
            if (!flag) flag=true;
            else cout<<"*";
        }
        if (cnt==1)
            cout<<i;
        else if (cnt>1)
            cout<<i<<"^"<<cnt;
        while (!isPrime(++i));
    }
    cout<<endl;
    return 0;
}
