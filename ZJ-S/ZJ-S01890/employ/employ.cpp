#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 505, P = 998244353;

bool s[N], tpA = 1, vis[N];
int n, m, ans, a[N], h[N];

signed main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		char c; cin >> c;
		if (c == '1') s[i] = 1; 
		else tpA = 0;
	}
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	sort(a + 1, a + n + 1, greater < int > ());
	if (tpA) {
		int cnt = 0;
		for (int i = 1; i <= n; i++)
			if (a[i] == 0) cnt++;
		ans = 1;
		for (int i = 1; i <= n - cnt; i++)
			ans = ans * i % P;
		cout << ans << '\n'; exit(0);
	}
	for (int i = n; i >= m; i--)
		if (a[i]) ans = ans * a[i] % P;
	cout << ans << '\n'; 
	return 0;
}

