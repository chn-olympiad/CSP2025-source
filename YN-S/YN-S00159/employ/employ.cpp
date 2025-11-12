// code by Lyd1107 CSP-S 复赛 2025-11-01
#include <bits/stdc++.h>
using namespace std;

namespace my_namespace {
	const int mod =  998244353;
	int n;
	int m;
	string s;
	unsigned long long ans = 1;
	int main() {
		freopen("employ.in", "r", stdin);
		freopen("employ.out", "w", stdout);
		ios::sync_with_stdio(0);
		cin.tie();
		cin >> n >> m;
		cin >> s;
		int zong = n;
		for (int i = 1; i <= n; i++) {
			int c;
			cin >> c;
			// c[i]可以等于0
			if (c == 0) {
				zong--;
			}
		}
		for (int i = 1; i <= n; i++) {
			ans *= n;
			ans %= mod;
		}
		cout << ans << '\n';
		return 0;
	}
}

int main() {
	return my_namespace::main();
}

