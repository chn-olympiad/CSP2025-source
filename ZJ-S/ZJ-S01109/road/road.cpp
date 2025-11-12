#include <bits/stdc++.h>
#define int long long
using namespace std;
const int maxn = 2e6 + 20, maxm = 1e4 + 20;
int n, m, k, ans, c[15][maxm], cnt, tot, sum, nw;
struct edge {int x, y, z;}e[maxn], E[maxn];
int fa[maxm];
int find(int x) {
	if(fa[x] == x) return x;
	return find(fa[x]);
}
void merge(int x, int y, int z) {
	int fx = find(x), fy = find(y);
	fa[fx] = fy;
	sum += z;
}
signed main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n >> m >> k;
	for(int i = 1; i <= m; i++) {
		int x, y, z; cin >> x >> y >> z;
		e[i] = {x, y, z};
	}
	for(int i = 1; i <= k; i++) {
		for(int j = 0; j <= n; j++) cin >> c[i][j];
	}
	ans = 1e18;
	for(int S = 0; S < (1 << k); S++) {
		sum = 0;
		tot = m, nw = n;
		for(int i = 1; i <= m; i++) E[i] = e[i];
		for(int i = 1; i <= k; i++) {
			if(S & (1 << (i - 1))) {
				nw++;
				sum += c[i][0];
				for(int j = 1; j <= n; j++) {
					E[++tot] = {nw, j, c[i][j]};
				}
			}
		}
		sort(E + 1, E + 1 + tot, [&](edge a, edge b) {
			return a.z < b.z;
		});
		for(int i = 1; i <= nw; i++) fa[i] = i;
		cnt = 0;
		for(int i = 1; i <= tot; i++) {
			int x = E[i].x, y = E[i].y, z = E[i].z;
			if(find(x) == find(y)) continue;
			merge(x, y, z);
			if(cnt == nw - 1) break;
		}
		ans = min(ans, sum);
	}
	cout << ans << "\n";
	return 0;
}
