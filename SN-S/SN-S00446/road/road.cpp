//µ­³þÜ²
#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 1e4 + 10, M = 1e6 + 10, K = 15;
int TTT = 1, n, m, k, ans = 1e16, f[N], b[M], c[N], vis[N], p[K][N];
struct node {int u, v, w;}a[M];

bool cmp(node x, node y) {return x.w < y.w;}
int find(int x) {return f[x] == x ? x : f[x] = find(f[x]);}

void solve()
{
	sort(a + 1, a + 1 + m, cmp);
	int res = 0;
	for(int i = 1; i <= n; i++) f[i] = i;
	for(int i = 1; i <= m; i++)
	{
		int u = a[i].u, v = a[i].v, w = a[i].w;
		u = find(u), v = find(v);
		if(u != v) f[u] = v, res += w;
	}
	cout << res;
}

void mian()
{
	cin >> n >> m >> k; bool g = true;
	for(int i = 1; i <= n; i++) f[i] = i;
	for(int i = 1; i <= m; i++) cin >> a[i].u >> a[i].v >> a[i].w;
	for(int i = 1; i <= k; i++)
	{
		cin >> c[i], g &= (c[i] == 0);
		for(int j = 1; j <= n; j++) cin >> p[i][j], g &= (p[i][j] == 0);
	}
	if(g) {cout << 0; return;}
	solve();
}

signed main()
{
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	ios::sync_with_stdio(false); cin.tie(0);
//	cin >> TTT;
	while(TTT--) mian();
	return 0;
}

