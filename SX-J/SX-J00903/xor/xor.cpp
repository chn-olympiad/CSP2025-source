#include <bits/stdc++.h>
using namespace std;
int ma[500010], a[500010], b[500010], k, n, f1, f2, cnt, cnt1;

int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		if (a[i] == 1)
			cnt++;
		if (a[i] == 1 && a[i - 1] == 1 && !b[i - 1]) {
			cnt1++;
			b[i] = 1;
		}
		if (a[i] != 1)
			f1 = true;
		if (a[i] > 1)
			f2 = true;
		ma[i] = ma[i - 1] ^ a[i];
	}
	if (!f1) {
		if (k > 1)
			cout << 0;
		else if (k == 1)
			cout << n;
		else
			cout << n / 2;
	} else if (!f2) {
		if (k > 1)
			cout << 0;
		else if (k == 1)
			cout << cnt;
		else
			cout << n - cnt + cnt1;
	} else {
		cnt = 0;
		memset(b, 0, sizeof(b));
		bool f = 0;
		for (int len = 1; len <= n; len++) {
			f = 0;
			for (int l = 1; l <= n - len + 1; l++) {
				int r = l + len - 1;
				if (f == 0) {
					bool f1 = 0;
					for (int i = l; i <= r; i++) {
						if (b[i]) {
							l = i;
							f1 = 1;
							break;
						}
					}
					if (f1)
						continue;
					f = 1;
				}
				if (b[r] == 1) {
					l = r;
					f = 0;
					continue;
				}
				if ((ma[l - 1]^ma[r]) == k) {
					cnt++;
					for (int i = l; i <= r; i++) {
						b[i] = 1;
					}
				}
			}
		}
		cout << cnt;
	}
	return 0;
}
