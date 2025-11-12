#include <bits/stdc++.h>
using namespace std;
const int MOD = 998244353;
int n, m, a[500], ans, oo;

int A(int n, int m) {
	int yy = 1;
	for (int i = n - m + 1; i <= n; i++) {
		yy = ((yy % MOD) * (i % MOD)) % MOD;
	}
}
bool flag = true;
string s;

int main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	cin >> n >> m;
	cin >> s;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == '0') {
			flag = false;
			break;
		}
	}
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		if (a[i] != 0) {
			oo++;
		}
	}
	if (flag) {

		sort(a + 1, a + n + 1);
		for (int i = 1; i <= n; i++) {
			if (a[i] >= i) {
				ans++;
				ans %= MOD;
			} else {
				break;
			}
		}
		cout << A(m, ans);
		return 0;
	}
	cout << 0;
	return 0;
}