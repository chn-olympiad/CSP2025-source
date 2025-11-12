#include <bits/stdc++.h>
using namespace std;
int n, k, a[100010], s[100010], f[100010], ans, fl;

int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		s[i] = (s[i - 1] ^ a[i]);
	}
	for (int i = 1; i <= n; i++) {
		for (int j = i; j <= n; j++) {
			fl = 1;
			for (int x = i; x <= j; x++) {
				if (f[x] == -1) {
					fl = 0;
					break;
				}
			}
			if (fl == 0)
				break;
			if ((s[j]^s[i - 1]) == k) {
				ans++;
				for (int x = i; x <= j; x++) {
					f[x] = -1;
				}
			}
		}
	}
	cout << ans;
	return 0;
}
