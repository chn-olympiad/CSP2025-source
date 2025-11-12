#include <bits/stdc++.h>
using namespace std;
int n, k, a[500010], b[500010];
int o, ans = 0;

void c(int i) {
	if (i >= n) {
		return;
	}
	if (b[i] == -1) {
		c(i + 1);
	} else {
		o++;
		c(b[i] + 1);
	}
}

int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	long long s = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = i ; j <= n; j++) {
			if (j == i) {
				s = a[i];
			} else {
				s ^= a[j];
			}
			if (s == k) {
				b[i] = j;
				break;
			}
		}
		if (s != k) {
			b[i] = -1;
		}
		s = 0;
	}
	for (int i = 1; i <= n; i++) {
		c(i);
		ans = max(ans, o);
		o = 0;
	}
	cout << ans;
	return 0;
}
