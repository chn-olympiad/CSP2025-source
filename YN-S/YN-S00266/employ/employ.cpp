#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	int n, m, a, sum = 0, maxn = -1;
	int ab[200];
	cin >> n >> m >> a;
	for (int i = 1; i <= n; i++) {
		cin >> ab[i];
	}
	for (int i = 1; i <= n; i++) {
		if (ab[i] > maxn) {
			maxn = ab[i];
			sum++;
		}
	}
	if (n < m) {
		cout << m;
	}
	if (sum < m) {
		cout << m;
	} else {
		cout << sum - m;
	}
	return 0;
}