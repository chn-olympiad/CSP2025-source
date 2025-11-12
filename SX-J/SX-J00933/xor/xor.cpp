#include <bits/stdc++.h>
using namespace std;
long long n, k;
long long a[500005];
long long ans, sum;

int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	if (a[1] == k) {
		ans++;
	}
	for (int i = 2; i <= n; i++) {
		if (a[i] == k) {
			ans++;
		} else if (sum == 0) {
			sum = a[i];
		} else {
			sum = sum ^a[i];
		}
		if (sum == k) {
			ans++;
		}
	}
	cout << ans;
	return 0;
}
