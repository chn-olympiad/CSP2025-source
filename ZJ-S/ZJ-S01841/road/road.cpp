#include <bits/stdc++.h>
#define int long long

using namespace std;

const int N = 10010, M = 1000010, K = 20;

int n, m, k;
int cnt[K];
pair<int, int> a[K][N];
int p[N], w[K], tmp[K];
struct Edge
{
	int a, b, c;
	bool operator < (const Edge& W) const
	{
		return c < W.c;
	}
} edge[M];
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;

int find(int x) { return x == p[x] ? x : p[x] = find(p[x]); }

signed main()
{
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	
	cin >> n >> m >> k;
	for (int i = 1; i <= m; i ++ ) cin >> edge[i].a >> edge[i].b >> edge[i].c;
	for (int i = 1; i <= k; i ++ )
	{
		cin >> w[i];
		for (int j = 1; j <= n; j ++ ) cin >> a[i][j].first, a[i][j].second = j;
		sort(a[i] + 1, a[i] + 1 + n);
		tmp[i] = w[i] + a[i][1].first;
		cnt[i] = 2;
	}
	
	sort(edge + 1, edge + 1 + m);
	for (int i = 1; i <= n; i ++ ) p[i] = i;
	int res = 0;
	for (int i = 1; i <= m; i ++ )
	{
		for (int j = 1; j <= k; j ++ )
			if (cnt[j] <= n && a[j][cnt[j]].first + tmp[j] <= edge[i].c)
				q.push({a[j][cnt[j]].first + tmp[j], j});
		while (q.size())
		{
			int w = q.top().first, j = q.top().second; q.pop();
			int u = find(a[j][1].second), v = find(a[j][cnt[j]].second);
			if (u == v)
			{
				cnt[j] ++ ;
				if (cnt[j] > n) continue;
				if (a[j][cnt[j]].first + tmp[j] <= edge[i].c)
					q.push({a[j][cnt[j]].first + tmp[j], j});
				continue;
			}
			res += w;
			p[u] = v;
			tmp[j] = 0;
			cnt[j] ++ ;
			if (cnt[j] > n) continue;
			if (a[j][cnt[j]].first + tmp[j] <= edge[i].c)
				q.push({a[j][cnt[j]].first + tmp[j], j});
		}
		int u = find(edge[i].a), v = find(edge[i].b);
		if (u == v) continue;
		p[u] = v;
		res += edge[i].c;
	}
	
	cout << res << '\n';
	
	return 0;
}
