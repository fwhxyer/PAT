#include<iostream>
#include<queue>
using namespace std;


int main(){
    priority_queue<int> d;
    d.insert(1);
    d.insert(2);
    d.insert(3);
    d.insert(4);
    d.insert(5);
    cout<<d.top()<<endl;
    d.pop();
    cout<<d.top()<<endl;
}
