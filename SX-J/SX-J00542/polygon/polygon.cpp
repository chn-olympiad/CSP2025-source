#include <bits/stdc++.h>
using namespace std;
long long n, m, s, a[6000], ans, sss = 1;
bool ss = 1;

inline int suan(long long d) {
	if (d < 3)
		return 1;
	if (d == 3) {
		int aans;
		for (int i = 1; i <= n; i++) {
			for (int j = i + 1; j <= n; j++) {
				for (int k = j + 1; k <= n; k++) {
					if (a[i] + a[j] + a[k] > (max(a[i], max(a[j], a[k]))) * 2)
						aans++;
					aans %= 998244353;
				}
			}
		}
		return aans;
	}
	return suan(d - 1) % 998244353;
}


int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> n;

	for (long long i = 1; i <= n; i++) {
		cin >> a[i];
		if (a[i] != 1)
			ss = 0;
	}

	if (ss) {
		n -= 3;
		ans = (6 + n) * n - n;
		ans /= 2;
		ans += 1;
		ans = ans % 998244353;
		cout << ans;
		return 0;

	} else {
		if (n == 3) {
			if (a[1] + a[2] + a[3] > max(a[1], max(a[2], a[3])) * 2)
				cout << 1;
			else {
				cout << 0;
			}

		} else {
			for (int i = 1; i <= n - 2; i++) {
				ans += sss;
				sss += 2;
			}
			cout << ans;
		}
	}
	return 0;
}

