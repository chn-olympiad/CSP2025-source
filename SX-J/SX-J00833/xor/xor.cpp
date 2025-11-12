#include <bits/stdc++.h>
using namespace std;
#define N 500001
#define M 2000001
int maxx, n, a[N], k, f[N];
int sum[N];

inline int g(int l, int r) {
	return (sum[r] xor sum[l - 1]);
}

int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		sum[i] = (a[i] xor sum[i - 1]);
		maxx = max(maxx, a[i]);
	}
	if (k > maxx) {
		cout << 0;
		return 0;
	}
	if (maxx != 1) {
		if (a[1] == k)
			f[1] = 1;
		for (int i = 2; i <= n; i++) {
			f[i] = f[i - 1];
			for (int j = 1; j <= i; j++) {
				if (g( j, i) == k) {
					f[i] = max(f[i], f[j - 1] + 1);
				}
			}
		}
		cout << f[n];
		return 0;
	} else {
		if (k == 0) {
			int ans = 0;
			for (int i = 1; i <= n; i++) {
				if (i < n) {
					if (a[i] == 1 && a[i + 1] == 1) {
						i++;
						ans++;
					}
				}
				if (a[i] == 0) {
					ans++;
				}
			}
			cout << ans;
			return 0;
		}
		if (k == 1) {
			int ans = 0;
			for (int i = 1; i <= n; i++) {
				if (a[i] == 1)
					ans++;
			}
			cout << ans;
			return 0;
		}
	}
	return 0;
}
