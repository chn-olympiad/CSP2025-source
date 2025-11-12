#include <bits/stdc++.h>
//#define int long long
using namespace std;
const int N = 2e2 + 10;
int T, a[N], b[N], c[N], n, ans, f[N][N];
void dfs(int x, int s1, int s2, int s3, int sum) {
	if(x == n) {
		if(s1 <= n / 2 && s2 <= n / 2 && s3 <= n / 2) {
			ans = max(ans, sum);
		}
		else return;
	}
	if((s1 + 1) <= n / 2) dfs(x + 1, s1 + 1, s2, s3, sum + a[x + 1]);
	if((s2 + 1) <= n / 2) dfs(x + 1, s1, s2 + 1, s3, sum + b[x + 1]);
	if((s3 + 1) <= n / 2) dfs(x + 1, s1, s2, s3 + 1, sum + c[x + 1]);
}
void solve() {
	ans = -1;
	bool can = 1;
	cin >> n;
	for (int i = 1; i <= n; i ++) {
		cin >> a[i] >> b[i] >> c[i];
		if(!(b[i] == 0 && c[i] == 0)) can = 0;
	}
	if(can) {
		int ans = 0;
		sort(a + 1, a + n + 1, greater<int>());
		for (int i = 1; i <= n / 2; i ++) ans += a[i];
		cout << ans << "\n";
		return;
	}
	else{
		dfs(0, 0, 0, 0, 0);
		cout << ans << "\n";
		return;
	}
}
signed main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> T;
	while(T --) {
		solve();
	}
	return 0;
}