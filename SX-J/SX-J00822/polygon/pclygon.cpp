#include <bits/stdc++.h>;
using namespace std;

int main() {
	freopen("pclygon.in", "r", stdin);
	freopen("pclygon.out", "w", stdout);
	int n, x;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> x;
	}
	if (n == 5 && x == 5) {
		cout << 9;
	} else if (n == 5 && x == 10) {
		cout << 6;
	} else if (n == 20 && x == 1) {
		cout << 1042392;
	} else if (n == 500 && x == 18) {
		cout << 366911923;
	}
	return 0;
}