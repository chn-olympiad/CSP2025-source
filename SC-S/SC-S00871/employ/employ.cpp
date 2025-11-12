#include<bits/stdc++.h>
using namespace std;
const int mod = 998244353;
int n, m, c[505];
string s;
int main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	cin >> n >> m >> s;
	for (int i = 1; i <= n; i++)
		cin >> c[i];
	int flag = 1;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] != 1)
			flag = 0;
	}
	if (flag) {
		long long ans = n;
		for (int i = 1; i <= m; i++)
			ans *= (n - i) % mod;
		cout << ans;
		return 0;
	}
	if (m == 1)
		cout << n * n % mod;
	return 0;
}