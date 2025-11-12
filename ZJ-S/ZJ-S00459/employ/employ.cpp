#include <bits/stdc++.h>
using namespace std; 
long long n, m, c[550], a[550], ans, f[550], vis[550]; 
char ch; 
bool cmp(long long x, long long y) {return x > y; }
bool check() {
	long long tmp = 0, sum = 0; 
	for(int i = 1; i <= n; ++ i) {
		long long x = a[i]; 
		if(tmp >= c[x]) ++ tmp; 
		else if(f[i] == 0) ++ tmp; 
		else ++ sum; 
	}
	return (sum >= m); 
}
void dfs(long long x) {
	if(x > n) {
		if(check()) ++ ans, ans %= 998244353; 
		return ; 
	}
	for(int i = 1; i <= n; ++ i) 
	if(vis[i] == 0) {
		a[x] = i, vis[i] = 1, dfs(x + 1), vis[i] = 0; 
	}
}
int main () {
	ios :: sync_with_stdio(0); cin.tie(0); cout.tie(0); 
	freopen("employ.in", "r", stdin);  
	freopen("employ.out", "w", stdout); 
	cin >> n >> m; 
	for(int i = 1; i <= n; ++ i) cin >> ch, f[i] = ch - '0';
	for(int i = 1; i <= n; ++ i) cin >> c[i]; 
	sort(c + 1, c + n + 1, cmp); 
	dfs(1); 
	cout << ans; 
	return 0; 
}
