#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 5e3 + 10, mod = 998244353;
int read(){
	int x; scanf("%lld", &x); return x;
}
int n, ans;
int a[N], book[N], b[N], vis[N], t[N];
void dfs(int t, int sum, int maxn){
	if(t > n + 1) return;
	if(t > 3){
		int z = 0;
		for(int i = 1; i <= n; i++){
			if(vis[i]) z = z + pow(2, n - i);
		}
		if(sum > maxn * 2 && !vis[z]){
			vis[z] = 1;
			ans = (ans + 1) % mod;
		} 	
	}
	vis[t] = 1;
	int z = max(maxn, a[t]);
	dfs(t + 1, sum + a[t], z);
	vis[t] = 0;
	dfs(t + 1, sum, maxn);
	
}
int dp[N], cnt, c[N][N];
init(){
	c[1][1] = 1;
	for(int i = 2; i <= n; i++){
		for(int j = 1; j <= i; j++){
			if(j == 1){
				c[i][j] = i;
				continue;
			} 
			if(i == j){
				c[i][j] = 1;
				continue;
			} 
			c[i][j] = (c[i - 1][j - 1] + c[i - 1][j]) % mod;
		}
	}
}
signed main(){
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	n = read();
	for(int i = 1; i <= n; i++){
		a[i] = read();
		if(a[i] == 1) cnt++;
	} 
	if(n <= 11){
		dfs(1, 0, 0);
		printf("%lld", ans % mod);
		return 0;
	} 
	if(cnt == n){
		init();
		for(int i = 3; i <= n; i++)
			ans = (ans + c[n][i]) % mod;
		printf("%lld", ans % mod);
		return 0;
	}
	dp[0] = 1;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			dp[j] = max(dp[j], (dp[j - 1] + a[i]) % mod);
		}
	}
	printf("%lld", dp[n] % mod);
	return 0;
}
