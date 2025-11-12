#include <bits/stdc++.h>
using namespace std;
int n, a[5000], qzh[5000], ans;

int maxl(int start, int end) {
	int l = 0;
	for (int i = start; i <= end; i++) {
		l = max(l, a[i]);
	}
	return l;
}

int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		qzh[i] = qzh[i - 1] + a[i];
	}
	for (int i = 1; i <= n; i++) {
		for (int j = i + 2; j <= n; j++) {
			if (qzh[j] - qzh[i - 1] > 2 * maxl(i, j)) {
				ans++;
			}
		}
	}
	cout << ans % 998244353;
}