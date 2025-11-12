#include <bits/stdc++.h>
using namespace std;
char *pa, *pb, buf[1000000];
#define int long long
#define db double
#define p_b push_back
#define nc() (pa==pb && (pb=(pa=buf)+fread(buf,1,1000000,stdin),pa==pb)?EOF:*pa++)
inline int in() { int x=0,f=1;char c=nc();while(!isdigit(c))f*=c==45?-1:1,c=nc();while(isdigit(c))x=(x<<1)+(x<<3)+(c^48),c=nc();return x*f; }

const int N = 1e4+15, M = 2e6+5;

int n, m, k, c[15], cw[N][15], fa[N], rk[N], res = 0, r = 0;
struct edge 
{ 
	int u, v, w;
	inline bool operator < (edge e) { return w < e.w; }
	inline bool operator > (edge e) { return w > e.w; }
	inline bool operator == (edge e) { return w == e.w; }
} es[M];

inline int fd(int u) { if (u == fa[u]) return u; else return fa[u] = fd(fa[u]); }

inline void un(int u, int v) { u = fd(u), v = fd(v); if (rk[u] < rk[v]) fa[u] = v; else if (rk[v] < rk[u]) fa[v] = u; else fa[u] = v, ++rk[v]; }

signed main() 
{
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	n = in(), m = in(), k = in(); 
	for (int i = 1; i <= m; ++i) es[i] = {in(), in(), in()};
	for (int j = 1; j <= k; ++j) { 
		c[j] = in(); 
		for (int i = 1; i <= n; ++i) cw[i][j] = in();
	}
	for (int i = 1; i <= n; ++i) for (int t = 1; t <= k; ++t) if (cw[i][t] == 0) {
		for (int j = 1; j <= n; ++j) es[++m] = {i, j, cw[j][t]};
	}
	sort(es+1, es+m+1); fill(rk+1, rk+n+1, 0); for (int i = 1; i <= n; ++i) fa[i] = i;
	for (int i = 1; r < n-1; ++i) {
		int u = es[i].u, v = es[i].v, w = es[i].w;
		if (fd(u) != fd(v)) { un(u, v); ++r, res += w; }
	}
	printf("%lld\n", res);
	fclose(stdin);
	fclose(stdout);
	return 0;
}