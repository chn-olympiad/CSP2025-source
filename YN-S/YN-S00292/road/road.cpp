#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
const int N = 1e4 + 5;
const int M = 1e6 + 5;
const int K = 15;
const ll inf = 1e18;

struct edge {
	int u, v;
	ll val;
} e[M + K * N];
int n, m, k;
int cnt;
int fa[N + K];
ll ans = inf;
ll c[K], a[K][N];
int idx;
bool b[K + N];

bool reimu(edge x, edge y) {
	return x.val < y.val;
}

void init() {
	sort(e + 1, e + cnt + 1, reimu);
	for (int i = 1; i <= n + k; i++) {
		fa[i] = i;
	}
	return;
}

int find(int x) {
	if (x == fa[x])
		return x;
	return fa[x] = find(fa[x]);
}

void merge(int x, int y) {
	fa[x] = y;
	return;
}

void kruskal(int now) {
	init();
	for (int i = 1; i <= now; i++)
		b[i + n] = false;
	ll tot = 0;
	int num = 0;
	for (int i = 1; i <= cnt; i++) {
		int u = e[i].u, v = e[i].v;
		ll val = e[i].val;
		int x = find(u), y = find(v);
		if (x == y)
			continue;
		tot += val;
		if (u > n && !b[u]) {
			b[u] = true;
			tot += c[u - n];
		} else if (v > n && !b[v]) {
			b[v] = true;
			tot += c[v - n];
		} else
			num++;
		merge((int)max(x, y), (int)min(x, y));
		if (num >= n - 1)
			break;
	}
	ans = min(ans, tot);
	return;
}

int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	scanf("%d%d%d", &n, &m, &k);
	for (int i = 1; i <= n; i++) {
		int u, v;
		ll val;
		scanf("%d%d%lld", &u, &v, &val);
		e[++cnt].u = u;
		e[cnt].v = v;
		e[cnt].val = val;
	}
	ans = inf;
	kruskal(0);
	for (int i = 1; i <= k; i++) {
		scanf("%lld", &c[i]);
		for (int j = 1; j <= n; j++) {
			scanf("%lld", &a[i][j]);
			e[++cnt].u = n + i;
			e[cnt].v = j;
			e[cnt].val = a[i][j];
		}
		kruskal(i);
	}
	printf("%lld", ans);
	return 0;
}