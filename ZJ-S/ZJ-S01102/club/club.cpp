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
}

constexpr ll INF = 1e18;

constexpr int fn = 1e6;
constexpr int N = fn + 10;

int n;
struct nde : array<ll, 3> {
	// ll get_max() const {
	// 	return max((*this)[0], (*this)[1], (*this)[2]);
	// }
	pair<ll, int> get_max() const {
		return max(max(make_pair((*this)[0], 0), make_pair((*this)[1], 1)), make_pair((*this)[2], 2));
	}
	ll get_se_max() const {
		auto pi = this->get_max();
		ll z = -INF;
		for (int j = 0; j < 3; ++j) if (j != pi.second) Max(z, (*this)[j]);
		return z;
	}
	ll lost_value() const {
		return this->get_max().first - this->get_se_max();
	}
} a[N];
int cnt[3];

void solve_tc() {
	n = int(rd());
	for (int i = 1; i <= n; ++i) for (int j = 0; j < 3; ++j) a[i][j] = rd();

	for (int j = 0; j < 3; ++j) cnt[j] = 0;
	ll ans = 0;
	for (int i = 1; i <= n; ++i) {
		auto pi = a[i].get_max();
		ans += pi.first;
		++cnt[pi.second];
	}

	int p = -1;
	for (int j = 0; j < 3; ++j) if (cnt[j] > n / 2) { p = j; break; }
	if (~p) {
		nde *ed = partition(a + 1, a + n + 1, [&](const nde &A) -> bool { return A.get_max().second == p; });
		sort(a + 1, ed, [&](const nde &A, const nde &B) -> bool { return A.lost_value() < B.lost_value(); });
		for (nde *it = a + 1; it < min(a + cnt[p] - n / 2 + 1, ed); ++it) {
			ans -= it->lost_value();
		}
	}
	wrln(ans);
	return;
}
void NamespaceMain() {
	int T = rd();
	while (T--) solve_tc();
	return;
}
}
int main() {
	ignore = freopen("club.in", "r", stdin);
	ignore = freopen("club.out", "w", stdout);
	MyNamespace::NamespaceMain();
	return 0;
}