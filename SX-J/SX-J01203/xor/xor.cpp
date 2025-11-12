#include <bits/stdc++.h>
using namespace std;
long long n, k, a[5000005], c = 0, ans = 0;

int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	cin >> n >> k;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	if (k == 0) {
		for (int i = 1; i <= n; i++)
			if (a[i] != 1)
				c = 1;
		if (c == 0) {
			if (n % 2 == 1)
				cout << (n - 1) / 2;
			else
				cout << n / 2;
			return 0;
		}
		for (int i = 2; i <= n; i++) {
			if (a[i] == a[i - 1])
				ans++, i++;
			else	if (a[i - 1] == 0)
				ans++;
		}
	} else {
		for (int i = 2; i <= n; i++) {
			if (a[i] !=  a[i - 1])
				ans++, i++;
			else	if (a[i - 1] == 1)
				ans++;
		}
	}
	cout << ans;
	return 0;
}
