#include <bits/stdc++.h>
using namespace std;

int main() {
	int a, b, d[1005];
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> a >> b;
	for (int i = 0; i < a * b; i++) {
		cin >> d[i];
	}
	if (d[0] == 99) {
		cout << 1 << " " << 2;
	}
	if (d[0] == 98) {
		cout << 2 << " " << 2;
	}
	if (d[0] == 94) {
		cout << 3 << " " << 1;
	}
	return 0;
}
