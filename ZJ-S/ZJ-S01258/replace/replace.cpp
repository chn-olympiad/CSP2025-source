#include <bits/stdc++.h>
#define i32 int
#define i64 long long
#define u64 unsigned long long
#define For(i, l, r) for (i32 i = (l); i <= (r); i++)
using namespace std;

const i32 N = 2e5 + 5;
const i32 M = 5e6 + 5;
const u64 P = 231;
string s[2][N];
string t[2][N];
i32 n, q;
i32 L1, L2;
u64 f[M];
u64 p1[M], p2[M];
namespace SpecialA {
	inline bool check() {
		// cerr << L1 << ' ' << L2 << ' ' << q << '\n';
		// return 1ll * (L1 + L2) * q <= 1e7;
		return 1;
	}
	inline void solve() {
		f[0] = 1; For (i, 1, M - 1) f[i] = f[i - 1] * P;
		For (i, 1, q) {
			i32 ans = 0;
			if (t[0][i].size() != t[1][i].size()) {
				cout << "0\n";
				continue;
			}
			i32 S = t[0][i].size();
			i32 L = 1e9, R = 0;
			For (j, 0, S - 1) {
				p1[j] = t[0][i][j], p2[j] = t[1][i][j];
				if (j) p1[j] += p1[j - 1] * P, p2[j] += p2[j - 1] * P;
				if (t[0][i][j] != t[1][i][j]) {
					L = min(L, j);
					R = j;
				}
			}
			// cerr << t[0][i] << ' ' << t[1][i] << endl;
			// cerr << L << ' ' << R << endl;
			For (j, 1, n) {
				u64 h1 = 0, h2 = 0;
				i32 m = s[0][j].size();
				if (m > S) continue;
				For (k, 0, m - 1) {
					h1 = h1 * P + s[0][j][k];
					h2 = h2 * P + s[1][j][k];
				}
				i32 l = L, r = l + m - 1;
				if (r >= S) l -= r - S + 1, r = S - 1;
				// cerr << j << ' ' << l << ' ' << r << endl;
				while (r >= R && l >= 0) {
					if (h1 == p1[r] - (l ? p1[l - 1] * f[r - l + 1] : 0) && h2 == p2[r] - (l ? p2[l - 1] * f[r - l + 1] : 0)) {
						// cerr << j << endl;
						ans++; break;
					}
					l--, r--;
				}
			}
			cout << ans << '\n';
		}
	}
}

namespace SpecialB {
	inline bool check(string a) {
		i32 cnt = 0;
		for (auto i : a) {
			if (i == 'b') cnt++;
			else if (i == 'a') ;
			else return 0;
		}
		return cnt == 1;
	}
	inline bool check() {
		For (i, 1, n) {
			if (!check(s[0][i]) || !check(s[1][i])) return 0;
		}
		For (i, 1, q) {
			if (!check(t[0][i]) || !check(t[1][i])) return 0;
		}
		return 1;
	}
	struct QUE {
		i32 L, R, id;
	};
	vector < QUE > ppp[2][N];
	#define lowbit(x) (x & -x)
	i32 tree[N], cnt, ans[N];
	inline void add(i32 x, i32 y) { for (; x <= n; x += lowbit(x)) tree[x] += y; }
	inline i32 sum(i32 x) { i32 res = 0; for (; x; x -= lowbit(x)) res += tree[x]; return res; }
	inline void solve() {
		For (i, 1, n) {
			i32 m = s[0][i].size();
			i32 id1, id2;
			For (j, 0, m - 1) {
				if (s[0][i][j] == 'b') id1 = j;
				if (s[1][i][j] == 'b') id2 = j;
			}
			if (id1 < id2) ppp[0][id2 - id1].push_back({ min(id1, id2), m - max(id1, id2), -1 });
			else ppp[1][id1 - id2].push_back({ min(id1, id2), m - max(id1, id2), -1 });
			// cerr << id1 << ' ' << id2 << '\n';
			// cerr << id1 - id2 << '\n';
			// cerr << id1 - id2 << " \n"[i == n];
		}
		For (i, 1, q) {
			i32 m = t[0][i].size();
			if (t[1][i].size() != m) { cout << "0\n"; continue; }
			i32 id1, id2;
			For (j, 0, m - 1) {
				if (t[0][i][j] == 'b') id1 = j;
				if (t[1][i][j] == 'b') id2 = j;
			}
			// if (i <= 15)
			// cerr << id1 - id2 << ' ' << m << '\n';
			// if (id1 < id2) cout << cnt[0][id2 - id1] << '\n';
			// else cout << cnt[1][id1 - id2] << '\n';
			if (id1 < id2) ppp[0][id2 - id1].push_back({ min(id1, id2), m - max(id1, id2), i });
			else ppp[1][id1 - id2].push_back({ min(id1, id2), m - max(id1, id2), i });
		}
		For (i, 0, 1) {
			For (j, 0, n) {
				sort(ppp[i][j].begin(), ppp[i][j].end(), [&](QUE a, QUE b) { return a.L < b.L || a.L == b.L && a.R < b.R || a.L == b.L && a.R == b.R && a.id < b.id; });
				cnt = 0;
				for (auto v : ppp[i][j]) {
					if (v.id == -1) {
						if (!v.R) cnt++;
						else add(v.R, 1);
					} else {
						ans[v.id] = sum(v.R) + cnt;
					}
				}
				for (auto v : ppp[i][j]) if (v.id == -1 && v.R) add(v.R, -1);
			}
		}
		For (i, 1, q) cout << ans[i] << '\n';
	}
}

inline void ___() {
	cin >> n >> q;
	For (i, 1, n) cin >> s[0][i] >> s[1][i], L1 += s[0][i].size() + s[1][i].size();
	For (i, 1, q) cin >> t[0][i] >> t[1][i], L2 += t[0][i].size() + t[1][i].size();
	if (SpecialB::check()) return SpecialB::solve();
	if (SpecialA::check()) return SpecialA::solve();
}



signed main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	double be = clock();
	ios::sync_with_stdio(false), cin.tie(), cout.tie();
	i32 T = 1; //cin >> T;
	while (T--) ___();
	// cerr << "times: " << (clock() - be) * 1.0 / CLOCKS_PER_SEC << endl;
}

/*
aaaaaaaaaaaaba
aaaaaaaaaabaaa
*/