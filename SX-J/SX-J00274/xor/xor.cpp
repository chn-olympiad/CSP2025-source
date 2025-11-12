#include <bits/stdc++.h>
using namespace std;
int xl[500010];

int main() {

	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	long long n, k, a1 = 0, b1 = 0;
	bool a = 1;
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> xl[i];
		if (xl[i] == 0)
			a = 0;
		if (xl[i] == 0)
			a1++;
		if (xl[i] == 1)
			b1++;
	}
	xl[n + 1] = 9;
//	long long ans = 0;
//	for (int i = 1; i <= n; i++)
//		ans += pow(n, i);
//	cout << ans;
	if (k == 0 && a == 1) {
		cout << n / 2;
		return 0;
	}
	if (k == 0 && a == 0) {
		int d = 0;
		int ans = 0;
		ans += a1;
		for (int i = 1; i <= n; i++) {
			if (xl[i] == 0 && xl[i + 1] == 0)
				d++;
			else {
				d += 1;
				ans += d / 2;
			}
		}
		cout << d;
		return 0;
	}
	if (k == 1 && a == 0) {
		int d = 0;
		int ans = 0;
		ans += b1;
		for (int i = 1; i <= n; i++) {
			if (xl[i] == 1 && xl[i + 1] == 1)
				d++;
			else {
				d += 1;
				ans += d / 2;
			}
		}
		cout << d;
		return 0;
	}
	if (k == 1 && a == 1) {
		int ans = 0;
		cout << b1;
		return 0;
	}
	return 0;
}
