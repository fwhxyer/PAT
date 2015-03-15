#include<iostream>
#include<algorithm>
using namespace std;

int pow2[]={1,2,4,8,16,32,64,128,256,512,1024};
int a[110],b[110],c[110];
int n;
bool anst=0;

bool check(){
    for (int i=0;i<n;i++)
        if (a[i]!=b[i]) return false;
    return true;
}
void mergesort(int t){
    if (t>n/2) return;
    //for (int i=0;i<n-1;i++) cout<<a[i]<<" ";
    //cout<<a[n-1]<<endl;
    for (int i=0;i<n;i+=pow2[t])
        sort(a+i,a+(i+pow2[t]<n?i+pow2[t]:n));
    if (!anst){
        if (check()){
            anst=1;
            mergesort(t+1);
            cout<<"Merge Sort"<<endl;
            for (int i=0;i<n-1;i++) cout<<a[i]<<" ";
            cout<<a[n-1]<<endl;
        }else
            mergesort(t+1);
    }
}

int main(){
    cin>>n;
    for (int i=0;i<n;i++){
        cin>>a[i];c[i]=a[i];
    }
    for (int i=0;i<n;i++)
        cin>>b[i];
    for (int i=1;i<n;i++){
        int j,t=a[i];
        for (j=i-1;j>=0;j--){
            if (a[j]>t)
                a[j+1]=a[j];
            else break;
        }
        a[j+1]=t;
        if (anst){
            cout<<"Insertion Sort"<<endl;
            for (int i=0;i<n-1;i++) cout<<a[i]<<" ";
            cout<<a[n-1]<<endl;
            break;
        }
        else if (check()){
            anst=1;
        }
    }
    if (!anst){
        for (int i=0;i<n;i++)
            a[i]=c[i];
        mergesort(1);
    }
    return 0;
}
