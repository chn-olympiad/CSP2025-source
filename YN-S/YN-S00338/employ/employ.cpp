#include <bits/stdc++.h>
using namespace std;
#define int long long
int n, m;
long long sam = 0;
long long san;

signed main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		char x;
		cin >> x;
		if (x == '1') {
			sam++;
		}
	}
	if (sam < m) {
		cout << 0;
		return 0;
	}
	sam = 1;
	for (long long i = 1; i <= n; i++) {
		sam *= i;
		sam %= 998244353;
	}
	cout << sam % 998244353;
	return 0;
}
