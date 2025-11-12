#include <bits/stdc++.h>
using namespace std;
string s;

int main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	int n, m, a[1000];
	cin >> n >> m;
	cin >> s;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	sort(a + 1, a + n + 1);
	int ans = 0;
	for (int i = 1; i < n; i++) {
		if (s[i - 1] == s[i] && s[i] == '1') {
			ans++;
		}
	}
	int a1b = 1;
	if (ans + 1 == n) {
		for (int i = 1; i <= n; i++) {
			a1b *= i;
		}
		cout << a1b % 998244353;
		return 0;
	}
	int cnt = 0, sum = 0;
	for (int i = 0; i < n; i++) {
		if (s[i] == '1' && a[i + 1] - sum >= 0) {
			cnt++;
		} else {
			sum++;
		}
	}
	cout << cnt % 998244353;
	return 0;
}