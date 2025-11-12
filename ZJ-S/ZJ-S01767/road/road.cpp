#include<bits/stdc++.h>
using namespace std;
vector<pair<int,int> > g[10005];
int n,m,k,ans=0;
int c[15][10005];
int h[15];
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
	{
		int u,v,w;
		cin>>u>>v>>w;
		if(k==0) ans+=w;
		g[u].push_back({v,w});
	}
	if(k!=0)
	{
		for(int i=1;i<=k;i++)
		{
			cin>>h[i];
			for(int j=1;j<=n;j++) cin>>c[i][j];
		}
		bool flag=0;
		for(int i=1;i<=n;i++)
		{
			if(h[i]!=0) flag=1;
			else
				for(int j=1;j<=n;j++)
					if(c[i][j]!=0) flag=1;
		}
		if(!flag)
			ans=0;
	} 
	cout<<ans;
	return 0;
}
