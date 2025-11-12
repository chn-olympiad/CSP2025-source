#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	int n, k;
	cin >> n >> k;
	if (n <= 2 && k == 0) {
		int pd = 0, c;
		for (int m = 1; m <= n; m++) {
			cin >> c;
			if (c == 0) {
				pd = 1;
			}
		}
		if (pd == 1) {
			cout << 1 << endl;
		} else {
			cout << 0 << endl;
		}
	}
	return 0;
}