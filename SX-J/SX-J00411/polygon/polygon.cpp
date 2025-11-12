#include <bits/stdc++.h>
using namespace std;
long long n, sum = 0, ssum = 0, maxx = 0, num = 0;
long long a[50005];

main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for (int i = 1; i <= n; i++) {
		for (int j = i; j <= n; j++) {
			sum++;
			if (sum >= 3) {
				for (int k = i; k <= j; k++) {
					num += a[k];
					maxx = max(a[k], maxx);
				}
				if (num > (maxx * 2))
					ssum++;
			}
			num = 0;
		}
		sum = 0;
	}
	cout << ssum;
	return 0;
}
//5
//1 2 3 4 5
