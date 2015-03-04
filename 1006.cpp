#include<iostream>
#include<string>
using namespace std;

struct Time{
    int hh,mm,ss;
    Time(){}
    Time(int a,int b,int c):hh(a),mm(b),ss(c){}
    bool operator<(const Time &t){
        if (hh<t.hh) return true;
        else if (hh>t.hh) return false;
        if (mm<t.mm) return true;
        else if (mm>t.mm) return false;
        if (ss<t.ss) return true;
        return false;
    }
    bool operator>(const Time &t){
        if (hh>t.hh) return true;
        else if (hh<t.hh) return false;
        if (mm>t.mm) return true;
        else if (mm<t.mm) return false;
        if (ss>t.ss) return true;
        return false;
    }
};

istream & operator >> (istream &o,Time &A)
{
    char c;
    o>>A.hh;
    o>>c;
    o>>A.mm;
    o>>c;
    o>>A.ss;
    return o;
}


string sname="",ename="",tn;
Time sTime(23,59,60),ts;
Time eTime(0,0,-1),te;
int main(){
    int n;
    cin>>n;
    for (int i=0;i<n;i++){
        cin>>tn>>ts>>te;
        if (ts<sTime) {sTime=ts;sname=tn;}
        if (te>eTime) {eTime=te;ename=tn;}
    }
    cout<<sname<<" "<<ename;
}
