#include <bits/stdc++.h>
using namespace std;
#define int long long
const int Mod = 998244353;
int n, m, cnt, cnt1;
string s;

signed main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	cin >> m >> n >> s;
	for (auto i : s) {
		if (i == '1')
			cnt++;
		else
			cnt1++;
	}
	if (cnt1 == s.size()) {
		cout << 0;
		return 0;
	}
	if (cnt == s.size()) {
		int sum = 1;
		for (int i = m; i >= 1; i--) {
			sum = (sum * i) % Mod;
			sum %= Mod;
		}
		int now = n - m, sum1 = 1;
		for (int i = now; i >= 1; i--) {
			sum1 = (sum1 * i) % Mod;
			sum1 %= Mod;
		}
		int sum2 = 1;
		for (int i = n; i >= 1; i--) {
			sum2 = (sum2 * i) % Mod;
			sum2 %= Mod;
		}
		cout << sum / (sum1 * sum2) << "\n";
		return 0;
	} else {
		cout << 0;
	}
	return 0;
}