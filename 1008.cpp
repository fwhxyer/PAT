#include<iostream>
using namespace std;

int main(){
    int n;
    while (cin>>n){
        int level=0;
        int prev_level=0;
        int mov=0,time=0;
        for (int i=0;i<n;i++){
            cin>>level;
            mov=level-prev_level;
            if (mov>0) time+=mov*6;
            else
                time+=-mov*4;
            time+=5;
            prev_level=level;
        }
        cout<<time<<endl;

    }
    return 0;
}
