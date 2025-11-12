#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 1e5 + 500;
ll t, n, a[N], b[N], c[N], maxm;

void dfs(ll u, ll m, ll na, ll nb, ll nc) {
	if (u == n + 1) {
		maxm = max(maxm, m);
		return;
	}

	ll tmp = m;
	if (na < (n / 2)) {
		dfs(u + 1, m + a[u], na + 1, nb, nc);
	}
	m = tmp;
	if (nb < (n / 2)) {
		dfs(u + 1, m + b[u], na, nb + 1, nc);
	}
	m = tmp;
	if (nc < (n / 2)) {
		dfs(u + 1, m + c[u], na, nb, nc + 1);
	}
	m = tmp;
}

void dfsB(ll u, ll m, ll na, ll nb) {
	if (u == n + 1) {
		maxm = max(maxm, m);
		return;
	}

	ll tmp = m;
	if (na < (n / 2)) {
		dfsB(u + 1, m + a[u], na + 1, nb);
	}
	m = tmp;
	if (nb < (n / 2)) {
		dfsB(u + 1, m + b[u], na, nb + 1);
	}
	m = tmp;
}


int main() {
	cin.tie(0)->sync_with_stdio(0);
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin >> t;
	while (t--) {
		maxm = 0;
		cin >> n;
		for (int i = 1; i <= n; i++) {
			cin >> a[i] >> b[i] >> c[i];
		}
		ll maxa = a[1], maxb = b[1], maxc = c[1];
		for (int i = 1; i <= n; i++) {
			maxa = max(maxa, a[i]);
			maxb = max(maxb, b[i]);
			maxc = max(maxc, c[i]);
		}

		if (n <= 30) {
			dfs(1, 0, 0, 0, 0);
		} else if (maxb == 0 && maxc == 0) {
			sort(a + 1, a + n + 1);
			for (int i = n; i > n / 2; i++) {
				maxm += a[i];
			}
		} else if (maxc == 0) {
			dfsB(1, 0, 0, 0);
		} else {
			dfs(1, 0, 0, 0, 0);
		}
		cout << maxm << '\n';

	}

	return 0;
}