#include<iostream>
using namespace std;

struct Node{
	int point;
	Node* left;
	Node* right;
	Node(){point=0;left=right=NULL;}
	Node(int t){point=t;left=right=NULL;}
};

int n;
int postorder[40];
int inorder[40];

int findin(int x,int l=0,int r=n){
	for (int i=l;i<r;i++)
		if (inorder[i]==x) return i;
	return -1;
}

void dfs(int l,int r,int &m,Node &h){
	if (l>=r||m<0) return;
	int filter=findin(postorder[m]);
	int fnd=findin(postorder[m-1]);
	Node*h11=new Node;
	h11->point=postorder[m-1];
	if (fnd<filter) {
		h.left=h11;
		dfs(l,filter-1,--m,*h11);
	}else{
		h.right=h11;
		dfs(filter+1,r,--m,*h11);
	}
}

void bfs(Node h){
	if (h.left)
		cout<<" "<<(*h.left).point;
	if (h.right)
		cout<<" "<<(*h.right).point;
	if (h.left)
		bfs(*h.left);
	if (h.right)
		bfs(*h.right);
}

int main(){
    cin>>n;
    for (int i=0;i<n;i++)
        cin>>postorder[i];
    for (int i=0;i<n;i++)
		cin>>inorder[i];
	Node head(postorder[n-1]);
	//for (int i=n-1;i>=0;i--)
	int m=n;
	while (--m>=0)
		dfs(0,n-1,m,head);
	cout<<head.point;
	bfs(head);
	system("pause");
	return 0;
}
