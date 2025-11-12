#include <bits/stdc++.h>
using namespace std;
int t;
long long a[100010][3], x[100010];
int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin >> t;
	while (t--) {
		long long n, ans = 0;
		cin >> n;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < 3; j++) cin >> a[i][j];
		}
		for (int i = 0; i < n; i++) {
			if (a[i][1] == 0 && a[i][2] == 0) x[i] = a[i][0];
		}
		sort(x, x + n);
		for (int i = n - 1; i >= n / 2; i--) ans += x[i];
		cout << ans;
	}
	return 0;
}
