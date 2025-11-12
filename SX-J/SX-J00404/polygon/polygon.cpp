#include <bits/stdc++.h>
using namespace std;
int n, sum = 0;
int a[5010];

int pd(int s) {

	return (s - 2) * (s - 1) * s / 6 / 2;
}

int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	sort(a, a + n);
	int dfg = 0;
	if (n < 3) {
		cout << 0;
	} else if (n == 3) {
		if (a[1] + a[0] > a[2]) {
			cout << 1;
		} else {
			cout << 0;
		}
	} else  if (n == 4) {
		if (a[1] + a[2] + a[3] + a[0] > a[3] * 2) {
			dfg++;
		}
		if (a[0] + a[1] > a[3]) {
			dfg++;
		}
		if (a[0] + a[2] > a[3]) {
			dfg++;
		}
		if (a[1] + a[2] > a[3]) {
			dfg++;
		}
		if (a[0] + a[1] > a[2]) {
			dfg++;
		}
		cout << dfg;
	} else {
		for (int i = n; i >= 3; i--) {
			sum += pd(i);
		}
		cout << sum % 998244353;
	}

	return 0;
}
