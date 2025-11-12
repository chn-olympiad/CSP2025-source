// code by Lyd1107 CSP-S ¸´Èü 2025-11-01
#include <bits/stdc++.h>
using namespace std;

namespace my_namespace {
	short T;
	int n;
	const int N = 1e5 + 5;
	short a[N];
	short b[N];
	short c[N];

	int A;
	int B;
	int C;

	int cant;
	int dp[N];
	int st = 1;

	int main() {
		freopen("club.in", "r", stdin);
		freopen("club.out", "w", stdout);
		ios::sync_with_stdio(0);
		cin.tie();
		cout.tie();
		cin >> T;
		A = B = C = 0;
		for (int iiii = 1; iiii <= T; iiii++) {
			cin >> n;
			for (int i = st; i <= n; i++) {
				dp[i] = -0x3f3f3f3f;
				cin >> a[i];
				cin >> b[i];
				cin >> c[i];
			}
			cant = n >> 1;
			dp[0] = 0;
			for (int i = 1; i <= n; i++) {
				dp[i] = max(dp[i], max(dp[i - 1] + a[i], max(dp[i - 1] + b[i], dp[i - 1] + c[i])));
			}
			int ans = -0x3f3f3f3f;
			for (int i = 1; i <= n; i++) {
				ans = max(ans, dp[i]);
			}
			cout << ans << '\n';
		}
		return 0;
	}
}

int main() {
	return my_namespace::main();
}