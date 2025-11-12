#include <bits/stdc++.h>
#define int long long
#define endl "\n"
#define File(x) freopen(x".in", "r", stdin), freopen(x".out", "w", stdout)
using namespace std;
const int N = 5e2 + 10, mod = 998244353;
int n, m, tot, c[N], ans;
bool vis[N];
string s;
void dfs(int x, int num) {
	if (x == n + 1) {
		if (n - num >= m) ans = (ans + 1) % mod;
		return;
	}
	for (int i = 1; i <= n; i ++) {
		if (!vis[i]) {
			vis[i] = 1;
			dfs(x + 1, num + ((s[x] == '0') || (num >= c[i])));
			vis[i] = 0;
		}
	}
}
signed main() {
	File("employ");
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> n >> m;
	cin >> s;
	for (int i = 1; i <= n; i ++) {
		cin >> c[i];
		if (c[i] == 0) tot ++;
	}
	s = '#' + s;
	bool f = 0;
	for (int i = 1; i <= n; i ++) {
		if (s[i] == '0') f = 1;
	}
	if (!f) {
		if (n - tot >= m) {
			int ans = 1;
			for (int i = 1; i <= n; i ++) ans = ans * i % mod;
			cout << ans << endl;
		}
		else cout << 0;
		return 0;
	}
	if (m == n) {
		if (f || tot > 0) cout << 0 << endl;
		else {
			int ans = 1;
			for (int i = 1; i <= n; i ++) ans = ans * i % mod;
			cout << ans << endl;
		}
		return 0;
	}
	dfs(1, 0);
	cout << ans << endl;
	return 0;
}
