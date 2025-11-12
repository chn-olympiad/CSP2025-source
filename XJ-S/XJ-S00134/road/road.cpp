#include <bits/stdc++.h>
using namespace std;
int n,m,k,q=1,h=0,p=1;
int u[10000],v[10000],w[10000],c[10000],a[10000][10000],b[10000][10000],d[10000];
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
	{
		cin>>u[i]>>v[i]>>w[i];
	}
	for(int i=1;i<=k;i++)
	{
		cin>>c[i];
		for(int j=1;j<=n;j++)
		{
			cin>>a[i][j];
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			b[i][j]=1000000;
		}
	}
	for(int i=2;i<=n;i++)
	{
		for(int j=1;j<=p;j++)
		{
			for(int x=1;x<=k;x++)
			{
				b[i][j]=min(b[i][j],a[x][i]+a[x][j]+c[x]);
			}
			for(int x=1;x<=n;x++)
			{
				if(i==u[x]&&j==v[x])
				{
					b[i][j]=min(b[i][j],w[x]);
				}
				else
				{
					if(i==v[x]&&j==u[x])
					{
						b[i][j]=min(b[i][j],w[x]);
					}
				}
			}
		}
		p++;
	}
	p=1;
	for(int i=2;i<=n;i++)
	{
		for(int j=1;j<=p;j++)
		{
			d[q]=b[i][j];
			q++;
		}
		p++;
	}
	sort(d+1,d+1+q);
	for(int i=2;i<=n;i++)
	{
		h+=d[i];
	}
	cout<<h;
	return 0; 
} 

