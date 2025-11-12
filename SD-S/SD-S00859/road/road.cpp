#include<bits/stdc++.h>
namespace whaleL{
using namespace std;
#define ll long long
#define pii pair<int, int>
#define fi first
#define se second
#define emp emplace
#define emb emplace_back
#define fo(i, j, n) for(int i = (j); i <= (n); i ++)
#define f(i, n) fo(i, 1, n)
#define re return
#define brk break
#define con continue
#define il inline
#define gn (cout << '\n', 0)
il void P() {cerr << '\n';}
template<typename m, typename...ms>
void P(m x, ms...y) {cerr << x << ' '; P(y...);}
il void S(string s, int a) {cerr << s << a << ": ";}
#ifdef _MJawa_
#define p(x...) (S("["#x"] Line ", __LINE__), P(x), 0)
#define g(x...) do{x;} while(0);
#else
#define p(x...) 0
#define g(x...) 
#endif
#ifndef DISFILE
#define file(x) freopen(#x".in", "r", stdin), freopen(#x".out", "w", stdout)
#else
#define file(...)
#endif
}using namespace whaleL;
const int N = 2e5 + 233;
#define int ll

mt19937 rnd(233);
const int GG = 1e3 + 02;
const int inf = 1e17 + 233;

vector<pii> e[N];

priority_queue<pii> q;
int di[N], vi[N];
bool is[N];

int c[11], AA;
int n, m, k, ans = inf;

//il int solve2() {
//	g(
//		f(i, k) cout << is[i] << " ";
//		gn;
//	)
//	int res = 0;
//	f(i, k) if (!is[n + i]) res += c[i];
//	fo(i, 0, n + k) di[i] = inf, vi[i] = false;
//	di[0] = 0;
//	for (int u, v, w, awa = 0; awa <= n + k; awa ++) {
//		v = inf, u = inf;
//		fo(i, 0, n + k) {
//			if (di[i] < v && !vi[i]) u = i, v = di[i];
//		}
//		if (u == inf) brk;
//		vi[u] = true;
//		res += di[u];
//		for (pii &ts : e[u]) {
//			v = ts.fi, w = ts.se;
//			p(v);
//			if (di[v] > w && !is[v]) {
//				di[v] = w;
//			}
//		}
//	}
//	f(i, n) {
//		if (di[i] == inf) re inf;
//	}
//	re res;
//}
il int solve1() {
	g(
		f(i, k) cout << is[i] << " ";
		gn;
	)
	int res = 0;
	f(i, k) if (!is[n + i]) res += c[i];
	fo(i, 0, n + k) di[i] = inf, vi[i] = false;
	di[0] = 0;
	q.emp(0, 0);
	for (int u, v, w; q.size(); ) {
		u = q.top().se;
		q.pop();
		if (vi[u]) con;
		p(u, e[u].size());
		vi[u] = true;
		res += di[u];
		for (pii &ts : e[u]) {
			v = ts.fi, w = ts.se;
			p(v);
			if (di[v] > w && !is[v]) {
				di[v] = w;
				q.emp(-di[v], v);
			}
		}
	}
	if (AA == ((1 << k) - 1))
	f(i, n) {
		if (di[i] == inf) re inf;
	}
	re res;
}

signed main(){
	ios::sync_with_stdio(0); cin.tie(0), cout.tie(0);
	file(road);
	cin >> n >> m >> k;
	int u, v, w;
	f(i, m) {
		cin >> u >> v >> w;
		e[u].emb(v, w);
		e[v].emb(u, w);
	}
	e[0].emb(1, 0);
	int CNT = 0;
	f(x, k) {
		cin >> c[x], CNT += c[x];
		f(i, n) {
			cin >> u;
			e[n + x].emb(i, u);
			e[i].emb(n + x, u);
		}
	}
	if (CNT) {
//		if ((1 << k) * m <= 1 && k > 5) {
			fo(A, 0, (1 << k) - 1) {
				AA = A;
				f(i, k) {
					is[n + i] = A & (1 << (i - 1));
				}
				ans = min(ans, solve1());
			}
//		}
//		else {
//			ans = min(ans, solve1());
//			f(i, k) is[n + i] = true;
//			ans = min(ans, solve1());
//				AA = (1 << k) - 1;
//			f(awa, (1 << 5)) {
//				f(i, k) is[n + i] = rnd() & 1;
//				ans = min(ans, solve1());
//			}
//		}
	}
	else {
		ans = solve1();
	}
	cout << ans;
}

