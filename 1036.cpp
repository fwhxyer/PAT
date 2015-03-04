#include<iostream>
#include<string>
using namespace std;

struct Stu{
    string name,id,sex;
    int grade;
};
int main(){
    int n;
    Stu m,f,tmp;
    m.name=f.name="Absent";
    m.grade=101;
    f.grade=-1;
    cin>>n;
    for (int i=0;i<n;i++){
        cin>>tmp.name>>tmp.sex>>tmp.id>>tmp.grade;
        if (tmp.sex=="M"){
            if (m.grade>tmp.grade){
                m=tmp;
            }
        } else {
            if (f.grade<tmp.grade){
                f=tmp;
            }
        }
    }
    cout<<f.name;
    if (f.name!="Absent") cout<<" "<<f.id;
    cout<<endl<<m.name;
    if (m.name!="Absent") cout<<" "<<m.id;
    if (m.name!="Absent"&&f.name!="Absent") cout<<endl<<f.grade-m.grade<<endl;
    else cout<<endl<<"NA"<<endl;
    return 0;
}
