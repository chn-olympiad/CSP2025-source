#include <bits/stdc++.h>
using namespace std;
long long n, a[5010], sum;

int main () {
	//freopen("polygon.in", "r", stdin);
	//freopen("polygon.out", "w", stdout);
	scanf("%lld", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%lld", &a[i]);
	}
	sort(a + 1, a + n + 1);
	bool ls = 1;
	for (int i = n; i >= 1; i--) {
		if (a[i] != 1) {
			ls = 0;
			break;
		}
	}
	if (ls) {
		int lssum = 1;
		for (int i = 3, i <= n, i++) {
			for (int j = 1; j <= i; i++) {
				lssum *= n - j + 1;
			}
			for (int j = 1; j <= i; i++) {
				lssum /= j;
			}
		}
		printf("%lld", lssum % 998244353);
	} else {
		if (n == 3) {
			for (i = 1; i <= n; i++) {
				for (j = i; j <= n; j++) {
					for (h = j; h <= n; h++) {
						if (i + j + h > 2 * max(h, (int)max(i, j))) {
							sum++;
							sum %= 998244353;
						}
					}
				}
			}
		}

	}
	return 0;
}
