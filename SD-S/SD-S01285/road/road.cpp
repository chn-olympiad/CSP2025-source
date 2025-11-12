#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
const int M = 1e6 + 10;
struct Edge { int u, v, w; }e[M];
const int N = 1e4 + 10, NN = 2e5 + 10;
int f[N];
inline int find(int x)
{
	if (f[x] != x) f[x] = find(f[x]);
	return f[x];
}
Edge cho[N], now[NN];
int tot;
typedef long long ll;
int a[20][N], c[20];
int main()
{
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout); 
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, m, k;
	cin >> n >> m >> k;
	for (int i = 1; i <= m; i++)
		cin >> e[i].u >> e[i].v >> e[i].w;
	sort(e + 1, e + m + 1, [](Edge A, Edge B) { return A.w < B.w; });
	for (int i = 1; i <= n; i++) f[i] = i;
	ll ans = 0;
	for (int i = 1; i <= m; i++)
	{
		int u = e[i].u, v = e[i].v, w = e[i].w;
		int fu = find(u), fv = find(v);
		if (fu == fv) continue;
		f[fu] = fv, cho[++tot] = e[i], ans += w;
	}
	ll minn = ans;
	for (int i = 1; i <= k; i++)
	{
		cin >> c[i];
		for (int j = 1; j <= n; j++) cin >> a[i][j];
	}
	for (int S = 1; S < (1 << k); S++)
	{
		for (int i = 1; i <= n + k; i++) f[i] = i;
		for (int i = 1; i < n; i++) now[i] = cho[i];
		ll sum = 0;
		int cnt = tot, dot = n;
		for (int j = 1; j <= k; j++)
			if (S & (1 << j - 1))
			{
				sum += c[j], dot++;
				for (int i = 1; i <= n; i++) now[++cnt] = {j + n, i, a[j][i]};
			}
		sort(now + 1, now + cnt + 1, [](Edge A, Edge B) { return A.w < B.w; });
		for (int i = 1; i <= cnt; i++)
		{
			int u = now[i].u, v = now[i].v, w = now[i].w;
			int fu = find(u), fv = find(v);
			if (fu == fv) continue;
			f[fu] = fv, sum += w, dot--;
			if (sum >= minn || dot == 1) break;
		}
		minn = min(minn, sum);
	}
	cout << minn << "\n";
	return 0;
}

