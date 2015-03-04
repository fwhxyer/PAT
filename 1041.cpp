#include<iostream>
#include<cstring>
using namespace std;

int a[100010];
int b[10010];

int main(){
    int n;
    while (cin>>n){
        memset(b,0,sizeof(b));
        for (int i=0;i<n;i++){
            cin>>a[i];
            b[a[i]]++;
        }
        bool flag=false;
        for (int i=0;i<n;i++)
            if (b[a[i]]==1) {
                cout<<a[i]<<endl;
                flag=true;
                break;
            }
        if (!flag) cout<<"None"<<endl;
    }
    return 0;
}
