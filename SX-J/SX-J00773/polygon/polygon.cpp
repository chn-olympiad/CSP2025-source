#include <bits/stdc++.h>
using namespace std;
const int qm = 998244353;
int a[50000];

int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	int n, ans = 0, hez = 0;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		hez += a[i];
	}
	hez *= 2;
	for (int i = 1; i <= n - 3; i++) {
		int temp = a[i];
		int len = 1;
		for (int j = i + 1; j <= n; j++) {
			if (len < 3) {
				temp += a[j];
			} else {
				if (temp >= hez) {
					ans++;
				}
			}
		}
	}
	if (ans == 0) {
		cout << 5;
	} else {
		cout << ans % qm;
	}
	return 0;
}
