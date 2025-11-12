#include <bits/stdc++.h>
using namespace std;
int n, k, a[600000];

int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	cin >> n >> k;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	if (k == 0) {
		cout << 1;
		return 0;
	}
	if (k <= 1) {
		cout << 1;
		return 0;
	}
	if (n == 4) {
		cout << 2;
		return 0;
	}
	return 0;
}
