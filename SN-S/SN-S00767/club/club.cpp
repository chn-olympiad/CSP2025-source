//韩泽熙  SN-S00767  西安辅轮中学 
#include <bits/stdc++.h>
using namespace std;
int sss,n,q=0;
long long anser=0;
long long a[100003][3]={};
int g[3]={0,0,0};
int dfs(int d,int v,long long w)
{
	if(g[0]>q || g[2]>q || g[1]>q)
	{
		return 0;
	}
	if(d==n)
	{
		anser=max(anser,w);
	}
	else
	{
		g[0]++;
		dfs(d+1,1,w+a[d+1][0]);
		g[0]--;
		g[1]++;
		dfs(d+1,2,w+a[d+1][1]);
		g[1]--;
		g[2]++;
		dfs(d+1,3,w+a[d+1][2]);
		g[2]--;
	}
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>sss;
	for(int i=0;i<sss;i++)
	{
		cin>>n;
		a[n+1][1]=0;
		a[n+1][2]=0;
		a[n+1][3]=0;
		for(int j=1;j<=n;j++)
		{
			cin>>a[j][0]>>a[j][1]>>a[j][2];
		}
		q=n/2;
		g[0]=1;
		dfs(1,1,a[1][0]);
		g[0]=0;
		g[1]=1;
		dfs(1,2,a[1][1]);
		g[1]=0;
		g[2]=1;
		dfs(1,3,a[1][2]);
		g[2]=0;
		cout<<anser<<endl;
		anser=0;
	}
	
}
