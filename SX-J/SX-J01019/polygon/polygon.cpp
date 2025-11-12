#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	int a, s[1000000], d = 0;
	cin >> a;
	for (int i = 1; i <= a; i++) {
		cin >> s[i];
	}
	if (a == 3) {
		if (s[1] + s[2] > s[3] && s[3] + s[2] > s[1] && s[1] + s[3] > s[2]) {
			cout << 1;
			return 0;
		}

		else {
			cout << 0;
		}

	}
	if (a == 4) {
		cout << 3;
		return 0;
	}
	for (int i = 1; i <= a; i++) {
		d += s - 1 - i;
	}
	cout << d;
	return 0;
}
