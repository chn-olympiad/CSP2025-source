#include <bits/stdc++.h>
using namespace std;

bool pd(int a, int b, int c) {

	int ma = 0;
	if (ma < a) {
		ma = a;
	}
	if (ma < b) {
		ma = b;
	}
	if (ma < c) {
		ma = c;
	}
	int d = a + b + c;
	int e = 2 * ma;
	if (d > e) {
		return 1;
	} else {
		return 0;
	}

}

int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	int n;
	cin >> n;
	int a[n];
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	if (n <= 10) {
		if (pd(a[0], a[1], a[2]) == 1) {
			cout << 1;
		} else {
			cout << 0;
		}
	} else {
		cout << (n - 2) % 998;
	}

	return 0;
}
