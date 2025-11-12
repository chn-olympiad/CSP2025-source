#include <bits/stdc++.h>
using namespace std;
const int N = 1e4 + 10, K = 15, INF = 0x3f3f3f3f;
struct E {
	int u, v, w;
	bool operator< (const E &x) const {
		return w < x.w;
	}
};
vector<E> e;
int oriw[N][N], n, m, k, a[K][N], c[K], s[N];
#define gc getchar()
#define pc(x) putchar(x)
#define isd(x) ((x) >= '0' && (x) <= '9')
inline void rd(int &x) {
	x = 0; char c;
	for(c = gc; !isd(c); c = gc);
	for(; isd(c); c = gc) x = (x << 1) + (x << 3) + (c ^ 48);
}
inline void wr(long long x) {
	if(x > 9) wr(x / 10);
	pc((x % 10) | 48);
}
int find(int x) {
	return x != s[x] ? s[x] = find(s[x]) : x;
}
inline void chkmin(int &a, long long b) {
	if(a > b) a = b;
}
#define min(a, b) ((a) < (b) ? (a) : (b))
#define max(a, b) ((a) > (b) ? (a) : (b))
signed main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	rd(n), rd(m), rd(k);
	memset(oriw, 0x3f, sizeof oriw);
	for(int i = 1, u, v, w; i <= m; ++i) {
		rd(u), rd(v), rd(w);
		chkmin(oriw[min(u, v)][max(u, v)], w);
	}
	for(int i = 1; i <= k; ++i) {
		rd(c[i]);
		for(int j = 1; j <= n; ++j)
			rd(a[i][j]);
	}
	int	ecnt = 0;
	for(int u = 1; u < n; ++u)
		for(int v = u + 1; v <= n; ++v) {
			for(int i = 1; i <= k; ++i)
				chkmin(oriw[u][v], (long long)a[i][u] + a[i][v]);
			if(oriw[u][v] != INF)
				++ecnt, e.push_back({u, v, oriw[u][v]});
		}
	sort(e.begin(), e.end());
	for(int i = 1; i <= n; ++i) s[i] = i;
	int tot = 0;
	long long ans = 0;
	for(int i = 0; i < ecnt; ++i) {
		int fu = find(e[i].u), fv = find(e[i].v);
		if(fu == fv) continue;
		s[fu] = fv, ans += e[i].w;
		if(++tot >= n) break;
	}
	wr(ans);
	return 0;
}