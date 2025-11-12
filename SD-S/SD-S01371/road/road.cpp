#include<bits/stdc++.h>
using namespace std;
int s[10005][10005];
int n,m,k;
int c[15][10005];
queue<int>q;
int dis[10005];
int main()
{
	scanf("%d%d%d",&n,&m,&k);
	memset(s,127,sizeof s);
	memset(dis,127,sizeof dis);
	cout<<dis[1];
	for(int i=1;i<=m;i++)
	{
		int u,v,w;
		scanf("%d%d%d",&u,&v,&w);
		s[u][v]=s[v][u]=w;
	}
	for(int i=1;i<=k;i++)
	{
		scanf("%d",&c[i][0]);
		for(int j=1;j<=n;j++)
		{
			scanf("%d",&c[i][j]);
		}
	}
	for(int i=1;i<=k;i++)
	{
		for(int j=1;j<=n;j++)
		{
			for(int k2=1;k2<=n;k2++)
			{
				s[j][k2]=min(s[j][k2],c[i][j]+c[i][k2]);
			}
		}
	}
	q.push(1);
	dis[1]=0;
	while(!q.empty())
	{
		int now=q.top();
		q.pop();
		for(int i=1;i<=n;i++)
		{
			dis[i]=min(dis[i],s[now][i]+dis[now]);
		}
		
	}
}
