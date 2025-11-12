#include <bits/stdc++.h>
using namespace std;
int l1, r1, l2, r2;
int a[50010];

int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	int n, k, sum = 0, he = 0, yi = 0;
	cin >> n >> k;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	for (l1 = 1; l1 <= n / 2 + 1; l1++) {
		for (r1 = l1; r1 <= n / 2 + 1; r1++) {
			for (int i = l1; i <= r1; i++)
				he += a[i];
			if (he == k ) {
				sum++;
				cout << l1 << r1;
			}
		}

		for (l2 = r1; l2 <= n; l2++) {
			for (r2 = l2; r2 <= n; r2++) {
				for (int i = l2; i <= r2; i++)
					yi = (yi | a[i]);
				if (yi == k && l2 != l1 && r2 != r1) {
					sum++;
					cout << l2 << r2;
				}
			}
		}
	}
	cout << sum;
	return 0;
}
