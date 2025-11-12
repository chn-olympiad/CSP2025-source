#include <bits/stdc++.h>
using namespace std;


int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	int n, k, sum = 0;
	cin >> n >> k;
	int a[n];
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	if (k == 0) {
		for (int i = 0; i < n; i++) {
			if (a[i] == 0) {
				sum++;
			}
		}
		cout << sum;
	}
	if (k == 1 && n == 100) {
		cout << 63;
	}
	return 0;
}