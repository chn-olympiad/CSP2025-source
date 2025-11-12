#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

typedef long long ll;

const int N = 1e4 + 5;

int n, m, k, cnt;
vector<pair<int, ll>> e[N];
ll c[15], a[15][N];
bool chk[N], vis[N];
bool sigma_sub1 = 1;

inline void add(int u, int v, ll w)
{
	e[u].emplace_back(v, w);
}

inline void sub1();
inline ll dfs(int);

int main()
{
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	scanf("%d %d %d", &n, &m, &k);
	for (int i = 1; i <= m; i++)
	{
		int u, v; ll w;
		scanf("%d %d %lld", &u, &v, &w);
		add(u, v, w), add(u, v, w);
	}
	
	for (int i = 1; i <= k; i++)
	{
		scanf("%d", c + i), sigma_sub1 &= (!c[i]);
		for (int j = 1; j <= n; j++)
			scanf("%d", a[i] + j), sigma_sub1 &= (!a[i][j]);
	}
	for (int i = 1; i <= k; i++)
		chk[c[i]] = 1;
	if(sigma_sub1)
	{
		sub1();
	}
	else
	{
		sub1();
	}
	
	return 0;
}

inline void sub1()
{
	vis[1] = 1;
	printf("%lld", dfs(1));
}

inline ll dfs(int u)
{
	ll res = 0;
	for (auto par : e[u])
	{
		int v = par.first;
		ll w = par.second;
		
		if(vis[v])
			continue;
		if ((chk[v] || chk[u]) && sigma_sub1)
			w = 0;
		else
		{
			if (chk[v])
				w = min(w, a[v][u]);
			if (chk[u])
				w = min(w, a[u][v]);
		} 
		vis[v] = 1;
		res += w + dfs(v);
	}
	return res;
}
