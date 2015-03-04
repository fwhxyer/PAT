#include<iostream>
#include<algorithm>
using namespace std;

int a[100010],b[100010];
int main(){
    int n,m;
    cin>>n;
    for (int i=0;i<n;i++)
        cin>>a[i];
    cin>>m;
    for (int i=0;i<m;i++)
        cin>>b[i];
    long long ans=0,ans1=0;
    sort(a,a+n);
    sort(b,b+m);
    int i=0;
    int t=n<m?n:m;
    while (i<t&&a[i]*b[i]>0){
        ans+=a[i]*b[i];i++;
    }
    if (i!=t){
        i=n-1;
        int j=m-1;
        while (i>=0&&j>=0&&a[i]*b[j]>0){
            ans+=a[i]*b[j];i--;j--;
        }
    }
    i=n-1;
    int j=m-1;
    while (i>=0&&j>=0&&a[i]*b[j]>0){
        ans1+=a[i]*b[j];i--;j--;
    }
    if (i!=-1&&j!=-1){
        int i=0;
        int t=n<m?n:m;
        while (i<t&&a[i]*b[i]>0){
            ans1+=a[i]*b[i];i++;
        }
    }
    cout<<(ans>ans1?ans:ans1)<<endl;
    return 0;
}
