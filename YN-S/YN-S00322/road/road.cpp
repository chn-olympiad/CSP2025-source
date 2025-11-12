#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;

struct eg {
	int u, v, w;
} a[N];
int pr[N];

int pd(int q) {
	if (pr[q] == q) {
		return q;
	} else {
		pr[q] = pd(pr[q]);
		return pr[q];
	}
}

int dx(eg a, eg b) {
	return a.w < b.w;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	long long msum = 0;
	int n, m, k;
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	cin >> n >> m >> k;
	int u[k][5];

	for (int i = 0; i < m; i++) {

		cin >> a[i].u >> a[i].v >> a[i].w;
	}

	for (int i = 0; i < k; i++) {

		cin >> u[i][0] >> u[i][1] >> u[i][2] >> u[i][3] >> u[i][4];
	}

	sort(a, a + m, dx);

	for (int i = 1; i <= n; i++) {

		pr[i] = i;
	}

	for (int i = 0; i < m; i++) {

		eg ls = a[i];
		int u = pd(ls.u);
		int v = pd(ls.v);

		if (u != v) {
			pr[u] = v;
			msum += ls.w;
		}
	}

	cout << msum << endl;
	return 0;
}