#include<iostream>
#include<string>
using namespace std;

int main(){
    string s;
    getline(cin,s);
    int l=s.length(),p,q,maxt=0;
    for (int i=0;i<l;i++){
        for (int j=l-1;j>=0;j--){
            if (s[i]==s[j]){
                p=i;q=j;
                while (p<q&&s[p]==s[q]) {p++;q--;}
                if (p>=q)
                {
                    if (j-i+1>maxt){
                        maxt=j-i+1;
                    }
                    break;
                }
            }
        }
    }
    cout<<maxt<<endl;
    return 0;
}
