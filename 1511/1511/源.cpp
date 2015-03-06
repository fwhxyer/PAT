#include<cstdio>
#include<iostream>

using namespace std;

int available=0;
int listSpace[3000000];
int listPi[3000000];

int list[1000001];
int list2[1000001];

int New()
{
	listSpace[available]=0;
	listPi[available]=-1;
	return available++;
}

void pb(int a,int data)
{
	while (listPi[a]!=-1) a=listPi[a];
	listPi[a]=available++;
	a=listPi[a];
	listSpace[a]=data;
	listPi[a]=-1;
}

int find(int a,int b)
{
	for (int i=0;i<b;i++)
	{
		a=listPi[a];
	}
	return listSpace[a];
}

int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		available=0;
		int nv,ne,m;
		scanf("%d%d",&nv,&ne);
		for (int i=0;i<=nv;i++)
			list[i]=New();
		for (int i=0;i<=nv;i++)
			list2[i]=New();
		for (int i=0;i<ne;i++)
		{
			int a,b,c;
			scanf("%d%d%d",&a,&b,&c);
			pb(list[a],b);
			pb(list[a],c);
			pb(list2[b],a);
			pb(list2[b],c);
		}
		/*
		scanf("%d",&m);
		pb(list[m],150);
		pb(list[m],160);
		pb(list[m],170);
		pb(list[m],180);
		pb(list[m+1],1150);
		pb(list[m+1],1160);
		pb(list[m+1],1170);
		pb(list[m+1],1180);
		printf("%d\n",find(list[m],1));
		printf("%d\n",find(list[m],2));
		printf("%d\n",find(list[m],3));
		printf("%d\n",find(list[m],4));
		printf("%d\n",find(list[m+1],1));
		printf("%d\n",find(list[m+1],2));
		printf("%d\n",find(list[m+1],3));
		printf("%d\n",find(list[m+1],4));
		*/
	}
	system("pause");
	return 0;
}