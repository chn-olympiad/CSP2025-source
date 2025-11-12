#include <bits/stdc++.h>
using namespace std;
long long n, a[5010], s;

int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for (int i = 1; i <= n; i++) {
		if (i >= 3 && a[i] + a[i + 1] > 2 * i) {
			s++;
		}
	}
	cout << s % 998244353;
	return 0;
}
