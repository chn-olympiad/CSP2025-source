#include <bits/stdc++.h>
using namespace std;
int n, a[5010], sum;

int h(int i, int j) {
	int cmp = 0;
	for (int k = i; k <= j; k++) {
		cmp += a[k];
	}
	return cmp;
}

int maxx(int i, int j) {
	int cmp = 0;
	for (int k = i; k <= j; k++) {
		cmp = max(cmp, a[k]);
	}
	return cmp;
}

int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; i ++) {
		cin >> a[i];
	}
	for (int i = 1; i <= n; i ++) {
		for (int j = 1; j <= n; j++) {
			if (h(i, j) > 2 * maxx(i, j)) {
				sum++;
				sum %= 998244353;
			}
		}
	}
	cout << sum;
	return 0;
}