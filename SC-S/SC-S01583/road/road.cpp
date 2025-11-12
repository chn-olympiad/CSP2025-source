#include<bits/stdc++.h>
using namespace std;
const long long N = 1e6+10;
const long long M = 1e3+10;
const long long inf = 0x3f3f3f3f3f;
struct edge {
	long long u, v, w;
};
edge a[N];
long long mp[M][M];
long long n, m, k;
long long s[N];
long long fa[M];
long long find(long long x) {
	if (fa[x] == x)return x;
	return fa[x] = find(fa[x]);
}
bool cmp(edge x, edge y) {
	return x.w < y.w;
}
int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	ios::sync_with_stdio(), cin.tie(0), cout.tie(0);
	cin >> n >> m >> k;
	for (long long i = 1; i <= n; i++) {
		fa[i] = i;
		for (long long j = 1; j <= n; j++) {
			mp[i][j] = inf;
		}
	}
	for (long long i = 1; i <= m; i++) {
		long long u, v, w;
		cin>>u>>v>>w;
		mp[u][v] = min(mp[u][v], w);
		mp[v][u] = mp[u][v];
	}
	long long kk = k;
	while (kk--) {
		long long p;
		cin >> p;
		for (long long i = 1; i <= M - 5; i++)s[i] = 0;
		for (long long i = 1; i <= n; i++) {
			cin >> s[i];
		}
		for (long long i = 1; i <= n - 1; i++) {
			for (long long j = i + 1; j <= n; j++) {
				mp[i][j] = min(mp[i][j], s[i] + s[j]);
				mp[j][i] = mp[i][j];
			}
		}
	}
	long long cnt = 0;
	for (long long i = 1; i < n; i++) {
		for (long long j = i + 1; j <= n; j++) {
			a[++cnt].u = i;
			a[cnt].v = j;
			a[cnt].w = mp[i][j];
		}
	}
	sort(a + 1, a + cnt + 1, cmp);
	long long num = 0;
	long long cnt2 = 1;
	long long ans = 0;
	while (num < n - 1) {
		long long u = a[cnt2].u;
		long long v = a[cnt2].v;
		long long w = a[cnt2].w;
		if (find(fa[u]) != find(fa[v])) {
			fa[find(u)] = find(fa[v]);
			ans += w;
			num++;
		}
		cnt2++;
	}
	cout << ans << '\n';
	return 0;
}