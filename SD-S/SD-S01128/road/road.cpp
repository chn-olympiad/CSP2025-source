#include<bits/stdc++.h>
using namespace std;

const int N = 1100100;
int n, m, k, f[N];
array<int, 3> e[N];
long long ans = 1ll << 60;

int find(int x) {
	return f[x] == x ? x : f[x] = find(f[x]);
}

inline void solve() {
	scanf("%d%d%d", &n, &m, &k);
	for (int i = 1; i <= m; i++) 
		scanf("%d%d%d", &e[i][1], &e[i][2], &e[i][0]);
	for (int i = 1; i <= k; i++) {
		int c;
		scanf("%d", &c);
		int mnid = m + (i - 1) * n + 1;
		for (int j = 1; j <= n; j++) {
			scanf("%d", &e[m + (i - 1) * n + j][0]);
			e[m + (i - 1) * n + j][1] = n + i;
			e[m + (i - 1) * n + j][2] = j;
			if (e[m + (i - 1) * n + j][0] < e[mnid][0]) 
				mnid = m + (i - 1) * n + j;
		}
		e[mnid][0] += c;
	}
	m += n * k;
	sort(e + 1, e + m + 1);
	for (int i = 0; i < 1 << k; i++) {
		for (int j = 1; j <= n + k; j++) 
			f[j] = j;
		long long res = 0;
		for (int j = 1; j <= m; j++) {
			int u = e[j][1], v = e[j][2], w = e[j][0];
			if (u > n && !(i >> (u - n - 1) & 1)) 
				continue;
			int fu = find(u), fv = find(v);
			if (fu != fv) {
				res += w;
				f[fu] = fv;
			}
		}
		ans = min(ans, res);
	}
	printf("%lld\n", ans);
}

int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	int t = 1;
//	scanf("%d", &t);
	while (t--) {
		solve();
	}
	return 0;
}
