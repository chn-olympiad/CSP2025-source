#include<bits/stdc++.h>
using namespace std;

namespace MyNamespace {
typedef long long ll;

inline namespace MyIO {
	inline ll rd() {
		ll s = 0, w = 1;
		char ch = char(getchar());
		while (!isdigit(ch)) {
			if (ch == '-') w = -1;
			ch = char(getchar());
		}
		while (isdigit(ch)) {
			s = (s << 3) + (s << 1) + (ch ^ 48);
			ch = char(getchar());
		}
		return (s * w);
	}
	template<typename T>
	inline void wr(T x) {
		if (x < 0) x = -x, putchar('-');
		if (x > 9) wr(x / 10);
		putchar(x % 10 + 48);
		return;
	}
	inline void wrsp() {}
	template<typename T, typename... Args>
	inline void wrsp(T x, Args... args) { wr(x), putchar(' '), wrsp(args...); }
	inline void wrln() { putchar('\n'); }
	template<typename T>
	inline void wrln(T x) { wr(x), wrln(); }
	template<typename T, typename... Args>
	inline void wrln(T x, Args... args) { wrsp(x), wrln(args...); }

	inline void rd_str(string &s) {
		char ch = char(getchar());
		while (!isalpha(ch)) ch = char(getchar());
		while (isalpha(ch)) {
			s += ch;
			ch = char(getchar());
		}
		return;
	}
}

inline namespace Base {
	#define siz(A) int((A).size())
	#define bug(x) << #x << '=' << (x) << ' '

	template<typename T>
	inline T& Max(T &x, const T &y) { return x = max(x, y); }
	template<typename T>
	inline T& Min(T &x, const T &y) { return x = min(x, y); }
}

constexpr int fn = 8e5, fidx = 5e6;
constexpr int N = fn + 10, Idx = fidx + 10;

int n, qn;
struct nde {
	string s, t, u, d, v; // d: diff
	int id;
	inline void init(int _id) {
		id = _id;
		rd_str(s), rd_str(t);
		if (siz(s) != siz(t)) return u.clear(), d.clear(), v.clear(), void();
		int l = -1, r = -1;
		for (int i = 0; i < siz(s); ++i) if (s[i] != t[i]) { l = i; break; }
		for (int i = siz(s) - 1; i >= 0; --i) if (s[i] != t[i]) { r = i; break; }
		if (!~l || !~r) return u.clear(), d.clear(), v.clear(), void();
		u = s.substr(0, l), d = s.substr(l, r - l + 1), v = s.substr(r + 1, siz(s) - (r + 1));
		return;
	}
} a[N];
int ans[N];

int idx, tr[Idx][27], fa[Idx], g[Idx];
inline int new_nde() {
	int x = ++idx;
	memset(tr[x], 0, sizeof(tr[x]));
	fa[x] = 0, g[x] = 0;
	return;
}
void init() {
	idx = 0, new_nde();
	return;
}
void ins(const nde &A) {
	int x = 1;
	auto push_back_char = [&](int ch) -> void {
		int &v = tr[x][ch];
		if (!v) v = new_nde();
		x = v;
		return;
	};
	for (char ch : A.u) push_back_char(ch - 'a');
	push_back_char(26);
	for (char ch : A.v) push_back_char(ch - 'a');
	++g[x];
	return;
}
void bld() {
	static int que[Idx]; int *hd = que, *tl = que;
	for (int j = 0; j <= 26; ++j) {
		int &v = tr[1][j];
		if (v) fa[v] = 1, *tl++ = v;
		else v = 1;
	}
	while (hd < tl) {
		int x = *hd++;
		for (int j = 0; j <= 26; ++j) {
			int &v = tr[x][j], w = tr[fa[x]][j];
			if (v) fa[v] = w, *tl++ = v;
			else v = w;
		}
	}
	return;
}
int H[Idx];
struct edg {
	int t, nxt;
} E[Idx]; int E_l;
inline void add_edg(int x, int y) {
	E[++E_l] = {y, H[x]};
	H[x] = E_l;
	return;
}
void dfs(int x) {
	for (int i = H[x]; i > 0; i = E[i].nxt) {
		int v = E[i].t;
		g[v] += g[x], dfs(v);
	}
	return;
}
void proc_g() {
	E_l = 0;
	for (int x = 2; x <= idx; ++x) add_edg(fa[x], x);
	dfs(1);
	return;
}
int parse(const nde &A) {
	int x = 1, res = 0;
	res += g[x];
	auto push_back_char = [&](int ch) -> void {
		x = tr[x][ch];
		res += g[x];
		return;
	};
	for (char ch : A.u) push_back_char(ch - 'a');
	push_back_char(26);
	for (char ch : A.v) push_back_char(ch - 'a');
	return res;
}

void bld_AC_automaton(int l, int r) { // [l, r)
	init();
	for (int i = l; i < r; ++i) if (!a[i].id) {
		ins(a[i]);
	}
	bld();
	proc_g();
	return;
}
void answer_qrys(int l, int r) { // [l, r)
	for (int i = l; i < r; ++i) if (a[i].id) {
		ans[a[i].id] = parse(a[i]);
	}
	return;
}

void NamespaceMain() {
	n = rd(), qn = rd();
	for (int i = 1; i <= n; ++i) a[i].init(0);
	for (int i = 1; i <= qn; ++i) a[n + i].init(i), ans[i] = 0;

	#warning stable_sort
	stable_sort(a + 1, a + n + qn + 1, [&](const nde &A, const nde &b) -> bool { return A.d < B.d; });

	int l = 1;
	while (l <= n + qn && siz(a[l].s) == 0) ++l;
	for (int r; l <= n + qn; l = r) {
		r = l;
		while (r <= n + qn && a[r].d == a[l].d) ++r;
		bld_AC_automaton(l, r);
		answer_qrys(l, r);
	}

	for (int i = 1; i <= qn; ++i) wrln(ans[i]);
	return;
}
}
int main() {
	MyNamespace::NamespaceMain();
	return 0;
}