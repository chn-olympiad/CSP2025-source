#include <bits/stdc++.h>
using namespace std;

int n, m, k, p, u, v, w, cnt, tot, f[10001], a[11][10001];
long long ans;
unordered_map <int, int> mp;

struct edge { int u, v, w; };
vector <edge> e;

int find(int x) { return (f[x] == x ? x : f[x] = find(f[x])); }

inline bool cmp(edge& a, edge& b) { return a.w < b.w; }

int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
 	freopen("road.in", "r", stdin); freopen("road.out", "w", stdout);
	cin >> n >> m >> k, memset(a, 0x3f, sizeof a);
	for (int i=1; i<=m; ++i) cin >> u >> v >> w, e.push_back({u, v, w});
	for (int i=1; i<=n; ++i) f[i] = i;
	for (int i=1; i<=k; ++i)
	{
		cin >> a[i][0];
		for (int j=1; j<=n; ++j) cin >> a[i][j];
	}
	if (k)
	{
		for (int i=1; i<=n; ++i)
		{
			for (int j=i+1; j<=n; ++j)
			{
				int tmp = 2e9+1;
				for (int t=1; t<=k; ++t) tmp = min(tmp, a[t][i] + a[t][j] + a[t][0]); 
				e.push_back({i, j, tmp});
			}
		}
	}
	sort(e.begin(), e.end(), cmp);
	for (auto t : e)
	{
		if (tot == n-1) break;
		int ru = find(t.u), rv = find(t.v);
		if (ru == rv) continue;
		f[ru] = rv, ans += (long long)t.w, ++ tot;
	}
	cout << ans << endl;
 	return 0;
}

