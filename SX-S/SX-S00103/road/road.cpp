#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pll pair<ll,ll>

const int N = 1e4+10;

int n, m, k, f[N];
ll ans;

int g(int x) {
	return x == f[x] ? x : f[x];
}

struct es {
	int u, v, w;
} e[N];

bool cmp(es a1, es a2) {
	return a1.w < a2.w;
}

int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	scanf("%d%d%d", &n, &m, &k);
	for (int i = 1; i <= n; i++)
		f[i] = i;
	for (int i = 1; i <= m; i++) {
		scanf("%d%d%d", &e[i].u, &e[i].v, &e[i].w);

	}
	sort(e + 1, e + n + 1, cmp);
	if (k == 0) {
		for (int i = 1; i <= m; i++) {
			int x = e[i].u, y = e[i].v, z = e[i].w;
			if (g(f[x]) != g(f[y])) {
				if (x < y)
					swap(x, y);
				f[x] = g(f[y]);
				ans += z;
			}
		}
	}
	printf("%lld", ans);
	return 0;
}