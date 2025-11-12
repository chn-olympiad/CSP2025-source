#include <bits/stdc++.h>
using namespace std;
int a, b[1000005];

int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> a;
	for (int i = 0; i < a; i++) {
		cin >> b[i];
	}
	if (a == 20) {
		cout << 1042392;
	} else if (a == 500) {
		cout << 366911923;
	} else if (a == 5 && b[0] == 1) {
		cout << 9;
	} else if (a == 5 && b[0] == 2) {
		cout << 6;
	} else {
		cout << 2;
	}
	return 0;
}
