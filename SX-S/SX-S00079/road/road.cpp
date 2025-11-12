#include <bits/stdc++.h>
using namespace std;
const int N = 1e4+10, M = 1e6+10;
int n, m, k, fa[N], c[11], a[N][11], cnt;

struct bian {
	int u, v, w;
} b[M], mi[M], jl[N];

bool cmp(bian a, bian b) {
	return a.w < b.w;
}

int find(int x) {
	if (x == fa[x])
		return x;
	return fa[x] = find(fa[x]);
}

long long MST(int gs) {
	sort(mi + 1, mi + cnt + 1, cmp);
	long long ans = 0;
	for (int i = 1; i <= n + k; i++)
		fa[i] = i;
	for (int i = 1; i <= cnt; i++) {
		auto [u, v, w] = mi[i];
		int fu = find(u), fv = find(v);
		if (fu != fv) {
			ans += w;
			gs--;
			fa[fv] = fu;
			if (!gs)
				break;
		}
	}
	return ans;
}

void slove() {
	cin >> n >> m >> k;

	for (int i = 1; i <= m; i++) {
		int u, v, w;
		scanf("%d%d%d", &u, &v, &w);
//		cin >> u >> v >> w;
		b[i] = {u, v, w};
	}
	sort(b + 1, b + m + 1, cmp);
	long long ans = 0;
	for (int i = 1; i <= n; i++)
		fa[i] = i;
	for (int i = 1; i <= m; i++) {
		auto [u, v, w] = b[i];
		int fu = find(u), fv = find(v);
		if (fu != fv) {
			ans += w;
			fa[fv] = fu;
			mi[++cnt] = {u, v, w};
			jl[cnt] = {u, v, w};
		}
	}
	for (int i = 1; i <= k; i++) {
		scanf("%d", &c[i]);
//		cin >> c[i];
		for (int j = 1; j <= n; j++)
			scanf("%d", &a[j][i]);
//			cin >> a[j][i];
	}
//	cerr << ans << '\n';
	int ma = mi[cnt].w;
	for (int j = 1; j < (1 << k); j++) {
		long long res = 0, gs = 0;
		cnt = n - 1;
		for (int i = 1; i <= cnt; i++)
			mi[i] = jl[i];
		for (int i = 1; i <= k; i++) {
			if ((j >> (i - 1)) & 1) {
				gs++;
				res += c[i];
				for (int d = 1; d <= n; d++) {
					if (a[d][i] < ma) {
						mi[++cnt] = {n + i, d, a[d][i]};
					}
				}
			}
		}
		res += MST(n + gs - 1);
		ans = min(ans, res);
	}
	cout << ans;
}

signed main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	int T = 1;
//	cin >> T;
	while (T--)
		slove();

	return 0;
}