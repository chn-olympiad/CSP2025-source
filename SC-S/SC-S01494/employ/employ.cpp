#include"bits/stdc++.h"
using namespace std;
const int N = 505, mod = 998244353;
int n, m, c[N];
string s;
bool can[N];
long long ans;
bool cmp(int x, int y) {
	if (!x)
		return 0;
	return x < y;
}
signed main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(0);
	cin >> n >> m >> s;
	for (int i = 0; i < s.size(); i++)
		can[i + 1] = s[i] - '0';
	for (int i = 1; i <= n; i++)
		cin >> c[i];
	bool xz_a = 1;
	for (int i = 1; i <= n; i++)
		xz_a &= can[i];
	if (xz_a) {
		sort(c + 1, c + 1 + n, cmp);
		int out = 0, cnt = 0;
		for (int i = 1; i <= n; i++)
			if (can[i] && c[i] > out)
				cnt++;
			else
				out++;
		if (cnt < m) {
			cout << 0;
			return 0;
		}
//		cnt = 0;
//		for (int i = 1; i <= n; i++)
//			cnt += (c[i] != 0);
//		if (cnt < m) {
//			cout << 0;
//			return 0;
//		}
		long long ans1 = 1, ans2 = 1;
		for (int i = 2; i <= cnt; i++)
			ans1 = ans1 * i % mod;
		for (int i = 2; i <= n - cnt; i++)
			ans2 = ans2 * i % mod;
		cout << ans1 << ' ' << ans2 << '\n';
		cout << (ans1 + ans2) % mod;
		return 0;
	} else if (n == m) {
		cout << 0;
		return 0;
	} else if (m == 1) {}
	else {
		vector<int>a(n);
		for (int i = 1; i <= n; i++)
			a[i - 1] = i;
		do {
//			for (int i=1;i<=n;i++)
//				cout<<c[a[i-1]]<<' ';
//			cout<<'\n';
			int out = 0, cnt = 0;
			for (int i = 1; i <= n; i++) {
				if (can[i] && c[a[i - 1]] > out)
					cnt++;
				else
					out++;
//				cout<<cnt<<' '<<out<<'\n';
			}
			if (cnt >= m)
				ans++;
		} while (next_permutation(a.begin(), a.end()));
		cout << ans;
	}
	return 0;
}