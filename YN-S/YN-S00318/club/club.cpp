#include <bits/stdc++.h>
using namespace std;
long long a[100005][3], b[20005];

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int t;
	cin >> t;
	for (int k = 1; k <= t; k++) {
		int n, maxx = 0, sum = 0;
		cin >> n;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= 3; j++) {
				cin >> a[i][j];
				if (j == 1)
					b[i] = a[i][j];
			}
		}
		sort(b + 1, b + n + 1);
		for (int i = n; i >= n / 2 + 1; i--) {
			sum += b[i];
		}
		cout << sum;
	}

	return 0;
}
