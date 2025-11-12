#include <bits/stdc++.h>
using namespace std;
long long n=0,m=0,k=0;
long long g[10010][10010];
long long c[11]; 
long long a[11][10010]; //新乡镇与城市通路的费用 
bool road[10010][10010]; //两点之间是否通路 
long long price[10010][10010];
bool jisuan[10010][10010];
long long ans=0;
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m >> k;
	for(int i=1;i<=m;i++)
	{
		int u,v,w;
		cin >> u >> v >> w;
			g[u][v]=w;
			g[v][u]=w;
			road[u][v]=true;
			road[v][u]=true;
			ans+=w;
	 } 
	for(int i=1;i<=k;i++)
	{
		cin >> c[i];
		for(int j=1;j<=n;j++)
		{
			cin >> a[i][j];
		 } 
	}
	cout << ans;
	return 0;
	}	
	
	
	
 
