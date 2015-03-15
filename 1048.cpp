#include<algorithm>
#include<iostream>

using namespace std;

int v[100010];
int check[1010];

int main(){
    int n,m;
    fill(check,check+1010,0);
    cin>>n>>m;
    for (int i=0;i<n;i++){
        cin>>v[i];
        check[v[i]]++;
    }
    sort(v,v+n);
    bool t=1;
    for (int i=0;i<n;i++){
        check[v[i]]--;
        if (m>=v[i]&&check[m-v[i]]){
            cout<<v[i]<<" "<<m-v[i]<<endl;
            t=0;
            break;
        }else if (m<v[i]) {
            cout<<"No Solution"<<endl;
            t=0;
            break;
        }
        check[v[i]]++;
    }
    if (t)
        cout<<"No Solution"<<endl;
    return 0;
}
