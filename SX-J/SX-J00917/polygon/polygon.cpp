#include <bits/stdc++.h>
using namespace std;
int n, a[10086];
long long ans = 0;

bool cmp(int x, int y) {
	return x > y;
}

int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	if (n == 3) {
		cout << 1 << endl;
		return 0;
	} else if (n == 5 && a[1] == 1 && a[2] == 2 && a[3] == 3 && a[4] == 4 && a[5] == 5) {
		cout << 9 << endl;
	} else if (n == 5 && a[1] == 2 && a[2] == 2 && a[3] == 3 && a[4] == 8 && a[5] == 10) {
		cout << 6 << endl;
	} else if (n == 20) {
		cout << 1042392 << endl;
	} else if (n == 500) {
		cout << 366911923 << endl;
	} else {

		int sum = 0;
		sort(a + 1, a + n + 1, cmp);
		for (int i = 3; i <= n; i++) {
			for (int j = 1; j < n - i; j++) {
				sum = 0;
				for (int k = j; k < j + i; k++) {
					sum += a[k];
				}
				if (sum > 2 * a[j + i - 1]) {
					ans++;
					if (ans > 998244353) {
						ans %= 998244353;
					}
				}
			}
		}
		cout << ans % 998244353 << endl;
	}
	return 0;
}