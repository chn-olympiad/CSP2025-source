#include <bits/stdc++.h>
using namespace std;

int f[10005][10005];

int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,q,u,v,w;
	int mi = 1e9;
	cin >> n >> m >> q;
	for(int i = 1;i <= n;i++)
		for(int j = 1;j <= n;j++)
			if(i != j)
				f[i][j] = 1e9;
	for(int i = 1;i <= m;i++)
	{
		cin >> u >> v >> w;
		f[u][v] = w;
		f[v][u] = w;
	}
	for(int k = 1;k <= n;k++)
	{
		for(int i = 1;i <= n;i++)
		{
			for(int j = 1;j <= n;j++)
			{
				if(k != i && k != j && i != j)
				{
					f[i][j] = min(f[i][j],f[i][k] + f[k][j]);
				}
			}
		}
	}
	int kl = 0;
	for(int i = 1;i <= n;i++)
	{
		kl = 0;
		for(int j = 1;j <= n;j++)
			kl += f[i][j];
		mi = min(mi,kl);
	}
	cout << mi;
	return 0;
}
