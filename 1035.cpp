#include<iostream>
#include<string>
using namespace std;

int main(){
    int n;
    string account[1010],password[1010],account_mod[1010],password_mod[1010];
    while (cin>>n){
        for (int i=0;i<n;i++)
            cin>>account[i]>>password[i];
        int count=0;
        for (int i=0;i<n;i++){
            bool flag=false;
            for (int j=0;j<password[i].length();j++)
                if (password[i][j]=='1'||password[i][j]=='0'||password[i][j]=='l'||password[i][j]=='O'){
                    flag=true;
                    if (password[i][j]=='1') password[i][j]='@';
                    if (password[i][j]=='0') password[i][j]='%';
                    if (password[i][j]=='l') password[i][j]='L';
                    if (password[i][j]=='O') password[i][j]='o';
                }
            if (flag) {
                account_mod[count]=account[i];
                password_mod[count]=password[i];
                count++;
            }
        }
        if (count){
            cout<<count<<endl;
            for (int i=0;i<count;i++){
                cout<<account_mod[i]<<" "<<password_mod[i]<<endl;
            }
        }
        else if (n==1)
            cout<<"There is "<<n<<" account and no account is modified"<<endl;
        else
            cout<<"There are "<<n<<" accounts and no account is modified"<<endl;
    }
    return 0;
}
