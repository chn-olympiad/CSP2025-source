#include <bits/stdc++.h>
using namespace std;
const int mod_ = 998244353;

int a0[501] = {1};

int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	int n;
	cin >> n;
	bool tmp1 = 1;
	for (int i = 1; i <= n; i ++) {
		cin >> a0[i];
		if (a0[i - 1] != a0[i])
			tmp1 = 0;
	}
	if (tmp1) {
		long long ans = 1;
		int p = n - 3;
		while (p) {
			ans *= 2;
			ans %= mod_;
			p -- ;
		}
		cout << ans;
		return 0;
	}
	sort(a0 + 1, a0 + n + 1);
	if (a0[1] + a0[2] > a0[3])
		cout << "1";
	else
		cout << "0";
	return 0;
}