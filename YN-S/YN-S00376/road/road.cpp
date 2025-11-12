#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e6 + 39;
int n, e, m;
int f[maxn];

struct st {
	int u, v, Next;
	ll w;
} a[maxn];
ll W[12][maxn];
ll V[12][maxn];
int vis[maxn];
ll ans;
int c[12];
int cnt;

int F(int x) {
	if (f[x] == x) {
		return x;
	} else {
		f[x] = F(f[x]);
	}
}

bool cmp(st a, st b) {
	return a.w < b.w;
}

void K() {
	for (int i = 1; i <= e; i++) {

		int u = a[i].u;
		int v = a[i].v;
		ll w = a[i].w;
		int fu = F(u);
		int fv = F(v);

		if (fu != fv) {
			ans += w;
			f[fu] = fv;
			cnt++;
			vis[i] = 1;
		}

		if (cnt == n - 1) {
			return;
		}
	}
}

int main () {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	scanf("%d %d %d", &n, &e, &m);

	for (int i = 1; i <= n; i++) {

		f[i] = i;
	}

	for (int i = 1; i <= e; i++) {

		scanf("%d %d %lld", &a[i].u, &a[i].v, &a[i].w);
	}

	sort(a + 1, a + e + 1, cmp);

	for (int i = 1; i <= m; i++) {

		scanf("%lld", &W[i][0]);

		for (int j = 1; j <= n; j++) {

			scanf("%lld", &W[i][j]);
		}
	}

	K();

	for (int i = e; i >= 1; i--) {

		if (vis[i] == 0) {
			continue;
		}

		int u = a[i].u;
		int v = a[i].v;
		ll w = a[i].w;
		ll M = LONG_LONG_MAX;

		for (int j = 1; j <= m; j++) {

			M = min(M, W[j][u] + W[j][v]);
		}

		for (int j = 1; j <= m; j++) {

			if (M == W[j][u] + W[j][v] ) {
				if (w > W[j][u] + W[j][v] + W[j][0] ) {
					ans -= (w - W[j][u] - W[j][v] - W[j][0]);

				}

			}
		}
	}

	printf("%lld", ans);
	return 0;
}
