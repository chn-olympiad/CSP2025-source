#include <bits/stdc++.h>
#define REP(i, l, r) for (int i = (l); i <= (r); i ++)
#define DEP(i, r, l) for (int i = (r); i >= (l); i ++)
#define CUP(i, l, r) for (int i = (l); i < (r); i ++)
#define fi first
#define se second
#define mems(a, v) memset((a), (v), sizeof(a))
#define memc(a, b) memset((a), (b), sizeof(b))
#define pb emplace_back
#define SZ(x) (int)((x).size())
#define ALL(x) (x).begin(), (x).end()
#define ppc __builtin_popcount
using namespace std;
namespace Milkcat {
	typedef long long LL;
	typedef pair<LL, LL> pii;
	const int N = 2e5 + 5, K = 2e6 + 5, M = 1e7 + 5;
	const int M1 = 1e9 + 7, M2 = 998244353, B1 = 1 << 20, B2 = 1 << 20;
	int n, q, ct, bl, tt, rs[N], d1[N], d2[N], d3[N], d4[N], tr[M][26], in[M], ot[M], c[K]; 
	string a[N], b[N], A[N], B[N]; unordered_map<LL, int> id;
	vector<int> g[N], r[N]; vector<pii> C[K], D[K];
	LL cut(string &A, string &B) {
		int p = 0, q = SZ(A) - 1, x = 1, b1 = 0, b2 = 0;
		while (A[p] == B[p]) p ++;
		while (A[q] == B[q]) q --;
		REP(i, p, q) {
			int x = A[i], y = B[i];
			b1 = (1LL * b1 * B1 + (x << 8 | y)) % M1;
			b2 = (1LL * b2 * B2 + (x << 8 | y)) % M2;
		}
		A = A.substr(0, p), B = B.substr(q + 1);
		return (LL)b1 << 32 | b2;
	}
	void dfs(int x) {
		in[x] = ++ tt;
		REP(i, 0, 25)
			if (tr[x][i]) dfs(tr[x][i]);
		ot[x] = tt;
	}
	int main() {
		cin >> n >> q;
		REP(i, 1, n) {
			cin >> a[i] >> b[i];
			if (a[i] == b[i]) continue;
			LL x = cut(a[i], b[i]);
			if (!id.count(x)) id[x] = ++ bl;
			g[id[x]].pb(i), reverse(ALL(a[i]));
		}
		REP(i, 1, q) {
			cin >> A[i] >> B[i];
			if (SZ(A[i]) != SZ(B[i])) continue;
			LL x = cut(A[i], B[i]);
			if (id.count(x)) r[id[x]].pb(i);
			reverse(ALL(A[i]));
		}
		REP(i, 1, bl) {
			ct = 2, tt = 0;
			for (int x : r[i]) {
				int p = 1, q = 2;
				for (int c : A[x]) {
					int &t = tr[p][c - 'a'];
					t = (t ? t : ++ ct), p = t;
				}
				for (int c : B[x]) {
					int &t = tr[q][c - 'a'];
					t = (t ? t : ++ ct), q = t;
				}
				d1[x] = p, d2[x] = q;
			}
			for (int x : g[i]) {
				int p = 1, q = 2;
				for (int c : a[x]) {
					int &t = tr[p][c - 'a'];
					t = (t ? t : ++ ct), p = t;
				}
				for (int c : b[x]) {
					int &t = tr[q][c - 'a'];
					t = (t ? t : ++ ct), q = t;
				}
				d3[x] = p, d4[x] = q;
			}
			dfs(1), dfs(2);
			vector<int> t;
			for (int x : g[i]) {
				int p = d3[x], q = d4[x];
				t.pb(in[p]), t.pb(ot[p] + 1), t.pb(in[q]), t.pb(ot[q] + 1);
			}
			for (int x : r[i]) t.pb(in[d1[x]]), t.pb(in[d2[x]]);
			sort(ALL(t)), t.erase(unique(ALL(t)), t.end());
			for (int x : g[i]) {
				int p = d3[x], q = d4[x];
				int l = lower_bound(ALL(t), in[p]) - t.begin() + 1;
				int r = lower_bound(ALL(t), ot[p] + 1) - t.begin() + 1;
				int L = lower_bound(ALL(t), in[q]) - t.begin() + 1;
				int R = lower_bound(ALL(t), ot[q] + 1) - t.begin() + 1;
				C[l].pb(L, 1), C[l].pb(R, -1);
				C[r].pb(L, -1), C[r].pb(R, 1);
			}
			for (int x : r[i]) {
				int p = d1[x], q = d2[x];
				int l = lower_bound(ALL(t), in[p]) - t.begin() + 1;
				int L = lower_bound(ALL(t), in[q]) - t.begin() + 1;
				D[l].pb(L, x);
			}
			REP(i, 1, SZ(t)) {
				for (auto [x, v] : C[i])
					for (x ++; x <= SZ(t); x += x & -x) c[x] += v;
				for (auto [x, i] : D[i])
					for (x ++; x; x -= x & -x) rs[i] += c[x];
			}
			REP(i, 1, ct) mems(tr[i], 0);
			REP(i, 1, SZ(t)) c[i] = 0, C[i].clear(), D[i].clear();
		}
		REP(i, 1, q) cout << rs[i] << '\n';
		return 0;
	}
}
int main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	cin.tie(0)->sync_with_stdio(0);
	int T = 1;
	while (T --) Milkcat::main();
	return 0;
}