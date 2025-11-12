#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
//#define int long long
const int N = 2e3 + 10, M = 2e6 + 10;
const int mod = 1e9 + 7, base = 233;
const double eps = 1e-8;
const ll inf = 1e17;
struct Code{
	ll u, v, w;
} a[M], b[M];
ll n, m, k, ans = inf, c[N], val[N][N], f[N];
inline ll read(){
	ll x = 0, m = 1;
	char ch = getchar();
	while(!isdigit(ch)){
		if(ch == '-') m = -1;
		ch = getchar();
	}
	while(isdigit(ch)){
		x = (x << 1) + (x << 3) + (ch ^ 48);
		ch = getchar();
	}
	return x * m;
}
inline void write(ll x){
	if(x < 0){
		putchar('-');
		write(-x);
		return;
	}
	if(x >= 10) write(x / 10);
	putchar(x % 10 + '0');
}
inline void Freopen(){
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
}
inline bool cmp(Code x, Code y){
	return x.w < y.w;
}
inline int find(int x){
	return f[x] == x ? x : f[x] = find(f[x]);
}
inline ll kruskal(int n, int m){
	ll cnt = 0, res = 0;
	sort(a + 1, a + 1 + m, cmp);
	for(int i = 1; i <= n + k; ++ i) f[i] = i;
	for(int i = 1; i <= m; ++ i){
		int u = find(a[i].u), v = find(a[i].v), w = a[i].w;
		if(u == v) continue;
		f[u] = v, res += a[i].w;
		if((++ cnt) == n - 1) break;
	}
	return res;
}
inline void solve(){
	n = read(), m = read(), k = read();
	for(int i = 1; i <= m; ++ i) b[i].u = read(), b[i].v = read(), b[i].w = read();
	for(int i = 1; i <= k; ++ i) {
		c[i] = read();
		for(int j = 1; j <= n; ++ j) val[i][j] = read();
	}
	for(int S = 0; S < (1 << k); ++ S){
		ll res = 0, tot = 0, x = 0;
		for(int i = 1; i <= m; ++ i) a[++ tot].u = b[i].u, a[tot].v = b[i].v, a[tot].w = b[i].w;
		for(int i = 1; i <= k; ++ i){
			if(!((S >> (i - 1)) & 1)) continue;
			res += c[i], ++ x;
			for(int j = 1; j <= n; ++ j) a[++ tot].u = n + i, a[tot].v = j, a[tot].w = val[i][j];
		}
		res += kruskal(n + x, tot);
//		cerr << S << ' ' << res << '\n';
		ans = min(ans, res);
	}
	write(ans);
}
signed main(){
	Freopen();
	int T = 1;
//	T = read();
	while(T --) solve();
	return 0;
}

