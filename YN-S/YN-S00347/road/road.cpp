#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

typedef long long LL;

const int N = 1e4 + 10;
const int M = 2e6 + 10;

struct edge {
	int w, u, v;
};

int n, m, k;
bool flagA;
int p[N], c[N], a[20][N];
edge e[M], e1[M];
LL ans;

bool cmp(edge x, edge y) {
	return x.w < y.w;
}

int find(int x) {
	if (p[x] == x)
		return x;
	return p[x] = find(p[x]);
}

void kruskal() {
	sort(e + 1, e + 1 + m, cmp);
	for (int i = 1; i <= n; i++)
		p[i] = i;
	for (int i = 1; i <= m; i++) {
		int u = e[i].u, v = e[i].v;
		if (find(u) != find(v)) {
			p[p[u]] = p[v];
			ans += e[i].w;
		}
	}
	return;
}

int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> n >> m >> k;
	for (int i = 1; i <= m; i++)
		cin >> e[i].u >> e[i].v >> e[i].w;
	flagA = 0;
	for (int i = 1; i <= k; i++) {
		cin >> c[i];
		for (int j = 1; j <= n; j++) {
			cin >> a[i][j];
		}
	}
	if (k == 0) {
		kruskal();
		cout << ans;
	} else {
		int tm = m;
		memcpy(e1, e, sizeof(e));
		LL res = 0;
		for (int i = 0; i < (1 << k); i++) {
			memcpy(e, e1, sizeof(e));
			m = tm;
			for (int j = 0; j < k; j++) {
				if (i >> j & 1) {
					ans += c[j + 1];
					for (int tt = 1; tt <= n; tt++) {
						e[++m].u = tt;
						e[m].v = j + 1;
						e[m].w = a[j + 1][tt];
					}
				}
			}
			kruskal();
			res = max(res, ans);
		}
		cout << res;
	}
	return 0;
}