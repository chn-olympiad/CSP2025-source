# include<bits/stdc++.h>

using namespace std;

const int N = 2e6 + 10, M = 20;
const long long inf = 1e18;
priority_queue<pair<long long , int>, vector<pair<long long ,int>>, greater<pair<long long , int > > > q;
vector<pair<long long, long long>> s[N];
pair<long long, pair<long long , long long>> tr[N], s2[N];
long long dis[N];
int n, m, k, vis[N], f[N];
pair<long long , int> g[N];
long long c[M], a[M][N], tot;

int find(int u)
{
	if(f[u] == u) return u;
	return f[u] = find(f[u]);
}

void init()
{
	for(int j = 1;j <= n;j ++ ) f[j] = j;
	int len = m;
	sort(s2 + 1, s2 + len + 1);
	for(int j = 1;j <= len;j ++ )
	{
		long long u = s2[j].second.first, v = s2[j].second.second;
		if(find(u) != find(v))
		{
			tr[ ++ tot] = s2[j];
			f[find(u)] = find(v);
		}
	}
	return;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	cin >> n >> m >> k;
	for(int i = 1, u, v, w;i <= m;i ++ )
	{
		cin >> u >> v >> w;
		s2[ ++ tot] = {w, {u, v}};
	}
	for(int i = 1;i <= k;i ++ )
	{
		cin >> c[i];
		for(int j = 1;j <= n;j ++ ) cin >> a[i][j]; 
	}
	tot = 0;
	init();
	int all = (1 << k) - 1;
	long long res = inf;
	for(int i = 0;i <= all;i ++ )
	{
		for(int j = 1;j <= n + k;j ++ ) f[j] = j;
		int len = 0; long long ans = 0;
		for(int j = 1;j <= tot;j ++ ) s2[ ++ len] = tr[j];
		for(int j = 1;j <= k;j ++ )
		{
			if(i >> (j - 1) & 1)
			{
				ans += c[j];
				for(int l = 1;l <= n;l ++ ) 
				{
					s2[ ++ len] = {a[j][l], {n + j, l}};
				}
			}
		}
		sort(s2 + 1, s2 + len + 1);
		for(int j = 1;j <= len;j ++ )
		{
			long long w = s2[j].first, u = s2[j].second.first, v = s2[j].second.second;
			if(find(u) != find(v))
			{
				ans += w;
				f[find(u)] = find(v);
			}
		}
		res = min(res, ans);
	}
	cout << res << "\n";
	return 0;
}