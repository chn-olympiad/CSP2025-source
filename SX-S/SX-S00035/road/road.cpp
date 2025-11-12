#include <bits/stdc++.h>

#define endl '\n'
#define ll long long
#define pii pair<int,int>
#define fi first
#define se second
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define pq priority_queue
#define In(x) freopen(x".in","r",stdin)
#define Out(x) freopen(x".out","w",stdout)
#define File(x) (In(x),Out(x))
using namespace std;
const int N = 1e4+15, M = 2e6, K = 15;
const ll D = 2e4;
int n, m, k, c[K], a[K][N], fa[N], tot, cnt[K], rk[N];
ll ans;

ll e[M], g[N], h[K][N];

int read() {
	char ch = getchar();
	int res = 0;
	while (ch > '9' || ch < '0')
		ch = getchar();
	while (ch <= '9' && ch >= '0')
		res = res * 10 + (ch - '0'), ch = getchar();
	return res;
}

int getfa(int x) {
	if (x == fa[x])
		return x;
	else
		return fa[x] = getfa(fa[x]);
}

signed main() {
	File("road");
	n = read(), m = read(), k = read();
	for (int i = 1; i <= m; i++) {
		int u, v, w;
		u = read(), v = read(), w = read();
		e[i] = w * D * D + u * D + v;
	}
	for (int i = 1; i <= k; i++) {
		c[i] = read();
		for (int j = 1; j <= n; j++)
			a[i][j] = read();
	}
	for (int i = 1; i <= n; i++)
		fa[i] = i, rk[i] = 1;
	sort(e + 1, e + m + 1), tot = 0;
	for (int i = 1; i <= m; i++) {
		int u = e[i] / D % D, v = e[i] % D, w = e[i] / D / D;
		int x = getfa(u), y = getfa(v);
		if (x == y)
			continue;
		else {
			if (rk[x] > rk[y])
				swap(x, y);
			fa[x] = y, rk[y] += rk[x], g[++tot] = w * D * D + u * D + v, ans += w;
		}
		if (tot == n - 1)
			break;
	}
	for (int x = 1; x <= k; x++) {
		for (int i = 1; i < n; i++)
			e[i] = g[i];
		for (int i = 1; i <= n; i++)
			e[i + n - 1] = a[x][i] * D * D + (n + 1) * D + i;
		for (int i = 1; i <= n + 1; i++)
			fa[i] = i, rk[i] = 1;
		sort(e + 1, e + n + n), tot = 0;
		for (int i = 1; i < n + n; i++) {
			int u = e[i] / D % D, v = e[i] % D, w = e[i] / D / D;
			int xx = getfa(u), yy = getfa(v);
			if (xx == yy)
				continue;
			else {
				if (rk[xx] > rk[yy])
					swap(xx, yy);
				fa[xx] = yy, rk[yy] += rk[xx], ++tot;
			}
			if (u == n + 1)
				h[x][++cnt[x]] = w * D * D + (n + x) * D + v;
			if (tot == n)
				break;
		}
	}
	int V = 1 << k;
	for (int s = 1; s < V; s++) {
		ll sum = 0;
		int p = n, edg = 0;
		for (int x = 1; x <= k; x++) {
			if (s & (1 << (x - 1))) {
				sum += c[x];
				p++;
				for (int i = 1; i <= cnt[x]; i++)
					e[++edg] = h[x][i];
			}
		}
		for (int i = 1; i < n; i++)
			e[++edg] = g[i];
		for (int i = 1; i <= n + k; i++)
			fa[i] = i, rk[i] = 1;
		sort(e + 1, e + edg + 1), tot = 0;
		for (int i = 1; i <= edg; i++) {
			int u = e[i] / D % D, v = e[i] % D, w = e[i] / D / D;
			int x = getfa(u), y = getfa(v);
			if (x == y)
				continue;
			else {
				if (rk[x] > rk[y])
					swap(x, y);
				fa[x] = y, rk[y] += rk[x], sum += w, tot++;
			}
			if (sum >= ans)
				break;
			if (tot == p - 1) {
				ans = min(ans, sum);
				break;
			}
		}
	}
	cout << ans << endl;
	return 0;
}
/*
fc /W test.out test.ans
*/
