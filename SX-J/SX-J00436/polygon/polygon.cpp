#include <bits/stdc++.h>
using namespace std;

int main() {
//	freopen("number.in", stdin);
//	freopen("number.out", stdout);
	int n, sum;
	cin >> n;
	int a[5000];
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			for (int k = i + 2; k < n; k++) {
				int z, d = INT_MIN;
				z = a[i] + a[j] + a[k];
				for (int s = 0; s < 3; s++) {
					if (s == 0) {
						if (a[i] > d) {
							d = a[i];
						}
						if (a[j] > d) {
							d = a[j];
						}
						if (a[k] > d) {
							d = a[k];
						}
					}
				}
				if (z > d * 2) {
					sum++;
				}
			}
		}
	}
	cout << sum;
	return 0;
}
