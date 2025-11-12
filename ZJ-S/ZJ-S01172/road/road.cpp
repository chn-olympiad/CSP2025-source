#include <bits/stdc++.h>
using namespace std;

#define int long long
const int N = 1e4 + 20;
const int M = 1e6 + 20;
const int K = 20;
int n, m, k, ans;
int c[K], v[K][N];
int fa[N];
struct Node
{
	int x, y, w;
	bool operator < (const Node &B) const
	{
		return w < B.w;
	}
}a[M], b[M * 2];
int find(int x)
{
	if (fa[x] == x) return fa[x] = x;
	return fa[x] = find(fa[x]);
}
void merge(int x, int y)
{
	int rx = find(x), ry = find(y);
	fa[rx] = ry;
}
int kruskal()
{
	sort (a + 1, a + m + 1);
	int cnt = 0, sum = 0;
	for (int i = 1; i <= m; i++)
	{
		int x = a[i].x, y = a[i].y, w = a[i].w;
		if (find(x) == find(y)) continue;
		merge(x, y);
		cnt++;
		sum += w;
		if (cnt == n - 1) break;
	}
	return sum;
}
bool flag[K];
int kruskal2()
{
	int mm = m, nn = n;
	for (int i = 1; i <= mm; i++)
		b[i] = a[i];
	int sum = 0, cnt = 0;
	for (int i = 1; i <= k; i++)
	{
		if (flag[i])
		{
			sum += c[i];
			nn++;
			for (int j = 1; j <= n; j++)
				b[++mm] = {nn, j, v[i][j]};
		}
	}
	for (int i = 1; i <= nn; i++)
		fa[i] = i;
	sort (b + 1, b + mm + 1);
	for (int i = 1; i <= mm; i++)
	{
		int x = b[i].x, y = b[i].y, w = b[i].w;
		if (find(x) == find(y)) continue;
		merge(x, y);
		cnt++;
		sum += w;
		if (cnt == nn - 1) break;
	}
	return sum;
}
void dfs(int step)
{
	if (step > k)
	{
		ans = min(ans,  kruskal2());
		return;
	}
	flag[step] = 1;
	dfs(step + 1);
	flag[step] = 0;
	dfs(step + 1);
}

signed main()
{
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n >> m >> k;
	for (int i = 1; i <= n; i++)
		fa[i] = i;
	for (int i = 1; i <= m; i++)
		cin >> a[i].x >> a[i].y >> a[i].w;
	for (int i = 1; i <= k; i++)
	{
		cin >> c[i];
		for (int j = 1; j <= n; j++)
			cin >> v[i][j];
	}
	ans = kruskal();
	if (k == 0)
	{
		cout << ans << endl;
		return 0;
	}
	dfs(1);
	cout << ans << endl;
	return 0;
}
