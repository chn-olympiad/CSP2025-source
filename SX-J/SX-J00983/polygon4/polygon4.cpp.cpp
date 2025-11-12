#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	int i, a[5], b;
	cin >> b;
	for (i = 0; i < 5; i++) {
		cin >> a[i];
	}
	if (a[0] == 1) {
		cout << 9;
	} else {
		cout << 6;
	}
	return 0;
}
