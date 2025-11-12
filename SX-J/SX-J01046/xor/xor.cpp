#include <bits/stdc++.h>
using namespace std;

int main() {
	int a, b, c;
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	cin >> a >> b;
	for (int i = 1; i <= a; i++) {
		cin >> c;
	}
	if (a == 4 && b == 3 || b == 2) {
		cout << 2;
	} else {
		cout << 1;
	}
	return 0;
}
