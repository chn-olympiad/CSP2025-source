#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define GL return
#define HF 0

const int N = 510, N2 = 20, M = (1 << 18) + 10;
const ll p = 998244353;

int n, m, c[N], a[N];
char s[N];
ll ans = 0ll, res = 0ll, f[N2][M][N2];

inline ll calc (const int &x, const int &t, const int &m) {
	if (m < 0 || m > x) {
		return 0ll;
	}
	if (x == 1) {
		if (s[x] == '0') {
			if (m <= 0) {
				return 1ll;
			} else {
				return 0ll;
			}
		} else {
			if (s[x] == '1') {
				if (m <= 1) {
					return 1ll;
				} else {
					return 0ll;
				}
			}
		}
	}
	if (f[x][t][m] != -1) {
		return f[x][t][m];
	}
	ll res = 0ll;
	if (s[x] == '0') {
		for (int j = 1; j <= n; j++) {
			if (t >> (j - 1) & 1) {
				if (x - 1 - m < c[j]) {
					res += calc(x - 1, t - (1 << (j - 1)), m);
					res %= p;				
				}
			}
		}
	} else {
		for (int j = 1; j <= n; j++) {
			if (t >> (j - 1) & 1) {
				res += calc(x - 1, t - (1 << (j - 1)), max(m - 1, x - c[x] - 2));
				res %= p;
			}
		}
	}
	return f[x][t][m] = res;
}

void solve () {
	scanf("%d%d%s", &n, &m, s + 1);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &c[i]);
	}
	bool ok = true;
	for (int i = 2; i <= n; i++) {
		if (s[i] != s[i - 1]) {
			ok = false;
			break;
		}
	}
	if (ok) {
		if (s[1] == '1') {
			puts("0");
		} else {
			ll res = 1ll;
			for (int i = 1; i <= n; i++) {
				res *= i;
				res %= p;
			}
			printf("%lld\n", res);
		}
		GL;
	}
	if (n <= 10) {
		for (int i = 1; i <= n; i++) {
			a[i] = i;
		}
		while (true) {
			int cnt = 0, cnt2 = 0;
			for (int i = 1; i <= n; i++) {
				if (s[i] == '1' && cnt2 < c[a[i]]) {
					cnt++;
				} else {
					cnt2++;
				}
			}
			if (cnt >= m) {
				ans++;
				ans %= p;
			}
			if (!next_permutation(a + 1, a + n + 1)) {
				break;
			}
		}
		printf("%lld\n", ans);
		GL;
	}
	for (int i = 0; i <= n; i++) {
		for (int j = 0; j < 1 << n; j++) {
			for (int k = 0; k <= n; k++) {
				f[i][j][k] = -1;
			}
		}
	}
	printf("%lld\n", calc(n, (1 << n) - 1, m));
	GL;
}

int main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	solve();
	GL HF;
}
