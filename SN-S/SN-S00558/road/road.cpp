#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef double db;
typedef pair<int, ll> pii;

const int N = 10100;
int n, m, q, fa[N];
struct Node {
	int u, v;
	ll w;
	bool operator < (const Node& A) const {
		return w < A.w;
	}
} a[N * N];

int findset(int x) { return x == fa[x] ? x : (fa[x] = findset(fa[x])); }

int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdin);
	scanf("%d%d%d", &n, &m, &q);
	for (int i = 1; i <= n; i++) fa[i] = i;
	for (int i = 1; i <= m; i++)
		scanf("%d%d%lld", &a[i].u, &a[i].v, &a[i].w);
	int len = m;
	for (int i = 1; i <= q; i++) {
		ll c;
		scanf("%lld", &c);
		for (int j = 1; j <= n; j++) {
			ll w;
			scanf("%lld", &w);
			if (i == j) continue;
			a[++len].u = i, a[len].v = j, a[len].w = c + w;
		}
	}
	sort(a + 1, a + len + 1);
	int p = 0;
	ll ans = 0;
	for (int i = 1; i <= len; i++) {
		if (p == n) break;
		int x = findset(a[i].u), y = findset(a[i].v);
		if (x != y) {
			fa[x] = y;
			ans += a[i].w;
			++p;
		}
	}
	printf("%lld\n", ans);
	return 0;
}
