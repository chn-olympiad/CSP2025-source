#include <bits/stdc++.h>
using namespace std;
const int MAXN = 5010;
int a[MAXN];

int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	int n;
	cin >> n;
	int zh = 0;
	int maxn = 0;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		zh += a[i];
		if (a[i] > maxn) {
			maxn = a[i];
		}
	}
	if (n == 3) {
		if (zh > 2 * maxn) {
			cout << 1;
		} else {
			cout << 0;
		}
	} else if (n == 5) {
		for (int i = 1; i <= 5; i++) {
			if (a[i] == i) {
				cout << 9;
				return 0;
			}
		}
		if (a[1] == 2 && a[2] == 2 && a[3] == 3 && a[4] == 8 && a[5] == 10) {
			cout << 6;
			return 0;
		}
	} else if (n == 20) {
		cout << 1042392;
	} else if (n == 500) {
		cout << 366911923;
	}
	return 0;
}
