#include <bits/stdc++.h>

#define endl '\n'
#define ll long long
#define pii pair<int,int>
#define fi first
#define se second
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define pq priority_queue
#define In(x) freopen(x".in","r",stdin)
#define Out(x) freopen(x".out","w",stdout)
#define File(x) (In(x),Out(x))
using namespace std;

const int N = 2e5+5, L = 5e6+5, mod[2] = {998244853, 998244353}, bas[2] = {29, 31};
int n, q, h[N][3][2], tot, hsh[L][3][2], pw[L][2];
string s[N][3], t[3];
map <pair<pii, pii>, int> mp;
vector <pair<int, pii> > lef[N], rig[N];
int get(int l, int r, int tp, int k) {
	int x = (hsh[r + 1][tp][k] - 1ll * hsh[l][tp][k] * pw[r - l + 1][k] % mod[k] + mod[k]) % mod[k];
	return x;
}
signed main() {
	File("replace");
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> n >> q;
	for (int i = 1; i <= n; i++)
		cin >> s[i][1] >> s[i][2];
	pw[0][0] = pw[0][1] = 1;
	for (int k = 0; k < 2; k++)
		for (int i = 1; i < L; i++)
			pw[i][k] = 1ll * pw[i - 1][k] * bas[k] % mod[k];
	for (int i = 1; i <= n; i++) {
		int len = s[i][1].size();
		int l = 0, r = len - 1;
		while (l < len && s[i][1][l] == s[i][2][l])
			l++;
		if (l == len)
			continue;
		while (s[i][1][r] == s[i][2][r])
			r--;
		for (int tp = 1; tp <= 2; tp++) {
			for (int k = 0; k < 2; k++) {
				for (int j = l; j <= r; j++) {
					h[i][tp][k] = (1ll * h[i][tp][k] * bas[k] + s[i][tp][j] - 'a') % mod[k];
				}
			}
		}
		int x = mp[ {{h[i][1][0], h[i][1][1]}, {h[i][2][0], h[i][2][1]}}];
		if (!x)
			x = mp[ {{h[i][1][0], h[i][1][1]}, {h[i][2][0], h[i][2][1]}}] = ++tot;
		int g[2];
		g[0] = g[1] = 0;
		for (int k = 0; k < 2; k++)
			for (int j = 0; j < l; j++)
				g[k] = (1ll * g[k] * bas[k] + s[i][1][j] - 'a') % mod[k];
		lef[x].pb({l, {g[0], g[1]}});
		g[0] = g[1] = 0;
		for (int k = 0; k < 2; k++)
			for (int j = r + 1; j < len; j++)
				g[k] = (1ll * g[k] * bas[k] + s[i][1][j] - 'a') % mod[k];
		rig[x].pb({len - r - 1, {g[0], g[1]}});
	}
	for (int tmp = 1; tmp <= q; tmp++) {
		cin >> t[1] >> t[2];
		int len = t[1].size(), l = 0, r = len - 1;
		while (l < len && t[1][l] == t[2][l])
			l++;
		while (t[1][r] == t[2][r])
			r--;
		for (int tp = 1; tp <= 2; tp++) {
			for (int k = 0; k < 2; k++) {
				for (int j = 1; j <= len; j++) {
					hsh[j][tp][k] = (1ll * hsh[j - 1][tp][k] * bas[k] + t[tp][j - 1] - 'a') % mod[k];
				}
			}
		}
		int x = mp[ {{get(l, r, 1, 0), get(l, r, 1, 1)}, {get(l, r, 2, 0), get(l, r, 2, 1)}}];
		if (x == 0) {
			cout << 0 << endl;
			continue;
		}
		ll ans = 0;
		for (int i = 0; i < int(lef[x].size()); i++) {
			int le = lef[x][i].fi, u = lef[x][i].se.fi, v = lef[x][i].se.se;
			if (l < le)
				continue;
			if (get(l - le, l - 1, 1, 0) != u || get(l - le, l - 1, 1, 1) != v)
				continue;
			le = rig[x][i].fi, u = rig[x][i].se.fi, v = rig[x][i].se.se;
			if (r + le >= len)
				continue;
			if (get(r + 1, r + le, 1, 0) != u || get(r + 1, r + le, 1, 1) != v)
				continue;
			ans++;
		}
		cout << ans << endl;
	}
	return 0;
}
/*
fc /W test.out test.ans
*/
