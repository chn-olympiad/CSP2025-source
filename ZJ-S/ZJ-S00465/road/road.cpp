#include <bits/stdc++.h>
#define gc() (iS == iT && (iT = (iS = buf) + fread(buf, 1, 1 << 20, stdin), iS == iT) ? EOF : *iS++)
char buf[1 << 20], *iS = buf, *iT = buf;
template <typename _Tp> inline void read(_Tp& x) {
	x = 0; char c = gc(); bool f = 0;
	for(; !std::isdigit(c); c = gc()) f |= c == '-';
	for(; std::isdigit(c); c = gc()) x = x * 10 + (c ^ 48);
	if(f) x = ~x + 1;
}
template <> inline void read(std::string& x) {
	x.clear(); char c = gc();
	for(; !std::isgraph(c); c = gc());
	for(; std::isgraph(c); c = gc()) x += c;
}
template <typename _Tp, typename ...Args>
inline void read(_Tp& x, Args& ...args) {
	read(x), read(args...);
}
typedef long long i64;
constexpr int N = 1e4 + 5;
constexpr int M = 2e6 + 5;
std::mt19937 seed((unsigned)time(nullptr));
int n, m, k, c[15], a[15][N], siz[N], fa[N];
bool vis[N];
i64 ans = 1e18;
struct Edge {
	int u, v, w;
} e[M], E[M];

int find(int u) { return u == fa[u] ? u : fa[u] = find(fa[u]); }
inline bool merge(int u, int v) {
	int fu = find(u), fv = find(v);
	if(fu == fv) return 1;
	if(siz[fu] > siz[fv]) std::swap(fu, fv);
	fa[fu] = fv, siz[fv] += siz[fu];
	return 0;
}

signed main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	int st = clock();
	read(n, m, k);
	for(int i = 1; i <= m; i++) read(e[i].u, e[i].v, e[i].w);
	std::vector<int> dig;
	int T = 0;
	for(int i = 1; i <= k; i++) {
		read(c[i]);
		for(int j = 1; j <= n; j++) read(a[i][j]);
		if(c[i] == 0) T |= 1 << (i - 1);
	}
	std::deque<int> vec;
	for(int S = 1; S < (1 << k) - 1; S++) if(S & T) vec.push_back(S);
	std::shuffle(vec.begin(), vec.end(), seed);
	vec.push_front(0), vec.push_front((1 << k) - 1);
	for(int S = 1; S < (1 << k) - 1; S++) if(!(S & T)) vec.push_back(S);
	for(auto& S : vec) {
		int tot = m, node = n + __builtin_popcount(S);
		i64 res = 0;
		for(int i = 1; i <= m; i++) E[i] = e[i];
		for(int i = 1, id = n; i <= k; i++) {
			if(~S >> (i - 1) & 1) continue;
			id++;
			for(int j = 1; j <= n; j++) {
				E[++tot] = Edge{id, j, a[i][j]};
			}
			res += c[i];
		}
		std::sort(E + 1, E + tot + 1, [&](Edge lhs, Edge rhs) { return lhs.w < rhs.w; });
		std::iota(fa + 1, fa + node + 1, 1);
		std::fill(siz + 1, siz + n + 1, 1);
		memset(vis + 1, 0, sizeof(bool) * n);
		for(auto& _ : E) {
			if(siz[find(1)] == n) break;
			int u = _.u, v = _.v, w = _.w;
			if(merge(u, v)) continue;
			res += w;
			if(res > ans) break;
		}
		ans = std::min(ans, res);
		if(clock() - st > 0.93 * CLOCKS_PER_SEC) break;
	}
	printf("%lld\n", ans);
	return 0;
}
