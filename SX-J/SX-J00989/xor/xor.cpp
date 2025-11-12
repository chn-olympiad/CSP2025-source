#include <bits/stdc++.h>
using namespace std;
int a[1001];


int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	int n, k;
	cin >> n >> k;

	int ans = 0;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		a[i] += a[i - 1];
	}

	for (int l = 1; l <= n; l++) {
		for (int r = l; r <= n; r++) {
			if (((a[r] - a[l - 1 ] ) == k || (a[r] - a[l - 1 ] ) == k * k || (a[r] - a[l - 1 ] ) == k * k * k) && a[l] != 0
			        && a[r] != 0) {
				ans++;
			}

		}
	}
	cout << ans;
	return 0;

}
