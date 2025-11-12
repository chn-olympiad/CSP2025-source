#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("ciub.in", "r", stdin);
	freopen("ciub.out", "w", stdout);
	int t, n, a[100000], b[100000], c[100000], sum = 0;
	cin >> t;
	for (int i = 1; i <= t; i++) {
		cin >> n;
		sum = 0;
		for (int j = 0; j < n; j++) {
			cin >> a[j] >> b[j] >> c[j];
		}
		for (int j = 0; j < n; j++) {
			sum += max(a[j], max(b[j], c[j]));
		}
		cout << sum;
	}
	return 0;
}