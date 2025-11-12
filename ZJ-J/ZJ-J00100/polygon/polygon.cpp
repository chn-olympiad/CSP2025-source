#include <bits/stdc++.h>
using namespace std;
int MOD = 998244353;
int n, a[5005], ans = 0;
void dfs(int x, int maxx, int sum, int cnt){
	if (x > n){
		if (cnt < 3 || sum <= 2*maxx)  return ;
		ans = (ans + 1) % MOD;
		return ;
	}
	dfs(x+1, maxx, sum, cnt);
	dfs(x+1, max(maxx, a[x]), sum + a[x], cnt + 1);
	return ;
}
int c[5005][5005];
void pre(int n){
	for (int i=1; i <= n; i++)  c[i][0] = c[i][i] = 1;
	for (int i=2; i <= n; i++){
		for (int j=1; j < i; j++)  c[i][j] = (c[i-1][j-1] + c[i-1][j])%MOD;
	}
	return ;
}
/*int maxx, lenn, rh;
bool dp[505][505][505];
void check(int len, int x, int sum, int lf){
	if (dp[lf][rh][lenn - len]){
		ans = (ans + c[lf-1][len]) % MOD;
		return ;
	}
	if (x < 1 && len > 0)  return ;
	if (len == 0){
		if (sum > maxx){
			ans = (ans + 1) % MOD;
			dp[lf][rh][lenn] = 1;
		}
		return ;
	}
	check(len, x-1, sum, lf);
	check(len-1, x-1, sum + a[x], x);
	return ;
}*/
int main(){
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> n;
	for (int i=1; i <= n; i++)  cin >> a[i];
	sort(a+1, a+n+1);
	if (n <= 20){
		dfs(1, 0, 0, 0);
		cout << ans;
	}
	else if (a[n] == 1){
		pre(n);
		for (int i=3; i <= n; i++)  ans = (ans + c[n][i]) % MOD;
		cout << ans;
	}
	/*else if (n <= 500){
		pre(n);	
		for (int i=n; i >= 3; i--){
			maxx = a[i], rh = i;
			for (int j=3; j <= i; j++){
				lenn = j;
				check(j-1, i-1, 0, j);
			}
		}
		cout << ans;
	}*/
	return 0;
}
