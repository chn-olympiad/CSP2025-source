#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = (a); i <= (b); i++)
#define lop(i, a, b) for (int i = (a); i < (b); i++)
#define dwn(i, a, b) for (int i = (a); i >= (b); i--)
#define pr pair<int, int>
#define mp(a, b) make_pair(a, b)
#define fir first
#define sec second
#define iosfst ios :: sync_with_stdio(false); cin.tie(0), cout.tie(0)
#define File(x) freopen(x".in", "r", stdin), freopen(x".out", "w", stdout)
using namespace std;
const int N = 5e2 + 10, mod = 998244353;
int n, m, sub = 1, sub2 = 1, f[N], c[N], ans;
bool vis[N];
string s;
bool check() {
	int cnt = 0, res = 0;
	rep (i, 1, n) {
		if (s[i - 1] == '0' || cnt >= c[f[i]]) cnt++;
		else res++;
	}
	return res >= m;
}
void dfs(int p) {
	if (p == n + 1) {
		if (check()) ans++;
		return;
	}
	rep (i, 1, n) if (!vis[i]) vis[i] = 1, f[p] = i, dfs(p + 1), vis[i] = 0;
	return;
}
signed main() {
	iosfst;
	File("employ");
	cin >> n >> m >> s;
	lop (i, 0, s.size()) sub &= (s[i] == '1'), sub2 &= (s[i] == '0');
	rep (i, 1, n) cin >> c[i];
	if (sub) {
		int ans = 1;
		rep (i, 1, n) ans = 1ll * ans * i % mod;
		cout << ans;
		return 0;
	}
	if (sub2) {
		cout << 0;
		return 0;
	}
	if (m == n) {
		lop (i, 0, s.size())
			if (s[i] == '0') {
				cout << 0;
				return 0;
			}
		int ans = 1;
		rep (i, 1, n) ans = 1ll * ans * i % mod;
		cout << ans;
		return 0;
	}
	dfs(1);
	cout << ans;
	return 0;
}
