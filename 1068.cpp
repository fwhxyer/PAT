#include<algorithm>
#include<iostream>

using namespace std;

int face[10010];
int couldm[110]={0};
vector<int> pre[110];

void printans(int a){
    if (couldm[a]){
        printans(couldm[a]);
        cout<<" "<<a-couldm[a];
    }else
        cout<<a-couldm[a];
}

int main(){
    int n,m;
    cin>>n>>m;
    for (int i=0;i<n;i++)
        cin>>face[i];
    sort(face,face+n);
    fill(couldm,couldm+m+1,-1);
    couldm[0]=0;
    for (int i=0;i<n;i++){
        for (int j=0;j<=m;j++)
            cout<<couldm[j]<<" ";
        cout<<endl;
        for (int j=m;j>=0;j--)
            if (couldm[j]!=-1&&j+face[i]<=m)
                //if (couldm[j+face[i]]==-1)//||couldm[j+face[i]]>i)
                {
                    couldm[j+face[i]]=j;
                    pre[j].push_back(face[i]);
                }
    }
    if (couldm[m]==-1)
        cout<<"No Solution";
    else
        printans(m);
    cout<<endl;
    return 0;
}
