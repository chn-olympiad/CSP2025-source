#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e4 + 20, M = 2e6 + 5; //注意M不一定够 

bool tpA = 1;
int n, m, K, c[15], a[15][N], ans = 1e18, tot;
int fa[N];
struct EDGE {
	int u, v, w;
	bool operator < (const EDGE &u) const {
		return w > u.w;
	}
}e[M];
int find(int x) {
	if (x == fa[x]) return x;
	return fa[x] = find(fa[x]);
}
priority_queue < EDGE > q;

int minitree(int cnt) {
	int res = 0;
	for (int i = 1; i <= tot; i++)
		q.push(e[i]);
	for (int i = 1; i <= n + cnt; i++)
		fa[i] = i;
	while (q.size()) {
		EDGE now = q.top(); q.pop();
		int x = now.u, y = now.v;
		x = find(x), y = find(y);
		if (x != y) {
			res += now.w;
			fa[find(x)] = find(y);
		}
	}
	return res;
}

signed main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> n >> m >> K;
	for (int i = 1; i <= m; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		e[++tot] = {u, v, w};
	}
	for (int i = 1; i <= K; i++) {
		cin >> c[i];
		for (int j = 1; j <= n; j++) 
			cin >> a[i][j];
		if (c[i]) tpA = 0;
	}
	if (tpA) {
		for (int i = 1; i <= K; i++)
			for (int j = 1; j <= n; j++)
				if (a[i][j] == 0) {
					for (int k = 1; k <= n; k++)
						if (k != j) e[++tot] = {j, k, a[i][k]};
					break;
				}
		cout << minitree(0) << '\n';
		exit(0);
	}
	for (int t = 0; t < (1 << K); t++) {
		int cnt = 0, sum = 0;
		for (int i = 1; i <= K; i++)
			if (t & (1 << (i - 1))) {
				for (int j = 1; j <= n; j++)
					e[++tot] = {n + i, j, a[i][j]};
				cnt++, sum += c[i];
			}
		ans = min(ans, sum + minitree(cnt));
		tot -= cnt * n;
	}
	cout << ans << '\n';
	return 0;
}
