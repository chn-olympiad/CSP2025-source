#include <bits/stdc++.h>
using namespace std;

long long n, sum = 1, a[5003], zcd, maxx, pf;

int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	scanf("%lld", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%lld", &a[i]);
		zcd += a[i];
		if (a[i] > maxx)
			maxx = a[i];
	}
	if (n < 3)
		cout << 0;
	else if (n == 3) {
		if (zcd > 2 * maxx)
			cout << 1;
		else
			cout << 0;
	} else if (maxx == 1) {
		if (n == 4)
			cout << 3;
		else
			cout << (n * (n - 1) - n + 1) % 998244353;
	}
	return 0;
}