#include<bits/stdc++.h>
using namespace std;
const long long N = 1e4 + 10;
long long a[N];
const long long mod = 998244353;
long long n;
long long ans = 0;
void dfs(long long x, long long ma, long long sum, long long g, long long last) {
	if(x > n + 1) return;
	if((sum > (ma * 2)) && (g > 2) && sum != last) {
		ans++, ans %= mod;
		dfs(x + 1, max(ma, a[x]), sum + a[x], g + 1, sum);
		dfs(x + 1, ma, sum, g, sum);
	}
	else {
		dfs(x + 1, max(ma, a[x]), sum + a[x], g + 1, sum);
		dfs(x + 1, ma, sum, g, sum);
	}
	return ;
}
int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> n;
	for(long long i = 1; i <= n; i++) cin >> a[i];
	dfs(1, 0, 0, 0, 0);
	cout << ans << endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
