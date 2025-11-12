#include <bits/stdc++.h>
using namespace std;
int n, m, K, f[10020][10005], aa[10005][10005], v[10020];
vector <int> a[10005];
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin >> n >> m >> K;
	for (int i = 1;i <= m;i++)
	{
		int u, v;
		cin >> u >> v;
		a[u].push_back(v);
		a[v].push_back(u);
		cin >> aa[u][v];
		aa[v][u] = aa[u][v];
	}
	for (int i = n+1;i <= K+n;i++)
	{
		cin >> f[i][0];
		for (int j = 1;j <= n;j++)
		{
			cin >> f[i][j];
			aa[i][j] = f[i][j];
		}
	}
	for (int k = n+1;k <= K+n;k++)
	{
		for (int i = 1;i <= n;i++)
		{
			for (int j = 1;j <= n;j++)
			{
				if (aa[i][j]>aa[i][k]+aa[k][j])
				{
					aa[i][j] = aa[i][k]+aa[k][j];
					v[k] = 1;
					for (int l = 1;l <= n;l++)
					{
						aa[k][l] -= f[i][l];
					}
				}
			}
		}
	}
	int ans = 0;
	for (int i = 1;i <= n;i++)
	{
		for (int j = i+1;j <= n;j++)
		{
			ans += aa[i][j];
		}
	}
	for (int i = n+1;i <= K+n;i++)
	{
		if (v[i] == 1)
		{
			ans += f[i][0];
		}
	}
	cout << ans;
	return 0;
}
//4 4 2
//1 4 6
//2 3 7
//4 2 5
//4 3 4
//1 1 8 2 4
//100 1 3 2 4
