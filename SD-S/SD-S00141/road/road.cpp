#include <bits/stdc++.h>

using namespace std;

#define int long long

const int N = 1e6 + 5;

int n, m, k, ans;

int c[N], f[N];

struct node {
	int u, v, w;
}e[N];

bool cmp(node a, node b) {
	return a.w < b.w;
}

int find(int x) {
	if (f[x] == x) return x;
	else return f[x] = find(f[x]);
}

void kskl() {
	for (int i = 1; i <= n; i ++) f[i] = i;
	sort(e + 1, e + 1 + m, cmp);
	int cnt = 0;
	for (int i = 1; i <= m; i ++) {
		if (cnt == n - 1) break;
		int u = e[i].u, v = e[i].v;
		int fu = find(u), fv = find(v);
		if (fu == fv) continue;
		cnt ++;
		ans += e[i].w;
		f[u] = find(f[v]);
	}
	
}

signed main(){
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m >> k;
	for (int i = 1; i <= m; i ++) {
		cin >> e[i].u >> e[i].v >> e[i].w;
	}
	ans = 0;
	if (k == 0) kskl();
	cout << ans << '\n';
	return 0;
}

