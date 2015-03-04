#include<iostream>
using namespace std;

struct Stu{
    int name;
    int value;
}s[1001],s1[1001];
int r[1001];

int main(){
    int n,m,nn,t;
    cin>>n>>m;nn=n;
    for(int i=0;i<n;i++){
        cin>>s1[i].value;
        s1[i].name=i;
    }
    for(int i=0;i<n;i++){
        cin>>t;
        s[i]=s1[t];
    }
    while(n>0){
        //cout<<n<<endl;
        int maxt=-1,maxp=0,ra=1;
        if (n!=1)
            ra=(n-1)/m+1+1;
        for (int i=n-1;i>=0;i--){
            r[s[i].name]=ra;
            if (maxt<s[i].value){maxt=s[i].value;maxp=i;}
            if (i%m==0){
                s1[i/m]=s[maxp];
                maxt=-1;maxp=0;
            }
        }
        for (int i=0;i<ra-1;i++){
            s[i]=s1[i];
        }
        n=ra-1;
    }
    cout<<r[0];
    for (int i=1;i<nn;i++)
        cout<<" "<<r[i];
    cout<<endl;
    return 0;
}
