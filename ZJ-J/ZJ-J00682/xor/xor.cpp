#include <bits/stdc++.h>
using namespace std;
const int maxn = 5e5 + 5;
string s, k;
int e[maxn][25], cnt[maxn], su[maxn][25], g[25];
struct N {
	int st, en;
	bool operator < (const N tmp) {
		return en < tmp.en;
	}
} minl[maxn];
int main () {
	freopen ("xor.in", "r", stdin);
	freopen ("xor.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n >> k;
	int ll = k.size(), rr = 0, maxl = 0;
	while (rr < ll) {
		e[0][++cnt[0]] = (k[ll - 1] - '0') % 2;
		int lazy = 0;
		for (int j = rr; j < ll; j++) {
			k[j] = (lazy * 10 + k[j] - '0') / 2 + '0';
			lazy = (k[j] - '0') % 2;
		}
		while (k[rr] == '0' && rr < ll) {
			rr++;
		}
	}
	for (int i = 1; i <= n; i++) {
		minl[i].st = -1e9;
		minl[i].en = 1e9;
		cin >> s;
		int l = s.size(), r = 0;
		while (r < l) {
			e[i][++cnt[i]] = (s[l - 1] - '0') % 2;
			int lazy = 0;
			for (int j = r; j < l; j++) {
				s[j] = (lazy * 10 + s[j] - '0') / 2 + '0';
				lazy = (s[j] - '0') % 2;
			}
			while (s[r] == '0' && r < l) {
				r++;
			}
		}
		maxl = max(maxl, cnt[i]);
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= maxl; j++) {
			su[i][j] = !(su[i - 1][j] == e[i][j]);
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int m = i; m <= n; m++) {
			memset(g, 0, sizeof(g));
			for (int j = 1; j <= maxl; j++) {
				g[j] = !(su[m][j] == su[i - 1][j]);
			}
			bool f = 1;
			for (int j = 1; j <= maxl; j++) {
				if (g[j] != e[0][j]) {
					f = 0;
					break;
				}
			}
			if (f) {
				minl[i] = {i, m};
				break;
			}
		}
	}
	sort(minl + 1, minl + n + 1);
	int j = 1, ans = 1;
	for (int i = 2; i <= n; i++) {
		if (minl[i].st > minl[j].en) {
			ans++;
			j = i;
		}
	}
	cout << ans;
	return 0;
}