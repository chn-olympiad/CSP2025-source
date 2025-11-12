#include <bits/stdc++.h>
using namespace std;
long long t, a[10000010][5];

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin >> t;
	while (t--) {
		long long n;
		cin >> n;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= 3; j++) {
				cin >> a[i][j];
			}
		}
		for (long long i = 1; i <= n; i++) {
			sort(a[i] + 1, a[i] + 4);
		}
		long long sum = 0;
		for (long long i = 1; i <= n; i++) {
			sum += a[i][3];
		}
		cout << sum << endl;
	}
	return 0;
}
