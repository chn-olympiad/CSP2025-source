#include <bits/stdc++.h>
using namespace std;
const int N = 5010; 
const int MOD = 998244353;
long long ans, f[N];
int n, a[N];
void dfs(int dep, int num, int sum, int maxn) {
	if (dep == n + 1) {
		if (sum > 2 * maxn && num >= 3) {
			ans++;
			ans %= MOD;
		}
		return;
	}
	dfs(dep + 1, num + 1, sum + a[dep], max(maxn, a[dep]));
	dfs(dep + 1, num, sum, maxn);
}
int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	ios:: sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	dfs(1, 0, 0, 0);
	cout << ans;
	return 0;
}

