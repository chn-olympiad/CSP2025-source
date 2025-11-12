#include <bits/stdc++.h>
using namespace std;
long long n, n1, m, a[100005], ans = 2, m1, m2, m3 = 1;
string s;
bool a1 = 1;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	cin >> n >> m;
	cin >> s;
	n1 = n;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == '0')
			m2++;
	}
	for (int i = 1; i <= n1; i++) {
		cin >> a[i];
		if (a[i] != 1 and a[i] != 0)
			a1 = 0;
		m1 += a[i];
		if (a[i] == 0)
			m2++;
	}
	if (a1) {
		if (m == 1)
			cout << n;
		if (m == 2)
			cout << n * n;
		else {
			for (int i = 3; i <= n; i++) {
				ans *= i;
				ans %= 998244353;
			}
			cout << ans;
		}
		return 0;
	}
	for (int i = 1; i <= n; i++) {
		m *= i;
		m %= 998244353;
	}
	if (m2) {
		for (int i = 1; i <= m2; i++) {
			m3 *= 2;
			m3 %= 998244353;
		}
		m %= m3;
	}
	cout << m;
	return 0;
}
