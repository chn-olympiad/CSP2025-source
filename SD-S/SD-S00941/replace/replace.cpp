/*
author: WilliamFranklin
AFOed on 2025/11/1

我常常追忆过去，忘了。 

我该在哪里停留？我问我自己。 
*/
#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second
#define mp(Tx, Ty) make_pair(Tx, Ty)
#define For(Ti, Ta, Tb) for(auto Ti = (Ta); Ti <= (Tb); Ti++)
#define Dec(Ti, Ta, Tb) for(auto Ti = (Ta); Ti >= (Tb); Ti--)
#define debug(...) fprintf(stderr, __VA_ARGS__)
#define range(Tx) begin(Tx),end(Tx)
const int N = 2e5 + 5, M = 5e6 + 5, mod = 1e9 + 7, p = 13331;
int n, q;
struct Str {
	string s, t;
	string A, B;
	int L, R;
	int len;
} a[N * 2];
struct node {
	long long hsh[2];
	int id;
	bool op;
} str[N * 2];
int L[N * 2], R[N * 2], W[N * 2];
long long fac[M], ifac[M];
int ans[N];
int tr[M * 2][26];
long long quickpow(long long a, long long b, long long mod) {
	long long res = 1;
	while (b) {
		if (b & 1) res = res * a % mod;
		a = a * a % mod;
		b >>= 1;
	}
	return res;
}
bool cmp(node a, node b) {
	if (a.hsh[0] == b.hsh[0]) {
		if (a.hsh[1] == b.hsh[1]) {
			if (a.op == b.op) return a.id < b.id;
			return a.op < b.op;
		}
		return a.hsh[1] < b.hsh[1];
	}
	return a.hsh[0] < b.hsh[0];
}
int rt[2] = {1, 2};
int idx = 2;
int dfn[2][M * 2];
int sz[2][M * 2];
int dfncnt[2];
void insert(string s, int op) {
//	cout << s << ' ' << op << '\n';
	int u = rt[op];
	int len = s.size();
	For(i, 0, len - 1) {
		int x = s[i] - 'a';
		if (!tr[u][x]) tr[u][x] = ++idx;
		u = tr[u][x];
	}
}
void dfs(int x, int op){
	if (!x) return;
	dfn[op][x] = ++dfncnt[op];
	sz[op][x] = 1;
	For(i, 0, 25) {
		int j = tr[x][i];
		if (!j) continue;
		dfs(j, op);
		sz[op][x] += sz[op][j];
	}
}
pair<int, int> query(string s, int op) {
	int u = rt[op];
	//if (s == "ax")
	//cout << s << ' ' << op << '\n';
	int len = s.size();
	For(i, 0, len - 1) {
		int x = s[i] - 'a';
		u = tr[u][x];
		//if (s == "ax") cout << u << '\n';
	}
	//if (s == "ax") cout << dfn[op][u] << '\n';
	return mp(dfn[op][u], dfn[op][u] + sz[op][u] - 1);
}
namespace Tree {
	int tr[M * 2];
	int lowbit(int x) {
		return x & -x;
	}
	void add(int x, int y) {
		assert(x > 0);
		for (int i = x; i <= dfncnt[1]; i += lowbit(i)) tr[i] += y;
	}
	int sum(int x) {
		if (x <= 0) return 0;
		int res = 0;
		for (int i = x; i; i -= lowbit(i)) res += tr[i];
		return res;
	}
}
bool cmp1(pair<int, pair<int, int> > a, pair<int, pair<int, int> > b) {
	if (a.x == b.x) return a.y.y < b.y.y;
	return a.x < b.x;
}
void work(int l, int r) {
	vector<pair<int, pair<int, int> > > G;
	For(i, l, r) {
		if (str[i].op == 0) G.push_back(mp(L[str[i].id], mp(str[i].id, 1))), G.push_back(mp(R[str[i].id] + 1, mp(str[i].id, -1)));
		else G.push_back(mp(W[str[i].id], mp(str[i].id, 2)));
	}
//	For(i, l, r) {
//		cout << str[i].op << ' ' << str[i].id << '\n';
//	}
//	cout << '\n';
	sort(range(G), cmp1);
	for (auto i : G) {
		if (i.y.y == 2) {
//			cout << i.y.x << ' ' << R[i.y.x + n] << ' ' << L[i.y.x + n] - 1 << '\n';
			ans[i.y.x] = Tree::sum(W[i.y.x + n]);
		} else {
//			cout << i.y.x << ' ' << i.y.y << '\n';
			Tree::add(L[i.y.x + n], i.y.y);
			Tree::add(R[i.y.x + n] + 1, -i.y.y);
		}
	}
}
int main() {
	assert(freopen("replace.in", "r", stdin));
	assert(freopen("replace.out", "w", stdout));
	cin.tie(nullptr)->sync_with_stdio(false);
	fac[0] = 1;
	For(i, 1, N - 1) fac[i] = fac[i - 1] * p % mod;
	ifac[N - 1] = quickpow(fac[N - 1], mod - 2, mod);
	Dec(i, N - 2, 0) ifac[i] = ifac[i + 1] * p % mod;
	assert(ifac[0] == 1);
	cin >> n >> q;
	For(i, 1, n) {
		cin >> a[i].s >> a[i].t;
		a[i].len = a[i].s.size();
		For(j, 0, a[i].len - 1) {
			if (a[i].s[j] != a[i].t[j]) {
				a[i].L = j;
				break;
			}
		}
		Dec(j, a[i].len - 1, 0) {
			if (a[i].s[j] != a[i].t[j]) {
				a[i].R = j;
				break;
			}
		}
		For(j, a[i].L, a[i].R) str[i].hsh[0] = (str[i].hsh[0] + fac[j - a[i].L] * (a[i].s[j] - 'a' + 1) % mod) % mod;
		For(j, a[i].L, a[i].R) str[i].hsh[1] = (str[i].hsh[1] + fac[j - a[i].L] * (a[i].t[j] - 'a' + 1) % mod) % mod;
		str[i].op = 0;
		str[i].id = i;
		a[i].A = a[i].B = "";
		Dec(j, a[i].L - 1, 0) a[i].A += a[i].s[j];
		For(j, a[i].R + 1, a[i].len - 1) a[i].B += a[i].s[j]; 
//		cout << a[i].A << ' ' << a[i].B << '\n';
		insert(a[i].A, 0);
		insert(a[i].B, 1);
	}
//	exit(0);
	For(i, 1, q) {
		cin >> a[i + n].s >> a[i + n].t;
		if (a[i + n].s.size() != a[i + n].t.size()) {
			ans[i] = 0;
			str[i + n].hsh[0] = str[i + n].hsh[1] = -1;
			continue;
		}
		a[i + n].len = a[i + n].s.size();
		For(j, 0, a[i + n].len - 1) {
			if (a[i + n].s[j] != a[i + n].t[j]) {
				a[i + n].L = j;
				break;
			}
		}
		Dec(j, a[i + n].len - 1, 0) {
			if (a[i + n].s[j] != a[i + n].t[j]) {
				a[i + n].R = j;
				break;
			}
		}
		For(j, a[i + n].L, a[i + n].R) str[i + n].hsh[0] = (str[i + n].hsh[0] + fac[j - a[i + n].L] * (a[i + n].s[j] - 'a' + 1) % mod) % mod;
		For(j, a[i + n].L, a[i + n].R) str[i + n].hsh[1] = (str[i + n].hsh[1] + fac[j - a[i + n].L] * (a[i + n].t[j] - 'a' + 1) % mod) % mod;
		str[i + n].op = 1;
		str[i + n].id = i;
		a[i + n].A = a[i + n].B = "";
		Dec(j, a[i + n].L - 1, 0) a[i + n].A += a[i + n].s[j];
		For(j, a[i + n].R + 1, a[i + n].len - 1) a[i + n].B += a[i + n].s[j]; 
		insert(a[i + n].A, 0);
		insert(a[i + n].B, 1);
	}
	dfs(rt[0], 0);
	dfs(rt[1], 1);
	assert(dfn[0][0] == 0 && sz[0][0] == 0);
	For(i, 1, n) {
		pair<int, int> seg1 = query(a[i].A, 0), seg2 = query(a[i].B, 1);
		L[i] = seg1.x, R[i] = seg1.y;
		L[i + n] = seg2.x, R[i + n] = seg2.y;
	}
//	For(i, 1, n) cout << W[i] << ' ';
//	cout << '\n';
	For(i, 1, q) {
		pair<int, int> seg1 = query(a[i + n].A, 0), seg2 = query(a[i + n].B, 1);
		W[i] = seg1.x;
		W[i + n] = seg2.x;
	}
//	For(i, 1, n + q) {
//		cout << str[i].hsh[0] << ' ' << str[i].hsh[1] << '\n';
//	}
//	cout << '\n';
//	cout << dfncnt[1] << '\n';
//	For(i, 1, n + q) {
//		cout << L[i] << ' ' << R[i] << '\n';
//	}
//	cout << '\n';
//	For(i, 1, n + q) cout << W[i] << ' ';
//	cout << '\n';
	sort(str + 1, str + n + q + 1, cmp);
	int l = 1, r = 1;
	while (l <= n + q) {
		while (r <= n + q && str[r].hsh[0] == str[l].hsh[0] && str[r].hsh[1] == str[l].hsh[1]) r++;
//		cout << l << ' ' << r << ":\n";
		if (str[l].hsh[0] != -1) work(l, r - 1);
		l = r;
		r++;
	}
	For(i, 1, q) cout << ans[i] << '\n';
	return 0;
} 
