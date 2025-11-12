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
}

inline namespace Base {
	#define siz(A) int((A).size())
	#define bug(x) << #x << '=' << (x) << ' '

	template<typename T>
	inline T& Max(T &x, const T &y) { return x = max(x, y); }
	template<typename T>
	inline T& Min(T &x, const T &y) { return x = min(x, y); }

	mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
	inline ll get_rnd(ll l, ll r) { return uniform_int_distribution<ll>(l, r)(rnd); }
	inline ll get_rnd_w(ll l, ll r, ll t) {
		ll res = get_rnd(l, r);
		while (t > 0) Max(res, get_rnd(l, r)), --t;
		while (t < 0) Min(res, get_rnd(l, r)), ++t;
		return res;
	}
}

int n; ll V;

void gen_tc() {
		n = get_rnd(1, 7) * 2, V = 2e4;
	wrln(n);
	for (int i = 1; i<= n; ++i) wrln(get_rnd(0, V), get_rnd(0, V), get_rnd(0, V));
	return;
}
void NamespaceMain() {
	int T = get_rnd(1, 3);
	wrln(T);
	while (T--) gen_tc();
	return;
}
}
int main() {
	ignore = freopen("club.in", "w", stdout);
	MyNamespace::NamespaceMain();
	return 0;
}