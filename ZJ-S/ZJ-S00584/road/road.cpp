#include <bits/stdc++.h>
#define REP(i, l, r) for (int i = (l); i <= (r); i ++)
#define DEP(i, r, l) for (int i = (r); i >= (l); i --)
#define CUP(i, l, r) for (int i = (l); i < (r); i ++)
#define fi first
#define se second
#define mems(a, v) memset((a), (v), sizeof(a))
#define memc(a, b) memset((a), (b), sizeof(b))
#define pb push_back
#define SZ(x) (int)((x).size())
#define ALL(x) (x).begin(), (x).end()
#define ppc __builtin_popcount
using namespace std;
namespace Milkcat {
	typedef long long LL;
	typedef pair<LL, LL> pii;
	typedef array<int, 3> edge;
	const int N = 1e4 + 25, K = 15;
	int n, m, k, x, y, z, fa[N], c[N]; LL rs;
	vector<edge> A, B, E[K], H[1024]; edge s[N * K];
	int fnd(int x) { return (fa[x] == x ? x : fa[x] = fnd(fa[x])); }
	bool cmp(edge& x, edge& y) { return x[2] < y[2]; }
	void mrg(auto &A, auto &B) {
		int p = 0, q = 0, t = 0;
		while (p < SZ(A) || q < SZ(B)) {
			if (p == SZ(A)) s[t ++] = B[q ++];
			else if (q == SZ(B)) s[t ++] = A[p ++];
			else if (cmp(A[p], B[q])) s[t ++] = A[p ++];
			else s[t ++] = B[q ++];
		}
		A.resize(t);
		CUP(i, 0, t) A[i] = s[i];
	}
	int main() {
		cin >> n >> m >> k, rs = 1e18;
		REP(i, 1, m) cin >> x >> y >> z, A.pb({x, y, z});
		sort(ALL(A), cmp);
		REP(i, 1, n) fa[i] = i;
		for (auto [x, y, z] : A) {
			int p = fnd(x), q = fnd(y);
			if (p != q) B.pb({x, y, z}), fa[p] = q;
		}
		REP(i, 1, k) {
			cin >> c[i];
			REP(j, 1, n) cin >> x, E[i].pb({n + i, j, x});
			sort(ALL(E[i]), cmp);
		}
		CUP(S, 0, 1 << k) {
			LL w = 0, t = 1; 
			if (!S) H[S] = B;
			else {
				int x = __lg(S & -S);
				H[S] = H[S ^ 1 << x], mrg(H[S], E[x + 1]);
			}
			REP(i, 1, k)
				if (S >> (i - 1) & 1) w += c[i];
			REP(i, 1, n + k) fa[i] = i;
			for (auto [x, y, z] : H[S]) {
				int p = fnd(x), q = fnd(y);
				if (p != q) fa[p] = q, w += z;
			}
			rs = min(rs, w);
		}
		cout << rs << '\n';
		return 0;
	}
}
int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	cin.tie(0)->sync_with_stdio(0);
	int T = 1;
	while (T --) Milkcat::main();
	return 0;
}