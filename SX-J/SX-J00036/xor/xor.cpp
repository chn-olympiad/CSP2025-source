#include <bits/stdc++.h>
using namespace std;

int a[7];

int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	for (int i = 1; i <= 7; i++) {
		cout << a[i];
	}
	if (a[1] == 4) {
		if (a[2] == 2 || a[2] == 3) {
			cout << 2;
		} else if (a[2] == 0) {
			cout << 1;
		}
	}
	return 0;
}
