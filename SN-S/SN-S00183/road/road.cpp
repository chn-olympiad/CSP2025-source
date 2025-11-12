#include <bits/stdc++.h>

#define ll long long
#define pii pair<int, int>
#define mkpr make_pair
#define fir first
#define sec second

using namespace std;

const int maxn = 1e4 + 7;
const int maxm = 1.2e6 + 7;
const int inf  = 0x3f3f3f3f;
const ll  linf = 0x3f3f3f3f3f3f3f3f;

int n, m, K;
int c[15], a[15][maxn];
struct edge {
	int u, v, w;
	bool operator < (const edge& oth) const {return w < oth.w;}
} e[maxm];
struct DSU {
	int fa[maxn << 1];
	void init(int x) {for (int i = 1; i <= x; ++i) fa[i] = i;}
	int find(int x) {return x == fa[x] ? x : fa[x] = find(fa[x]);}
	void merge(int x, int y) {(x = find(x)) == (y = find(y)) ? 0 : fa[x] = y;}
	bool chk(int x, int y) {return find(x) == find(y);}
} dsu;
namespace SubK {
	void Main() {
		dsu.init(n), sort(e + 1, e + m + 1);
		int cnt = 0; ll ans = 0;
		for (int i = 1; i <= m; ++i) {
			if (dsu.chk(e[i].u, e[i].v)) continue;
			dsu.merge(e[i].u, e[i].v), ans += e[i].w;
			if (++cnt == n - 1) break;
		}
		printf("%lld\n", ans);
	}
}
bool A = 1;
namespace Sub1 {
	edge ee[maxm]; int ecnt = 0;
	bool chk() {
		for (int i = 1; i <= n; ++i)
			if (!dsu.chk(1, i)) return 0;
		return 1;
	}
	void Main() {
		ll ans = linf, res = 0;
		for (int s = 0; s < (1 << K); ++s) {
			ecnt = res = 0;
			for (int i = 1; i <= m; ++i) ee[++ecnt] = e[i];
			for (int i = 1; i <= K; ++i) {
				if (s >> (i - 1) & 1) continue;
				res += c[i];
				for (int j = 1; j <= n; ++j)
					ee[++ecnt] = {n + i, j, a[i][j]};
			}
			dsu.init(n + K), sort(ee + 1, ee + ecnt + 1);
			for (int i = 1; i <= ecnt; ++i)  {
				if (dsu.chk(ee[i].u, ee[i].v)) continue;
				res += ee[i].w, dsu.merge(ee[i].u, ee[i].v);
				if (chk()) break;
			}
			ans = min(ans, res);
		}
		printf("%lld\n", ans);
	}
}
signed main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
//	freopen("road2.in", "r", stdin);
//	freopen("my.out", "w", stdout);
	scanf("%d%d%d", &n, &m, &K);
	for (int i = 1; i <= m; ++i)
		scanf("%d%d%d", &e[i].u, &e[i].v, &e[i].w);
	for (int i = 1; i <= K; ++i) {
		scanf("%d", c + i), A &= (c[i] == 0);
		for (int j = 1; j <= n; ++j)
			scanf("%d", a[i] + j);
	}
	if (!K) {
		SubK::Main();
		return 0;
	}
	
	Sub1::Main();
	return 0;
}

