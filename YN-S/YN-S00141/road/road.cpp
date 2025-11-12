//cl csp-s T2
#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll N = 1e4 + 5, M = 1e6 + 5;
int n, m, k, tot, cnt, cot, c[N], a[20][N], fa[N];
ll sum, ans = 1e18;

void in(int &x) {
	int Sum = 0, f = 1;
	char c = getchar();
	while (c < '0' || c > '9') {
		if (c == '-')
			f = -1;
		c = getchar();
	}
	while (c >= '0' && c <= '9') {
		Sum = (Sum << 1) + (Sum << 3) + (c - '0');
		c = getchar();
	}
	x = Sum;
}

struct node {
	int u, v, w;
} e[M], G[M], P[M];

inline bool cmp(node x, node y) {
	return x.w < y.w;
}

inline int find(int x) {
	if (x == fa[x])
		return x;
	return fa[x] = find(fa[x]);
}

inline void merge(int x, int y) {
	fa[find(x)] = find(y);
}

inline void ks() {
	for (int i = 1; i <= m; ++i) {
		if (find(e[i].v) != find(e[i].u)) {
			G[++cnt] = e[i];
			merge(e[i].v, e[i].u);
		}
	}
}

inline void ks1(int K) {
	int Cnt = 0;
	for (int i = 1; i <= cot; ++i) {
		if (find(P[i].v) != find(P[i].u)) {
			sum += P[i].w;
			merge(P[i].u, P[i].v);
			++Cnt;
		}
		if (Cnt == K)
			return;
	}
}

int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	in(n), in(m), in(k);
	for (int i = 1; i <= n; ++i) {
		fa[i] = i;
	}
	for (int i = 1; i <= m; ++i) {
		int u, v, w;
		in(u), in(v), in(w);
		e[++tot] = {u, v, w};
	}
	sort(e + 1, e + 1 + m, cmp);
	ks();
	for (int i = 1; i <= k; ++i) {
		in(c[i]);
		for (int j = 1; j <= n; ++j) {
			in(a[i][j]);
		}
	}
	for (int i = 0; i < (1 << k); ++i) {
		for (int j = 1; j <= n; ++j) {
			fa[j] = j;
		}
		cot = cnt;
		sum = 0;
		int Cnt = 0;
		for (int j = 1; j <= cnt; ++j) {
			P[j] = G[j];
		}
		for (int j = 1; j <= n + k; ++j) {
			fa[j] = j;
		}
		for (int j = 1; j <= k; ++j) {
			if ((i & (1 << (j - 1)))) {
				Cnt++;
				sum += c[j];
				for (int l = 1; l <= n; ++l) {
					if (a[j][l] > P[cnt].w)
						continue;
					P[++cot] = {j + n, l, (int)a[j][l]};
				}
			}
		}
		sort(P + 1, P + 1 + cot, cmp);
		ks1(n + Cnt);
		ans = min(ans, sum);
		if (ans == 0)
			break;
	}
	cout << ans;
	return 0;
}