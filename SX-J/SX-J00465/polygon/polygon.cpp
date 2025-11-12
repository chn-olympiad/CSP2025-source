#include <bits/stdc++.h>
#define endl "\n"

using namespace std;
using lnt = long long;
const int MOD = 998244353;

int n, a[5010], mmax = 0;
lnt sum;

signed main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
		mmax = max(a[i], mmax);
		sum += a[i];
	}

	if (n >= 3 && sum > 2 * mmax) {
		cout << 1 << endl;
	} else {
		cout << 0 << endl;
	}

	return 0;
}
