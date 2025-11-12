#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	int n, k, a[500005];
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	int sum = 0, cnt = 0;
	for (int i = 1; i <= n; i++) {
		if (a[i] == k) {
			cnt++;
			continue;
		}
		if (sum < k) {
			sum = sum ^a[i] ^ a[i + 1];
		}
		if (sum == k) {
			cnt++;
			sum = 0;
		}
	}
	cout << cnt;
	return 0;
}
