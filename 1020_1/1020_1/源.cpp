#include<iostream>

using namespace std;

struct Node{
	int l;
	int r;
	Node():l(0),r(0){}
};

int n;
int postorder[40];
int inorder[40];
Node node[40];
int q[40];

int findin(int x,int l=0,int r=n-1){
	for (int i=l;i<=r;i++)
		if (inorder[i]==x) return i;
	return -1;
}
int findpo(int x,int l=0,int r=n-1){
	for (int i=l;i<=r;i++)
		if (postorder[i]==x) return i;
	return -1;
}
void findhead(int m,int l,int r,int lp,int rp){
	if (l>=r) return;
	int mid=findin(postorder[m],l,r);
	int tmp;
	if (m==lp) return;
	if (findin(postorder[m-1],l,r)<mid){
		node[postorder[m]].l=postorder[m-1];
		findhead(m-1,l,mid-1,m-1-(mid-l),m-1);
		if (m-1-(mid-l)<lp) return;
		node[postorder[m]].r=postorder[m-1-(mid-l)];
		findhead(m-1-(mid-l),l,mid-1,lp,m-2-(mid-l));
	}else{
		node[postorder[m]].r=postorder[m-1];
		findhead(m-1,mid+1,r,m-1-(r-mid),m-1);
		if (m-1-(r-mid)<lp) return;
		node[postorder[m]].l=postorder[m-1-(r-mid)];
		findhead(m-1-(r-mid),l,mid-1,lp,m-2-(r-mid));
	}
}

int main(){
    cin>>n;
    for (int i=0;i<n;i++)
        cin>>postorder[i];
    for (int i=0;i<n;i++)
		cin>>inorder[i];

	findhead(n-1,0,n-1,0,n-1);

	q[0]=postorder[n-1];	
	int l=0,r=1;
	while(l<r){
		if (node[q[l]].l) q[r++]=node[q[l]].l;
		if (node[q[l]].r) q[r++]=node[q[l]].r;
		l++;
	}
	/*
	for (int i=1;i<=n;i++)
		cout<<node[i].l<<" "<<node[i].r<<endl;
	cout<<endl;
	*/
	cout<<q[0];
	for (int i=1;i<r;i++)
		cout<<" "<<q[i];
	cout<<endl;
	return 0;
}
