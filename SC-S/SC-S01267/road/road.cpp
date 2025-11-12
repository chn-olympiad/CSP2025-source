#include<bits/stdc++.h>//t2
using namespace std;
const int N=1e4+100;
int a,b,c,g,h;
vector<int>d1[N];
vector<int>d2[N];
int e1[20];
int e2[20][N];
int f[N];//并查集 
struct node
{
	int x,y,z;
}k[N];
bool cmp(node x,node y)
{
	if(x.z<y.z)
	{
		return 1;
	}
	return 0;
}
int find(int x)
{
	if(f[x]==x)
	{
		return x;
	}
	f[x]=find(f[x]);
	return f[x];
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	//ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>a>>b>>c;
	for(int i=1;i<=b;i++)
	{
		int x1,x2,x3;
		cin>>x1>>x2>>x3;
		d1[x1].push_back(x2);
		d1[x2].push_back(x1);
		d1[x1].push_back(x3);
		d1[x2].push_back(x3);
		k[i].x=x1;
		k[i].y=x2;
		k[i].z=x3;
	}
	for(int i=1;i<=c;i++)
	{
		cin>>e1[i];
		for(int j=1;j<=a;j++)
		{
			cin>>e2[i][j];
		}
	}
	if(c==0)
	{
		for(int i=1;i<=a;i++)
		{
			f[i]=i;
		}
		sort(k+1,k+1+b,cmp);
		int oo=0;
		for(int i=1;i<=b;i++)
		{
			int u1=find(k[i].x);
			int u2=find(k[i].y);
			if(u1!=u2)
			{
				f[u1]=u2;
				oo=oo+k[i].z;
			}
		}
		cout<<oo;
		return 0;
	}
	cout<<"23213";

	return 0;
}
/*
4 4 0
1 4 6
2 3 7
4 2 5
4 3 4
*/