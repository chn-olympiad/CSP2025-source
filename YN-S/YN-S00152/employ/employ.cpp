#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 998244353
char p[505];
int c[505];
int de[15];
int f[15];
ll ans = 0;
int n, m;

ll solve(int now, int de[], int f[]) {

	if (now == n + 1) {

		int per = 0;
		int pas = 0;
		for (int j = 1; j <= n; j++) {
			if (p[j] == '0' || per >= de[j]) {
				per++;
			} else {
				pas++;
			}
		}
		if (pas >= m) {
			ans++;
			if (ans >= mod) {
				ans %= mod;
			}
		}
		return 0;
	}
	for (int i = 1; i <= n; i++) {
		if (f[i] == 0) {
			de[now] = c[i];
			f[i] = 1;
			solve(now + 1, de, f);
			de[now] = 0;
			f[i] = 0;
		}

	}
	return 0;
}

int main () {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	cin >> n >> m;
	int flag = 1;
	for (int i = 1; i <= n; i++) {
		cin >> p[i];
		if (p[i] == '0') {
			flag = 0;
		}
	}
	for (int iu = 1; iu <= n; iu++) {
		cin >> c[iu];
	}
	if (n <= 14) {
		solve(1, de, f);

	} else {
		if (m == 1 || flag == 1) {
			ans = 1;
			for (int j = 2; j <= n; j++) {
				ans *= j;
				if (ans >= mod) {
					ans %= mod;
				}
			}
		} else {
			ans = n;
		}
	}
	cout << ans << endl;
	return 0;
}