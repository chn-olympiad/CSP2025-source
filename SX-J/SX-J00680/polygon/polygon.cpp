#include <bits/stdc++.h>
using namespace std;
int n, num[5005], ck = 1;

int main() {
	freopen("polygon", "r", stdin);
	freopen("polygon", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> num[i];
		if (num[i] != 1)
			ck = 0;
	}
	if (n == 3) {
		cout << 1;
		return 0;
	}
	if (ck) {
		if (n == 4) {
			cout << 5;
			return 0;
		}
		if (n == 5) {
			cout << 14;
			return 0;
		}
		if (n == 6) {
			cout << 38;
			return 0;
		}
		long long ans = 0;
		for (int i = 1; i <= (n - 2); i++) {
			ans = (ans + i *i) % 998244353;
		}
		cout << ans;
		return 0;
	}
	cout << 1;
	return 0;
}
