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

constexpr int fn = 4e5, fidx = 5e6;
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

void bld_trie(int l, int r) { // [l, r)
	for (int i = l; i < r; ++i) {

	}
}
void answer_qrys(int l, int r) { // [l, r)

}

void NamespaceMain() {
	n = rd(), qn = rd();
	for (int i = 1; i <= n; ++i) a[i].init(0);
	for (int i = 1; i <= m; ++i) a[n + i].init(i);

	#warning stable_sort
	stable_sort(a + 1, a + n + m + 1, [&](const nde &A, const nde &b) -> bool { return A.d < B.d; });

	int l = 1;
	while (l <= n + m && siz(a[l].s) == 0) ++l;
	for (int r; l <= n + m; l = r) {
		r = l;
		while (r <= n + m && a[r].d == a[l].d) ++r;
		bld_trie(l, r);
		answer_qrys(l, r);
	}
	return;
}
}
int main() {
	MyNamespace::NamespaceMain();
	return 0;
}