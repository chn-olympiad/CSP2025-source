#include <iostream>
#include <algorithm>
using namespace std;
#define int long long
const int M = 1e6 + 3;
int n, m, k, f[M], ans;
struct res{
	int u, v, w;
	bool operator < (const res &a) const { return w < a.w; }
} r[M];
int find(int x) {
	if (x == f[x]) return x;
	return f[x] = find(f[x]);
}
signed main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	scanf("%lld %lld %lld", &n, &m, &k);
	for (int i = 1; i <= n; i++) f[i] = i;
	for (int i = 1; i <= m; i++) scanf("%lld %lld %lld", &r[i].u, &r[i].v, &r[i].w);
	sort(r + 1, r + 1 + m);
	for (int i = 1; i <= m; i++) {
		if (find(r[i].u) != find(r[i].v)) {
			ans += r[i].w; f[find(r[i].u)] = find(r[i].v);
		}
	}
	printf("%lld\n", ans);
	return 0;
}
