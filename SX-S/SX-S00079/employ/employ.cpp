#include <bits/stdc++.h>
using namespace std;
const int N = 501, M = 998244353;
int n, m, p[N], a[N];

signed main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	cin >> n >> m;
	string s;
	cin >> s;
	int sum = 0, jc = 1;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		sum += s[i - 1] - '0';
		jc = 1ll * jc * i % M;
	}
	if (sum == n) {
		cout << jc;
		return 0;
	} else if (sum < m) {
		cout << 0;
		return 0;
	}

	return 0;
}