#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;


int a[]={1,2,3,4,5,6,6,6,6,8,8,9,9,10};

int main(){
    int n=14;
    cout<<equal_range(a,a+n,7).first-a<<" "<<equal_range(a,a+n,7).second-a<<endl;
    return 0;
}
