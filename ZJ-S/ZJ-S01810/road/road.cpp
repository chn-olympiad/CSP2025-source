#include <bits/stdc++.h>

using namespace std;

namespace IO
{
#define gc getchar
#define pc putchar
template<typename T> inline void read(T& x) 
{
	x = 0; char ch = gc(); bool w = 1;
	while (!isdigit(ch)) { if (ch == 0x2d) w = 0; ch = gc(); }
	while (isdigit(ch)) { x = x * 0xa + (ch ^ 0x30); ch = gc(); }
	x = w ? x : -x; 
}
template<typename T, typename... Args> 
inline void read(T& x, Args&... args) { read(x); read(args...); }
template<typename T> inline void write(T x)
{
	if (x < 0) pc(0x2d), x = -x; if (x > 9) write(x / 0xa); pc(x % 0xa + 0x30); 
}
} using namespace IO;

typedef long long ll; 
typedef unsigned long long ull; 
#define pii pair<int, int>
#define pil pair<int, ll>
#define pli pair<ll, int>
#define pll pair<ll, ll>
#define mems(arr, v) memset(arr, v, sizeof(arr))
#define rep(i, x, y) for (int i = (x); i <= (y); ++i)
#define fep(i, y, x) for (int i = (y); i >= (x); --i)
#define pbk push_back
#define mkp make_pair
#define fst first
#define sec second

const int maxn = 1e4 + 5, maxm = 1e6 + 1e5 + 5; 
int n, m, k, S; ll c[maxn], a[12][maxn], ans, res;
struct E{ int u, v; ll w; } e1[maxm], e2[maxn]; int cnt2;
struct G{ int to; ll w; } b[12][maxn]; int rt[maxn], pos[maxn], vis[maxn];
inline bool cmp(const E& x, const E& y) { return x.w < y.w; }
inline bool cmp2(const G& x, const G& y) { return x.w < y.w; }

int fa[maxn]; 
inline int find(int u) { return u == fa[u] ? u : fa[u] = find(fa[u]); }

void kruskal()
{
	sort(e1 + 1, e1 + m + 1, cmp);
	rep(i, 1, n) fa[i] = i; 
	for (int i = 1; i <= m && cnt2 < n - 1; ++i)
	{
		int u = e1[i].u, v = e1[i].v; ll w = e1[i].w; 
		if (find(u) == find(v)) continue; 
		ans+= w; fa[find(u)] = find(v); e2[++cnt2] = e1[i]; 
	}
}

inline void work()
{
	rep(i, 1, n) fa[i] = i; cnt2 = 0; 
	for (int i = 1; i <= m && cnt2 < n - 1; ++i)
	{
		int p = 0, u = e2[i].u, v = e2[i].v; ll w = e2[i].w; 
		rep(j, 1, k) if (pos[j] <= n && vis[j])
		{
			while (pos[j] <= n && find(rt[j]) == find(b[j][pos[j]].to)) ++pos[j];
			if (pos[j] > n) continue; 
			if (b[j][pos[j]].w < w) p = j, u = rt[j], v = b[j][pos[j]].to, w = b[j][pos[j]].w;
		}
		if (find(u) == find(v)) continue;
		fa[find(u)] = find(v); res+= w; ++cnt2; 
		if (p) pos[p]++, i--;
	}
}

int main()
{
	freopen("road.in", "r", stdin); freopen("road.out", "w", stdout); 
	read(n, m, k); rep(i, 1, m) read(e1[i].u, e1[i].v, e1[i].w);
	rep(i, 1, k) { read(c[i]); rep(j, 1, n) read(a[i][j]); }
	rep(i, 1, k) rep(j, 1, n) b[i][j] = {j, a[i][j]};
	rep(i, 1, k) sort(b[i] + 1, b[i] + n + 1, cmp2);
	rep(i, 1, k) rt[i] = b[i][1].to; 
	S = (1 << k); kruskal(); 
	for (int s = 1; s < S; ++s)
	{
		res = 0; 
		rep(i, 1, k) vis[i] = 0, pos[i] = 2;
		rep(i, 1, k) if ((s >> (i - 1)) & 1) res+= c[i] + b[i][1].w, vis[i] = 1;
		if (res > ans) continue; 
		work(); ans = min(ans, res);
	}
	write(ans); pc(0xa); 
	return 0; 
}
/*
4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
1 1 8 2 4
100 1 3 2 4
*/