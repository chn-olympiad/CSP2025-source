#include <bits/stdc++.h>
#define int long long
#define ull unsigned long long
using namespace std;
const int N = 5e3 + 10, M = 998244353;
map<ull, int> mp;
int n, a[N], ans, maxxn = -1;
int dfs2(int x, int sum, int maxn, bool can, ull hash) {
	if(x > n + 1)
		return 0;
	if(mp.count(hash)) {
		if(mp[hash] >= 0) return mp[hash];
	}
		
	if(x >= 4 && sum > 2 * maxn && can) {
		mp[hash] ++;mp[hash] %= M;
	}
	char sd = x + '0';
	int f = 0;
	f += dfs2(x + 1, sum + a[x], max(maxn, a[x]), 1, hash * 23 + x + 1) % M;
	f += dfs2(x + 1, sum, maxn, 0, hash) % M;
	return mp[hash] + f;
}
void dfs(int x, int sum, int maxn, bool can) {
	if(x > n + 1)
		return;
	if(x >= 4 && sum > 2 * maxn && can) {
		ans ++;ans %= M;
	}
	dfs(x + 1, sum + a[x], max(maxn, a[x]), 1);
	dfs(x + 1, sum, maxn, 0);
}
int c(int n, int m) {                    
	int x = 1;
	for (int i = 1; i <= n; i ++) {
		x = x * (m - i + 1) % M;
	}
	for (int i = 1; i <= n; i ++) x = x / i % M;
	return x % M;
}
int solve(int x) {
	int sum = 0;
	for (int i = 3; i <= x; i ++) {
		sum = (sum + c(i, x)) % M;
	}
	return sum;
}
signed main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i ++) {
		cin >> a[i];           
		maxxn = max(maxxn, a[i]);
	}
	if(n <= 26) {
		dfs(1, 0, -1, 1);
		cout << ans;
		return 0;      
	}                 
	else if(maxxn == 1) {
		cout << solve(n);
		return 0;
	}
	else 
		cout << dfs2(1, 0, -1, 1, 0);
	return 0;
} 