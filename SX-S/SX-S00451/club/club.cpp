#include <bits/stdc++.h>
using namespace std;
long long t, n, maxx, sum;
long long a[10000005], b[10000005], c[10000005];

int main() {
	freopen("club.in", "r", stdin);
	freopen ("club.out", "w", stdout);
	cin >> t;
	for (int i = 1; i <= t; i++) {
		cin >> n;
		sum = 0;
		for (int j = 1; j <= n; j++) {
			cin >> a[i] >> b[i] >> c[i];
			if (a[i] > c[i] && a[i] > b[i]) {
				sum += a[i];
			} else if (b[i] > a[i] && b[i] > c[i]) {
				sum += b[i];
			} else if (c[i] > a[i] && c[i] > b[i]) {
				sum += c[i];
			}
		}
		cout << sum << endl;
	}
	return 0;
}
