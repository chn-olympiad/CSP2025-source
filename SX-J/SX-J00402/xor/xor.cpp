#include <bits/stdc++.h>
using namespace std;
long long a[5000005];
long long n, k, ans;

int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	cin >> n >> k;

	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for (int i = 1; i <= n; i++) {
		long long b = a[i];
		if (b == 0)
			continue;
		if (b == k) {
			ans++;
			continue;
		}
		for (int j = i + 1; j <= n; j++) {
			b = (b ^a[j]);
			if (b == k) {
				ans++;
				break;
			}
		}
	}
	cout << ans;
	return 0;
}
