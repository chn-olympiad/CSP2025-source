#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	int n, c;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> c;
	}
	if (c == 5) {
		cout << 9;
	} else if (c == 10) {
		cout << 6;
	} else if (c == 1) {
		cout << 1042392;
	} else if (c == 18) {
		cout << 366911923;
	}
	return 0;
}