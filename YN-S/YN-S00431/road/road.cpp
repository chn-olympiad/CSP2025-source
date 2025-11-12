#include <bits/stdc++.h>
#define ll long long
using namespace std;
int n, m, k;
ll l;

struct edge {
	ll u, v, w;
} e[2000005];
ll v[11][10004];
ll fa[10004];

ll find(ll x) {
	if (fa[x] == x) {
		return x;
	}
	return fa[x] = find(fa[x]);
}

bool cmp(edge a, edge b) {
	return a.w < b.w;
}
ll ans = 0;
ll xz = 0;

void kal() {
	sort(e + 1, e + l + 1, cmp);
	for (int i = 1; i <= m + k * (n - 1); i++) {
		ll gx = find(e[i].u);
		ll gy = find(e[i].v);
		if (gx == gy) {
			continue;
		}
		ans += e[i].w;
		fa[gx] = gy;
	}
}

int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	cin >> n >> m >> k;
	for (int i = 1; i <= n; i++) {
		fa[i] = i;
	}
	for (int i = 1; i <= m; i++) {
		ll x, y, z;
		cin >> x >> y >> z;
		e[i].u = x;
		e[i].v = y;
		e[i].w = z;
	}
	l = m + 1;
	for (int j = 1; j <= k; j++) {
		for (int i = 1; i <= n + 1; i++) {
			cin >> v[j][i];
		}
	}
	for (int i = 1; i <= k; i++) {
		for (int j = 2; j <= n; j++) {
			for (int b = j + 1; b <= n; b++) {
				e[l].u = j - 1;
				e[l].v = b - 1;
				e[l].w = v[i][j] + v[i][b] + v[i][1];
				l++;
			}
		}
	}
	kal();
	cout << ans;
	return 0;
}