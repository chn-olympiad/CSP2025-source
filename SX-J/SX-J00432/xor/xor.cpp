#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	int n, k, s = 0;
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		int b;
		cin >> b;
		if (b == 1) {
			s++;
		}
	}
	if (k == 0) {
		cout << s / 2;
	} else {
		cout << s;
	}
	return 0;
}
