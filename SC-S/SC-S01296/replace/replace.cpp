#include <bits/stdc++.h>
using namespace std;
#define int long long
#define rep(i, x, y) for (int i = (x); i <= (y); i++)
#define per(i, x, y) for (int i = (x); i >= (y); i--)
//int read() {
//	int s = 0, f = 1; char c = getchar();
//	while (!isdigit(c)) { if (c == '-') f = -1; c = getchar(); }
//	while (isdigit(c)) s = s * 10 + (c ^ 48), c = getchar();
//	return s * f;
//}
mt19937 rng(random_device{}());
constexpr int N = 2e5 + 5, NN = 1e7 + 5, mod1 = 1011451423, mod2 = 1e9 + 9;
int n, q, hsh1[N], hsh2[N], hh1[N], hh2[N], pw1[NN], pw2[NN], nw1[NN / 2], nw2[NN / 2], ow1[NN / 2], ow2[NN / 2], npw1[NN / 2], npw2[NN / 2];
//string s1[N], s2[N];
map<array<int, 2>, vector<array<int, 2>>> mp;
set<array<int, 4>> ss;
unordered_map<int, int> buc;
int qpow(int x, const int mod, int y) {
	int res = 1;
	while (y) {
		if (y & 1) (res *= x) %= mod;
		(x *= x) %= mod, y >>= 1;
	}
	return res;
}
signed main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	cin >> n >> q;
	int base1 = rng(), base2 = rng();
	base1 = (base1 + 10000 * mod1) % mod1, base2 = (base2 + 10000 * mod2) % mod2;
	int nb1 = qpow(base1, mod1, mod1 - 2), nb2 = qpow(base2, mod2, mod2 - 2);
	rep (i, pw1[0] = pw2[0] = npw2[0] = npw1[0] = 1, NN - 1) {
		pw1[i] = pw1[i - 1] * base1 % mod1;
		pw2[i] = pw2[i - 1] * base2 % mod2;
		
	}
	rep (i, npw2[0] = npw1[0] = 1, NN / 2 - 1) {
		npw1[i] = npw1[i - 1] * nb1 % mod1;
		npw2[i] = npw2[i - 1] * nb2 % mod2;
	}
//	cerr << pw1[33] * npw1[33] % mod1 << ' ' << pw2[33] * npw2[33] % mod2 << '\n';
	rep (i, 1, n) {
		string s1, s2;
		cin >> s1 >> s2;
		s1 = '*' + s1, s2 = '*' + s2;
		int len = s1.size() - 1, l = 1e9, r = 0;
		rep (j, 1, len) if (s1[j] != s2[j]) l = min(l, j), r = max(r, j);
		if (l > r) continue;
		rep (j, l, r) {
			hh1[i] = (hh1[i] + pw1[j - l] * s1[j]) % mod1;
			hh2[i] = (hh2[i] + pw2[j - l] * s1[j]) % mod2;
			hh1[i] = (hh1[i] + pw1[j - l + (r - l + 1)] * s2[j]) % mod1;
			hh2[i] = (hh2[i] + pw2[j - l + (r - l + 1)] * s2[j]) % mod2;
		}
		rep (j, 1, len) {
			hsh1[i] = (hsh1[i] + pw1[j - 1] * s1[j]) % mod1;
			hsh2[i] = (hsh2[i] + pw2[j - 1] * s1[j]) % mod2;
			hsh1[i] = (hsh1[i] + pw1[j + len - 1] * s2[j]) % mod1;
			hsh2[i] = (hsh2[i] + pw2[j + len - 1] * s2[j]) % mod2;
		}
//		cerr << hh1[i] << ' '<< hh2[i]<<' '<<l - 1<<' '<< len - r<<'\n';
		if (!ss.count({hh1[i], hh2[i], l - 1, len - r})) {
			mp[{hh1[i], hh2[i]}].push_back({l - 1, len - r});
			ss.insert({hh1[i], hh2[i], l - 1, len - r});
		}
		buc[(hsh1[i] << 31) ^ hsh2[i]]++;
	}
	rep (i, 1, q) {
		string t1, t2;
		cin >> t1 >> t2;
		t1 = '*' + t1, t2 = '*' + t2;
		if (t1.size() != t2.size()) { cout << "0\n"; continue; }
		int len = t1.size() - 1, l = 1e9, r = 0;
		rep (j, 1, len) if (t1[j] != t2[j]) l = min(l, j), r = max(r, j);
		int hs1 = 0, hs2 = 0;
		rep (j, l, r) {
			hs1 = (hs1 + pw1[j - l] * t1[j]) % mod1;
			hs2 = (hs2 + pw2[j - l] * t1[j]) % mod2;
			hs1 = (hs1 + pw1[j - l + (r - l + 1)] * t2[j]) % mod1;
			hs2 = (hs2 + pw2[j - l + (r - l + 1)] * t2[j]) % mod2;
		}
		rep (j, 1, len) {
			nw1[j] = (nw1[j - 1] + pw1[j - 1] * t1[j]) % mod1;
			nw2[j] = (nw2[j - 1] + pw2[j - 1] * t1[j]) % mod2;
			ow1[j] = (ow1[j - 1] + pw1[j - 1] * t2[j]) % mod1;
			ow2[j] = (ow2[j - 1] + pw2[j - 1] * t2[j]) % mod2;
		}
		auto &x = mp[{hs1, hs2}];
//		cerr << hs1 << ' ' << hs2 << '\n';
		int L = l - 1, R = len - r, ans = 0;
		for (auto to : x) if (L >= to[0] && R >= to[1]) {
//			cerr << L << ' ' << R << ' ' << to[0] << ' ' << to[1] << endl;
			int ql = l - to[0], qr = r + to[1];
			int h11 = (nw1[qr] - nw1[ql - 1] + mod1) * npw1[ql - 1] % mod1;
			int h12 = (nw2[qr] - nw2[ql - 1] + mod2) * npw2[ql - 1] % mod2;
			int h21 = (ow1[qr] - ow1[ql - 1] + mod1) * npw1[ql - 1] % mod1;
			int h22 = (ow2[qr] - ow2[ql - 1] + mod2) * npw2[ql - 1] % mod2;
			h11 = (h21 * pw1[qr - ql + 1] + h11) % mod1;
			h22 = (h22 * pw2[qr - ql + 1] + h12) % mod2;
			ans += buc[(h11 << 31) ^ h22];
		}
		cout << ans << '\n';
	}
	return 0;
}
/*
4 2
xabcx xadex
ab cd
bc de
aa bb
xabcx xadex
aaaa bbbb
*/