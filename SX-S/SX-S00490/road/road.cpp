#include <bits/stdc++.h>
using namespace std;
#define gcd std::__gcd
#define ctz __builtin_ctzll
#define popcount __builtin_popcountll
template<class T> constexpr T lowbit(T x) {return x&-x;}
template<class T> constexpr T lg(T x) {return x==0?0:std::__lg(x);}

template<class T> ostream& operator<< (ostream& out, const vector<T>& v) {
	out << "[";
	for (int i = 0, n = v.size(); i < n; out << (++i < n ? ", " : "")) out << v[i];
	return out << "]";
}
template <class A, class B> ostream& operator<< (ostream& out, const pair<A, B>& p) {
	return out << "(" << p.first << ", " << p.second << ")";
}
template <class A, class B> istream& operator>> (istream& in, pair<A, B>& p) {
	return in >> p.first >> p.second;
}

#undef assert
#ifdef SPN_LOCAL
#define FILE(x) ((void)0)
#define FLOCAL(x) freopen(x".in", "r", stdin), freopen(x".out", "w", stdout)
#define debug(x) (cerr<<"On Line "<<__LINE__<<": "<<#x<<" = "<<(x)<<endl)
void _o(auto&&...x)
{int f=1;((cerr<<(f?"":", ")<<x,f=0),...);}
#define mdebug(...) (cerr<<"On Line "<<__LINE__<<": {"<<#__VA_ARGS__<<"} = [",_o(__VA_ARGS__),cerr<<"]\n")
#define assert(x) do{if(!(x))cerr<<"Assertion Failed on Line "<<__LINE__<<endl,exit(0);}while(0)
#else
#define FILE(x) freopen(x".in", "r", stdin), freopen(x".out", "w", stdout)
#define FLOCAL(x) ((void)0)
#define debug(x) ((void)0)
#define mdebug(...) ((void)0)
#define assert(x) ((void)0)
#endif //SPN_LOCAL

// remember to define variable type into long long!
constexpr int N = 1e6 + 5, M = 1e4 + 5;

int n, m, k, w, c[15];
struct Edge {
	int u, v, w;
	bool operator< (const Edge& a) const {return w < a.w;}
} e[N], p[N << 1], f[11][M], tmp[N << 1];
int fa[M], sz[M];
int find(int x) {return x == fa[x] ? x : fa[x] = find(fa[x]);}

void _main() {
	cin >> n >> m >> k;
	for (int i = 1; i <= m; i++) cin >> e[i].u >> e[i].v >> e[i].w;
	sort(e + 1, e + m + 1);
	for (int i = 1; i <= k; i++) {
		cin >> c[i];
		for (int j = 1; j <= n; j++) cin >> w, f[i][j] = {i + n, j, w};
		sort(f[i] + 1, f[i] + n + 1);
	}
	long long res = 1e18;
	for (int s = (count(c + 1, c + k + 1, 0) == k ? ((1 << k) - 1) : 0); s < (1 << k); s++) {
		copy(e + 1, e + m + 1, p + 1);
		int tot = m, cnt = 0, tar = popcount(s) + n;
		long long cur = 0;
		for (int i = 1; i <= k; i++) {
			if (s >> (i - 1) & 1) cur += c[i];
		}
		if (cur >= res) continue;
		for (int i = 1; i <= k; i++) {
			if (!(s >> (i - 1) & 1)) continue;
//			for (int j = 1; j <= n; j++) p[++tot] = f[i][j];
			copy(p + 1, p + tot + 1, tmp + 1);
			merge(tmp + 1, tmp + tot + 1, f[i] + 1, f[i] + n + 1, p + 1);
			tot += n;
		}
//		assert(is_sorted(p + 1, p + tot + 1));
//		stable_sort(p + 1, p + tot + 1);
		iota(fa + 1, fa + n + k + 1, 1), fill(sz + 1, sz + n + k + 1, 1);
		for (int i = 1; i <= tot; i++) {
			int u = find(p[i].u), v = find(p[i].v), w = p[i].w;
			if (u == v) continue;
			//mdebug(p[i].u, p[i].v, w);
			if (sz[u] > sz[v]) swap(u, v);
			fa[u] = v, sz[v] += sz[u], cur += w;
			if (++cnt == tar - 1) break;
			if (cur >= res) break;
		}
		//mdebug(s, cur);
		res = min(res, cur);
	}
	cout << res;
} signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr), cerr.tie(nullptr);
	FILE("road");
	//debug((sizeof(p) + sizeof(w)) / 1048576.0);
	FLOCAL("road4");

	int t = 1; for (/*cin >> t*/; t--; ) _main();
	return 0;
}

// expected 80 + [0, 20] pts.
