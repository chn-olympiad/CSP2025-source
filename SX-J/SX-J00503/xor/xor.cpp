#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	int n, k;
	cin >> n >> k;
	int a[10000];
	for (int i = 1; i <= n; i++) {
		cout << a[i];
	}
	for (int i = 1; i <= n; i++) {
		if (k == 0 && i <= n) {
			cout << 1;
		}
	}
	return 0;
}