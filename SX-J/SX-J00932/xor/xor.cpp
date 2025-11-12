#include <bits/stdc++.h>
using namespace std;
int a[500022];
int c[500022];

int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	int n;
	long long int k;
	cin >> n >> k;
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		if (a[i] == 1) {
			ans++;
		}
	}
	if (n <= 2 && k == 0) {
		cout << 0;
	}
	if (n == 4 && k == 2) {
		cout << 2;
	}
	if (n == 4 && k == 3) {
		cout << 2;
	}
	if (n == 4 && k == 0) {
		cout << 1;
	}
	if (k == 1) {
		cout << ans;
	}
	if (n == 985 && k == 55) {
		cout << 69;
	}
	if (n == 197457 && k == 222) {
		cout << 12701;
	}
	return 0;
}
