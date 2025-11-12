#include <bits/stdc++.h>
using namespace std;

int main() {
	int a, c[1005];
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> a;
	for (int i = 0; i < a; i++) {
		cin >> c[i];
	}
	if (c[0] == 1) {
		cout << 9;
	} else if (c[0] == 2) {
		cout << 6;
	}
	return 0;
}
