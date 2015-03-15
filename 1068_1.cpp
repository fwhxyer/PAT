#include<algorithm>
#include<iostream>

using namespace std;

int face[10010];
bool couldm[110]={0};
bool couldmt[10010][110]={0};

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
    couldm[0]=1;
    for (int i=n-1;i>=0;i--){
        for (int j=m;j>=0;j--)
            if (j-face[i]>=0&&couldm[j-face[i]])
                couldmt[i][j]=1;
            else
                couldmt[i][j]=0;
        for (int j=m;j>=0;j--)
            if (j-face[i]>=0&&couldm[j-face[i]])
                couldm[j]=1;
        /*
        for (int j=0;j<=m;j++)
            cout<<couldm[j]<<" ";
        cout<<endl;
        */
    }
    /*
    cout<<endl;
    for (int i=n-1;i>=0;i--){
        for (int j=0;j<=m;j++)
            cout<<couldmt[i][j]<<" ";
        cout<<endl;
    }
    */
    if (!couldm[m])
        cout<<"No Solution";
    else
        for (int i=0;i<n;i++){
            if (couldmt[i][m]){
                cout<<face[i];
                if (m!=face[i]) cout<<" ";
                m-=face[i];
                if (m==0) break;
            }
        }
    cout<<endl;
    return 0;
}
