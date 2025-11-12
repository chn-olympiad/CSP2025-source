#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int mod = 998244353;
int n, m, a[505], b[505], sum[505], t[505];
ll ans;
string s;
bool f[505];
void dfs(int cnt) {
	if (cnt == n + 1) {
		bool f = 1;
		for (int i = 1; i <= n; ++i) {
			if (t[i] < sum[i]) {
				f = 0;
				break;
			}
			if (a[i] && t[i] == sum[i]) {
				f = 0;
				break;
			}
		}
		ans += f;
		ans %= 998244353;
		return ;
	}
	for (int i = 1; i <= n; ++i) {
		if (!f[i]) {
			t[cnt] = b[i];
			f[i] = 1;
			dfs(cnt + 1);
			f[i] = 0;
		}
	}
	return ;
}
bool fg = 1;
int main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin >> n >> m >> s;
	for (int i = 0; i < n; ++i) {
		a[i + 1] = (s[i] == '0');
		sum[i + 1] = sum[i] + a[i + 1];
	}
	for (int i = 1; i <= n; ++i) {
		cin >> b[i];
		fg &= (a[i] == 1);
	}
	if (n <= 20) {
		dfs(1);
		cout << ans;
		return 0;
	}
	if (fg) {
		for (int i = m; i <= n; ++i) {
			ll cnt = 1;
			for (int j = 1; j <= n - m; ++j) {
				cnt *= j;
				cnt %= 998244353;
			}
			for (int j = 1; j <= m; ++j) {
				cnt *= j;
				cnt %= 998244353;
			}
			ans += cnt;
			ans %= 998244353;
		}
	}
	cout << ans;
	return 0;
}