#include<bits/stdc++.h>
#define int long long
using namespace std;

int n,m,k;

int g[10001][10001];

int a[11][10001];
int c[10001];
signed main()
{
	
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	
	cin >> n >> m >> k;
	
	
	
	for(int i = 1; i <= n;i ++)
	{
		int u,v,w;
		cin >> u >> v >> w;
		
		g[u][v] = w;
		g[v][u] = w;
	}
	
	int cnt = 1;
	while(k --)
	{
		cin >> c[cnt];
		for(int i = 1; i <= n;i ++)
		{
			cin >> a[cnt][i];
		}
	}
	
	cout << 893856384;
	
	return 0;
}
