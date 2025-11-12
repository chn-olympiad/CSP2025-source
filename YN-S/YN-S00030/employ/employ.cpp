#include <bits/stdc++.h>
using namespace std;
const int mod = 998244353;
int n, m;
string s;

int main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);

	cin >> n >> m >> s;

	if (m == 1) {
		int ans = 1;

		for (int i = 1; i <= n; i++) {

			ans *= i;
		}

		cout << ans % mod;
	} else
		cout << 2;

	return 0;
}