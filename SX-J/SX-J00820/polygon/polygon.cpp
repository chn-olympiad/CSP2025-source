#include <bits/stdc++.h>
using namespace std;
int a[5010];

int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	int n, sum = 0, maxe = -1;
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	sort(a, a + n);
	while (n--) {
		for (int i = 1; i <= n / 2; i++) {
			for (int j = 1; j <= n; j++) {
				if (i != j) {

					maxe = max(maxe, a[j]);
					int c = a[i] + a[j] ;
					if (c > 2 * maxe)
						sum++;
				}
			}
		}
	}
	cout << sum;
	return 0;
}
