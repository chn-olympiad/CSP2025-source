#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 200010, L = 5000010, SIG = 30;
const ll mod[2] = {2025110249, 2025110251};
mt19937 rng (114514);
uniform_int_distribution <ll> dist (1919810, mod[0] - 1919810);
int n, m, q, w = 27, hsh[N][2], rc, cnt;
ll bas[L];
char s[L], t[L];
map <ll, int> mp;
vector <int> a[N];
namespace kmp {
	int fail[L];
	int main (int p) {
		int n = a[p].size (), m = a[0].size (), ret = 0;
		if (::n <= 100) {
			for (int i = 1; i <= m - n + 1; i++) {
				bool flag = true;
				for (int j = 1; j <= n; j++) {
					if (a[p][j - 1] != a[0][i + j - 2]) {
						flag = false;
						break;
					}
				}
				if (flag) {
					ret++;
				}
			}
		} else {
			for (int i = 2, j = 0; i <= n; i++) {
				j++;
				while (j != 0 && a[p][j - 1] != a[p][i - 1]) {
					j = fail[j];
				}
				fail[i] = j;
			}
			for (int i = 1, j = 0; i <= m; i++) {
				j++;
				while (j != 0 && a[p][j - 1] != a[0][i - 1]) {
					j = fail[j];
				}
				if (j == n) {
					ret++;
					j = fail[j];
				}
			}
		}
		return ret;
	}
}
int main () {
	freopen ("replace.in", "r", stdin);
	freopen ("replace.out", "w", stdout);
	scanf ("%d%d", &n, &q);
	for (int i = 1; i <= n; i++) {
		scanf ("%s%s", s + 1, t + 1);
		m = strlen (s + 1);
		int l = -1, r = -1;
		for (int j = 1; j <= m; j++) {
			if (s[j] != t[j]) {
				if (l == -1) {
					l = j;
				}
				r = j;
			}
		}
		if (l != -1) {
			for (int j = l; j <= r; j++) {
				if (bas[j - l + 1] == 0) {
					bas[j - l + 1] = dist (rng);
				}
				ll u = (s[j] - 96) * 26 + t[j] - 96;
				(hsh[i][0] += u * bas[j - l + 1]) %= mod[0];
				(hsh[i][1] += u * bas[j - l + 1]) %= mod[1];
			}
		}
		a[i].resize (m);
		for (int j = 1; j <= m; j++) {
			a[i][j - 1] = s[j] - 96;
		}
	}
	for (int i = 1; i <= q; i++) {
		scanf ("%s%s", s + 1, t + 1);
		m = strlen (s + 1);
		int l = -1, r = -1;
		for (int j = 1; j <= m; j++) {
			if (s[j] != t[j]) {
				if (l == -1) {
					l = j;
				}
				r = j;
			}
		}
		hsh[0][0] = 0, hsh[0][1] = 0;
		if (l != -1) {
			for (int j = l; j <= r; j++) {
				if (bas[j - l + 1] == 0) {
					bas[j - l + 1] = dist (rng);
				}
				ll u = (s[j] - 96) * 26 + t[j] - 96;
				(hsh[0][0] += u * bas[j - l + 1]) %= mod[0];
				(hsh[0][1] += u * bas[j - l + 1]) %= mod[1];
			}
		}
		a[0].resize (m);
		for (int j = 1; j <= m; j++) {
			a[0][j - 1] = s[j] - 96;
		}
		int ans = 0;
		for (int j = 1; j <= n; j++) {
			if (hsh[0][0] == hsh[j][0] && hsh[0][1] == hsh[j][1]) {
				ans += kmp::main (j);
			}
		}
		printf ("%d\n", ans);
	}
	return 0;
}