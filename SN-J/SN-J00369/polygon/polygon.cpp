//SN-J00369 张正轩 西安高新第一中学 
#include<bits/stdc++.h>
using namespace std;
int n, a[5005], ans = 0, mod = 998244353;
void dfs(int sum, int maxx, int s) {
	if (s == n + 1) {
		if (sum > maxx * 2) {
			ans++;
			ans %= mod;
		}
		return ;
	}
	dfs(sum, maxx, s + 1);
	dfs(sum + a[s], max(maxx, a[s]), s + 1);
}
int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	int mx;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		mx = max(mx, a[i]);
	}
	if (mx > 1) {
		dfs(0, 0, 1);
		cout << ans;
	}
	return 0;
}
