#include<iostream>
#include<cstdio>
using namespace std;

int a[1000010],b[1000010];
int mint(int a,int b){return a<b?a:b;}

int main(){
    int n,m,ans;
    scanf("%d",&n);
    for (int i=0;i<n;i++)
        scanf("%d",&a[i]);
    scanf("%d",&m);
    for (int i=0;i<m;i++)
        scanf("%d",&b[i]);
    int t=(m+n+1)/2-1;
    int k=0,i=0,j=0,anst=0;
    while (k<t){
        if (i<n&&j<m){
            if (a[i]<b[j]) i++;
            else j++;
        }else
        if (i>=n){
            j++;
        }else{
            i++;
        }
        k++;
    }
    if (i<n&&j<m){
        anst=mint(a[i],b[j]);
        if (a[i]<b[j]) i++;
        else j++;
    }else
    if (i>=n){
        anst=b[j];
        j++;
    }else{
        anst=a[i];
        i++;
    }
    printf("%d\n",anst);
    return 0;
}
