#include<bits/stdc++.h>
using namespace std;

const int M=1e6+101;

int n,m,k;
int c[15];
struct node
{
	int to;
	int nex;
	int len;
}e[M];
int head[M],cnt;

void add(int x,int y,int z)
{
	e[++cnt]=(node){y,head[x],z};
	head[x]=cnt;
}

signed main()
{
	
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for (int i=1;i<=m;i++)
	{
		int u,v,w;
		cin>>u>>v>>w;
		add(u,v,w);
		add(v,u,w);
	}
	int num1=0,num2=0;
	for (int i=1;i<=k;i++)
	{
		cin>>c[i];
		if (c[i]==0) num1++;
		for (int j=1;j<=n;j++)
		{
			int a;
			cin>>a;
			if (a==0) num2++;
			add(i+m,j,a);
			add(j,i+m,a);
		}
	}
	if (num1==k&&num2==k*m)
	{
		cout<<0;
		return 0;
	}
	
	
	return 0;
}
