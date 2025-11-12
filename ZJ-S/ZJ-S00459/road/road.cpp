#include <bits/stdc++.h>
using namespace std; 
long long n, m, k, f[(long long)1e4 + 100], a[12][(long long)1e4 + 100], c[12], top, ff[12], ans = 1e17;
long long u[(long long)1e6 + 10], v[(long long)1e6 + 10], w[(long long)1e6 + 10]; 
struct no {
	long long u, v, w; 
}e[(long long)2e6 + 200]; 
bool cmp(no x, no y) {
	return x.w < y.w; 
}
long long find(long long x) {
	if(x == f[x]) return x; 
	return f[x] = find(f[x]); 
}
void check() {
	long long sum = 0, cnt = 0, tmp = 0; 
	long long t = top; 
	for(int i = 1; i <= n + 2 * k; ++ i) f[i] = i; 
	for(int i = 1; i <= top; ++ i) e[i] = no {u[i], v[i], w[i]}; 
	for(int i = 1; i <= k; ++ i) 
		if(ff[i]) {
			sum += c[i];  
			for(int j = 1; j <= n; ++ j) e[++ t] = no{n + i, j, a[i][j]}; 
			++ tmp; 
		}
	sort(e + 1, e + t + 1, cmp); 
	for(int i = 1; i <= t; ++ i) {
		long long u = e[i].u, v = e[i].v, w = e[i].w; 
		long long fu = find(u),  fv = find(v); 
		if(fu != fv) {
			sum += w, f[fu] = fv; 
			++ cnt; 
			if(cnt == n + tmp - 1) break; 
		}
	}	
//	cout << tmp << " " << sum << "\n"; 
	ans = min(ans, sum); 
}
void dfs(long long x, long long s) {
	if(s >= ans) return ; 
	if(x > k) {
		check(); 
		return ; 
	}
	ff[x] = 1; dfs(x + 1, s + c[x]); 
	if(c[x] != 0) {
		ff[x] = 0; dfs(x + 1, s); 
	}
}
int main () {
	ios :: sync_with_stdio(0); cin.tie(0); cout.tie(0); 
	freopen("road.in", "r", stdin);  
	freopen("road.out", "w", stdout); 
	cin >> n >> m >> k; 
	for(int i = 1; i <= m; ++ i) cin >> u[i] >> v[i] >> w[i], e[++ top] = no{u[i], v[i], w[i]}; 
	for(int i = 1; i <= k; ++ i) {
		cin >> c[i]; 
		for(int j = 1; j <= n; ++ j) cin >> a[i][j]; 
	}
	dfs(1, 0); 
	cout << ans; 
	return 0; 
}
