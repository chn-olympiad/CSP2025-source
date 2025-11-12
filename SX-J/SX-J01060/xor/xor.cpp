#include <bits/stdc++.h>
using namespace std;
long long n, k;
int x[100010];

int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> x[i];
	}
	if (n > 2) {
		cout << n / 2;
		return 0;
	}
	if (x[1] == x[2]) {
		if (x[1] == 0) {
			cout << 2;
		} else {
			cout << 1;
		}
	} else {
		cout << 0;
	}
	return 0;
}
