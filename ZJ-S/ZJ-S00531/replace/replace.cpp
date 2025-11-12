#include <bits/stdc++.h>
using namespace std;
constexpr int N = 5e6 + 5, M = 2e5 + 5, mod = 1e9 + 7, MOD = 998244353, P = 131;
typedef unsigned long long ull;
int n, T, le[M], h1[N], h2[N], h3[N], h4[N], p1[N], p2[N], dab[M], hd[M], tl[M];
char a[N], b[N], s[N], t[N];
ull hl[M], hr[M];
inline ull get_hash(int *h1, int *h2, int l, int r) {
	if (l > r)
		return 0ull;
	ull x = (h1[r] - 1ll * h1[l - 1] * p1[r - l + 1] % mod + mod) % mod;
	ull y = (h2[r] - 1ll * h2[l - 1] * p2[r - l + 1] % MOD + MOD) % MOD;
	return x << 32 | y; 
}
inline void solve() {
	int m = strlen(s + 1), ans = 0;
	for (int i = 1; i <= m; i++) {
		h1[i] = (1ll * h1[i - 1] * P + s[i]) % mod;
		h2[i] = (1ll * h2[i - 1] * P + s[i]) % MOD;
		h3[i] = (1ll * h3[i - 1] * P + t[i]) % mod;
		h4[i] = (1ll * h4[i - 1] * P + t[i]) % MOD;
	}
	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= n; j++) {
			if (i - le[j] >= 0 && get_hash(h1, h2, i - le[j] + 1, i) == hl[j] && get_hash(h3, h4, i - le[j] + 1, i) == hr[j]) {
				if (get_hash(h1, h2, 1, i - le[j]) == get_hash(h3, h4, 1, i - le[j]) && get_hash(h1, h2, i + 1, m) == get_hash(h3, h4, i + 1, m))
					ans++;
			}
		}
	}
	cout << ans << '\n';
}
inline void Solve() {
	int m = strlen(s + 1), ans = 0;
	int posl = 0, posr = 0, taskB = true;
	for (int i = 1; i <= m; i++) {
		if (s[i] == 'b')
			posl = i;
		if (t[i] == 'b')
			posr = i;
		taskB &= (s[i] == 'a' || s[i] == 'b');
		taskB &= (t[i] == 'a' || t[i] == 'b');
	}
	if (!taskB) {
		solve();
		return;
	}
	for (int i = 1; i <= n; i++) {
		if (m >= le[i] && hd[i] <= posl && le[i] - hd[i] <= m - posl) {
			int d = hd[i] - tl[i];
			if (posl - posr == d)
				ans++;
		}
	}
	cout << ans << '\n';
}
signed main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	p1[0] = p2[0] = 1;
	for (int i = 1; i < N; i++) {
		p1[i] = 1ll * p1[i - 1] * P % mod;
		p2[i] = 1ll * p2[i - 1] * P % MOD;
	}
	cin >> n >> T;
	int sm = 0;
	bool taskB = true;
	for (int i = 1; i <= n; i++) {
		cin >> (a + 1) >> (b + 1);
		int m = (le[i] = strlen(a + 1)), ctb = 0; 
		sm += m;
		ull H1 = 0, H2 = 0;
		for (int j = 1; j <= m; j++) {
			H1 = (1ll * H1 * P + a[j]) % mod;
			H2 = (1ll * H2 * P + a[j]) % MOD;
			taskB &= (a[j] == 'a' || a[j] == 'b');
			if (a[j] == 'b')
				hd[i] = j, ctb++;
		}
		if (ctb != 1) 
			taskB = false;
		hl[i] = H1 << 32 | H2, H1 = 0, H2 = 0;
		for (int j = 1; j <= m; j++) {
			H1 = (1ll * H1 * P + b[j]) % mod;
			H2 = (1ll * H2 * P + b[j]) % MOD;
			taskB &= (b[j] == 'a' || b[j] == 'b');
			if (b[j] == 'b')
				tl[i] = j;
		}
		hr[i] = H1 << 32 | H2;
	}
	while (T--) {
		cin >> (s + 1) >> (t + 1);
		if (!taskB)
			solve();
		else {
			Solve();
		}
	}
	return 0;
}