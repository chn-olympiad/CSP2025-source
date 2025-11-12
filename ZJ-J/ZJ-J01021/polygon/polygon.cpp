#include <bits/stdc++.h>
#define MOD 998244353
#define int long long
using namespace std;
signed main() {
	freopen("polygon4.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int n;
	cin >> n;
	vector<int> a(n + 1);
	for (int i = 1; i <= n; i += 1) {
		cin >> a[i];
	}
	int ans = 0;
	list<int> select;
	function<void(int)> dfs = [&select, &ans, &a, &n, &dfs](int i) -> void {
		if (i > n) {
			if (select.size() >= 3) {
				int maxn = 0;
				int sum = 0;
				for (auto data : select) {
					maxn = max(maxn, data);
					sum += data; 
				}
				if (sum > maxn * 2) {
					ans += 1;
					ans %= MOD;
				}
			}
			return;
		}
		select.push_back(a[i]);
		dfs(i + 1);
		select.pop_back();
		dfs(i + 1);
	};
	dfs(1);
	cout << ans << endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
