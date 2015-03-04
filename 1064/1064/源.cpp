#include<iostream>
#include<algorithm>
using namespace std;

int a[2020],t[2020];
int pow2[]={1,2,4,8,16,32,64,128,256,512,1024,2048};
int minmin(int a,int b){return a<b?a:b;}

void build(int l,int r,int c){
    if (l>r) return;
    int i=0,n=r-l+1;
    while (n>=pow2[i]-1) i++;
    i--;
    int mid=minmin(n-pow2[i]+1,pow2[i-1])+pow2[i]/2+l-1;
    t[c]=a[mid];
    build(l,mid-1,c*2);
    build(mid+1,r,c*2+1);
}

int main(){
    int n;
    cin>>n;
	for (int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+1+n);
    build(1,n,1);
	cout<<t[1];
	for (int i=2;i<=n;i++)
		cout<<" "<<t[i];
	cout<<endl;
	system("pause");
    return 0;
}
