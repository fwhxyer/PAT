#include<iostream>
using namespace std;

int a[1000010],b[1000010];
int main(){
    int n,m;
    cin>>n;
    for (int i=0;i<n;i++)
        cin>>a[i];
    cin>>m;
    for (int i=0;i<m;i++)
        cin>>b[i];
    int k=0,i=0,j=0;
    while(k<(m+n+1)/2-2){
        k++;
        if (i<n-1&&j<m-1&&a[i]<b[j]) i++;
        else if (i<n-1&&j<m-1&&a[i]>=b[j]) j++;
        else if (i>=n) j++;
        else if (j>=m) i++;
    }
    int ans;
    //cout<<i<<" "<<j<<" "<<k<<endl;
    if (i<n&&j<m&&a[i]<b[j]) ans=a[++i];
    else if (i<n&&j<m&&a[i]>=b[j]) ans=b[++j];
    else if (i>=n) ans=b[++j];
    else if (j>=m) ans=a[++i];
    cout<<ans<<endl;
    return 0;
}
