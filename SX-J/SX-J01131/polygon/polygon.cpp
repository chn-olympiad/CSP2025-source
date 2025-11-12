#include <bits/stdc++.h>
using namespace std;
const int MOD = 998244353;
long long f[5005], a[5005], ans, n;

inline void dfs(int now, long long maxa, int sum) {
//	cout << now << ":" << maxa << "," << sum << "," << ans << endl;
	if (now == n + 1) {
		if (sum > maxa * 2 && sum != 0)
			ans++;
		return;
	}
	dfs(now + 1, max(maxa, a[now]), sum + a[now]);
	dfs(now + 1, maxa, sum);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	f[0] = 1;
	for (int i = 1; i <= n; i++)
		f[i] = f[i - 1] * i, f[i] %= MOD;
	dfs(1, 0, 0);
	cout << ans;
	return 0;
}
