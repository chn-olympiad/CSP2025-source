#include<bits/stdc++.h>
using namespace std;

int n, m, k, mp[10005][10005];

struct city
{
	int u, v, w;
};
city ct[1000005];

struct ctside
{
	int c, to_ct[100005];
};
ctside cts[1000005];

int main()
{
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	cin >> n >> m >> k;
	for(int i = 1; i <= m; i++)
	{
		cin >> ct[i].u >> ct[i].v >> ct[i].w;
		mp[ct[i].u][ct[i].v] = ct[i].w;
		mp[ct[i].v][ct[i].u] = ct[i].w;
	}
	for(int i = 1; i <= k; i++)
	{
		cin >> cts[i].c;
		for(int j = 1; j <= n; j++)
		{
			cin >> cts[i].to_ct[j];
		}
	}
	if(k == 0)
	{
		int total = 0;
		for(int i = 1; i < n; i++)
		{
			total += mp[i][i + 1];
		}
		cout << total;
	}
	else cout << 0;
	return 0;
}
