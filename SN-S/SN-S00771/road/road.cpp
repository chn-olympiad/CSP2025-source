#include<bits/stdc++.h>
using namespace std;
int n,m,k,a[10005][10005];
int ans[500005];
int w,u,v,tot;
int t;

int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	
	
	cin>>n>>m>>k;
	
	for(int i=1;i<=m;i++)
	{
		cin>>u>>v>>w;
		a[u][v]=w;
		a[v][u]=w;
	}
	
	for(int i=1;i<=n;i++)
	{
		for(int j=i;j<=n;j++)
		{
			if(i!=j)	ans[0]+=a[i][j];
		}
	}
	
	for(int i=1;i<=k;i++)
	{
		tot=0;
		cin>>w;
		for(int j=1;j<=n;j++)
		{
			cin>>u;
			for(int x=1;x<=n;x++)
			{
				if(x!=j&&a[x][j]>u+w)
				{
					tot=1;
					a[x][j]=u;
					a[i][x]=u;
				}
				
			}
			if(tot==1)
			{
				t++;
				for(int x=1;x<=n;x++)
				{
					for(int y=x;y<=n;y++)
					{
						ans[t]+=a[x][y];
					}
				}
				ans[t]+=w;
			}
			
		}
	}
	
	sort(ans,ans+t);
	cout<<ans[0];
	return 0;
}
