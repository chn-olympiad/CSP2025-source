#include<bits/stdc++.h>
using namespace std;

long long n, m, k, mx[10001], fa[10001], ans, sum = 0, cnt = 0;

struct edge
{
	int u, v, w;
}ez[101000001];

bool cmp(edge x, edge y)
{
	return x.w < y.w;
}

int find(int x)
{
	if(fa[x] != x)
	{
		fa[x] = find(fa[x]);
	}
	return fa[x];
}

int main()
{
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	cin >> n >> m >> k;
	for(int j = 1; j <= n; j++)
	{
		fa[j] = j;
	}
	for(int i = 1; i <= m; i++)
	{
		int u, v, w;
		cin >> u >> v >> w;
		ez[++sum].u = u;
		ez[sum].v = v;
		ez[sum].w = w;
	}
	for(int i = 1; i <= k; i++)
	{
		int c, a[10001];
		cin >> c;
		for(int j = 1; j <= n; j++)
		{
			cin >> a[j];
		}
		for(int j = 1; j <= n; j++)
		{
			for(int l = j+1; l <= n; l++)
			{
				ez[++sum].u = j;
				ez[sum].v = l;
				ez[sum].w = a[j] + a[l] + c;
			}
		}
	}
	sort(ez+1, ez+sum+1, cmp);
	for(int i = 1; i <= sum; i++)
	{
		if(cnt == n-1)
		{
			break;
		}
		if(find(ez[i].u) != find(ez[i].v))
		{
			ans += ez[i].w;
			fa[find(ez[i].v)] = find(ez[i].u);
		}
	}
	cout << ans;
}
