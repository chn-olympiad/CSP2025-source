//2025csp-s mzyz ÀîÄ­è°
#include <bits/stdc++.h>
#define ll long long
using namespace std;
const ll N = 1e4 + 6, M = 1.2e6 + 6;
int n, m, k, f[N], c[N], tot;
bool bo[N], bl[N];
ll ans = 1e18, sum = 0;

inline void r(int &in) {
	in = 0;
	bool bo = 0;
	char ch = getchar();
	while (!isdigit(ch)) {
		bo ^= (ch == '-');
		ch = getchar();
	}
	while (isdigit(ch)) {
		in = (in << 1) + (in << 3) + (ch ^ 48);
		ch = getchar();
	}
	if (bo) {
		in = -in;
	}
}

struct F {
	int U, V, W, id;
} e[M];

bool cmp(F X, F Y) {
	if (X.W == Y.W) {
		return X.id < Y.id;
	}
	return X.W < Y.W;
}

int find(int x) {
	if (f[x] == x) {
		return x;
	}
	return f[x] = find(f[x]);
}

void dfs(int a, ll b) {
	if (b >= ans) {
		return;
	}
	if (a > k) {
		for (int i = 1; i <= n; ++i) {
			f[i] = i;
		}
		sum = b;
		for (int i = 1; i <= m; ++i) {
			if (!bo[e[i].id]) {
				continue;
			}
			int x = find(e[i].U), y = find(e[i].V);
			if (x != y) {
				f[x] = y;
				sum += e[i].W;
				if (sum >= ans) {
					return;
				}
			}
		}
//		cout << ans << "\n";
		ans = sum;
		return;
	}
	if (c[a])
		dfs(a + 1, b);
//	if (bl[a]) {
	bo[a] = 1;
	dfs(a + 1, b + c[a]);
	bo[a] = 0;
//	}
}

int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
//	freopen("road3.in", "r", stdin);
//	freopen("T2.out", "w", stdout);
	r(n);
	r(m);
	r(k);
	for (int i = 1; i <= m; ++i) {
		r(e[i].U);
		r(e[i].V);
		r(e[i].W);
		e[i].id = 0;
	}
	for (int i = 1; i <= k; ++i) {
		r(c[i]);
		sum += c[i];
		for (int u = 1; u <= n; ++u) {
			e[++m].U = n + i, e[m].V = u;
			e[m].id = i;
			r(e[m].W);
		}
	}
	sort(e + 1, e + m + 1, cmp);
	n += k;
	for (int i = 1; i <= n; ++i) {
		f[i] = i;
	}
	for (int i = 1; i <= m; ++i) {
		int x = find(e[i].U), y = find(e[i].V);
		if (x != y) {
			f[x] = y;
			sum += e[i].W;
			bl[e[i].id] = 1;
		}
	}
	for (int i = 1; i <= k; ++i) {
		if (!bl[i]) {
			sum -= c[i];
		}
	}
	ans = sum;
	bo[0] = 1;
	dfs(1, 0);
	cout << ans;
	return 0;
}
