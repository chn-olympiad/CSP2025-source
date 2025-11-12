#include <bits/stdc++.h>
using namespace std;
long long n, k, sum = 0, ssum = 0, maxx = 0;
long long a[100000005];

main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	if (k == 0) {
		for (int i = 1; i <= n; i++) {
			if (a[i] == 0) {
				sum++;
			}
		}
		cout << sum;
	}
	if (k == 1) {
		for (int i = 1; i <= n; i++) {

			if (a[i] == 0) {
				sum++;
			}
			if (a[i] == 1)
				ssum = 1;
		}
		cout << sum;
	}
	return 0;
}
//4 2
//2 1 0 3
