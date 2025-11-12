#include <bits/stdc++.h>
using namespace std;

int a[5005] = {0};

int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	if (n < 3) {
		cout << 0;
		return 0;
	} else if (n == 3) {
		int s = a[0] + a[1] + a[2];
		int sm = max({a[0], a[1], a[2]});
		if (s > sm * 2) {
			cout << 1;
		} else {
			cout << 0;
		}
		return 0;
	} else {
		int t = 0;
		for (int i = 1; i <= n; i++) {
			for (int j = 3; j <= n; j++) {
				if (j + i <= n + 1) {
					int s = 0;
					int sm = 0;
					for (int m = i; m < i + j; m++) {
						s += a[m];
						sm = max(sm, a[m]);
					}
					if (s > sm * 2) {
						t++;
					}
				}
			}
		}
		cout << t % 998244353;
	}
	return 0;
}
