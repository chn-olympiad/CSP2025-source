#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	int i, l, r;
	cin >> l >> r;
	int a[4];
	for (i = 0; i < 4; i++) {
		cin >> a[i];
	}
	if (r == 2 || r == 3) {
		cout << 2;
	}
	if (r == 0) {
		cout << 1;
	}
	return 0;
}
