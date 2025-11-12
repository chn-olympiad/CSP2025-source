//huangyi 2025.11.1
#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e4 + 100;
const int M = 2e6;
ll n, m, k, cnt;
ll sum, fa[N];
ll c[50], a[50][N];
bool bk[50];

struct node {
	ll u, v, w;
} e[M], p[M];

int find(int x) {
	if (x == fa[x])
		return x;
	return fa[x] = find(fa[x]);
}

bool cmp(node x, node y) {
	return x.w < y.w;
}

void kcs007nb(int hy) {
	for (int i = 1; i <= n + k; i++)
		fa[i] = i;
	for (int i = 1; i <= k; i++)
		bk[i] = 0;
	sort(e + 1, e + cnt + 1, cmp);
	bk[hy] = 1;
	ll ans = c[hy], tot = 0, ain = 0;
	for (int i = 1; i <= cnt; i++) {
		int x = e[i].u, y = e[i].v;
		x = find(x);
		y = find(y);
		if (x == y)
			continue;
		fa[x] = fa[y];
		ans += e[i].w;
		p[++tot] = e[i];
		if (e[i].u <= n && e[i].v <= n)
			ain++;
		else {
			if (e[i].u > n && bk[e[i].u - n] == 0) {
				bk[e[i].u - n] = 1;
				ans += c[e[i].u - n];
			}
			if (e[i].v > n && bk[e[i].v - n] == 0) {
				bk[e[i].v - n] = 1;
				ans += c[e[i].v - n];
			}
		}
		if (ain == n - 1)
			break;
	}
	if (ans < sum) {
		sum = ans;
		for (int i = 1; i <= tot; i++) {
			e[i] = p[i];
		}
		cnt = tot;
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	cin >> n >> m >> k;
	for (ll i = 1; i <= m; i++) {
		cin >> e[i].u >> e[i].v >> e[i].w;
	}
	for (int i = 1; i <= k; i++) {
		cin >> c[i];
		for (int j = 1; j <= n; j++)
			cin >> a[i][j];
	}
	sum = 1e18;
	cnt = m;
	kcs007nb(0);
	for (int i = 1; i <= k; i++) {
		for (int j = 1; j <= n; j++) {
			e[++cnt].u = j;
			e[cnt].v = i + n;
			e[cnt].w = a[i][j];
		}
		kcs007nb(i);
	}
	cout << sum;
	return 0;
}
