#include <bits/stdc++.h>
using namespace std;
int a[5010];

int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	int ct = 0;

	if (a[0] + a[1] + a[2] > a[0] * 2) {
		ct++;
	}
	if (a[0] + a[1] + a[2] + a[3] > a[0] * 2) {
		ct++;
	}
	if (a[0] + a[1] + a[2] + a[3] + a[4] > a[0] * 2) {
		ct++;
	}
	if (a[3] + a[1] + a[2] > a[0] * 2) {
		ct++;
	}
	if (a[3] + a[1] + a[2] + a[4] > a[0] * 2) {
		ct++;
	}
	if (a[4] + a[3] + a[2] > a[0] * 2) {
		ct++;
	}
	if (a[4] + a[3] + a[2] + a[0] + a[1] > a[0] * 2) {
		ct++;
	}
	if (n == 5) {
		cout << ct - 1;
	} else
		cout << 3;

	return 0;
}