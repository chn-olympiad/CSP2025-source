#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	int n, k, sum = 0;
	cin >> n >> k;
	int a[n + 2];
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for (int l = 1; l <= n; l++) {
		int num = 0;
		for (int r = l; r <= n; r++) {
			num = ~((-num &(-a[r])));
			if (num == k) {
				sum++;
				l = l + 1;
				r = l;
			}
		}
	}
	cout << sum;
	return 0;
}

