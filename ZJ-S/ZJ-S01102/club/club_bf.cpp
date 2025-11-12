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

constexpr int fn = 2e6;
constexpr int N = fn + 10;

int n; ll a[N][3];

int cnt[3]; ll ans;
void enm(int p, ll sum) {
	if (p > n) {
		bool fl = 1;
		for (int j = 0; j < 3; ++j) if (cnt[j] > n / 2) { fl = 0; break; }
		if (fl) {
			Max(ans, sum);
		}
		return;
	}
	for (int j = 0; j < 3; ++j) {
		++cnt[j], enm(p + 1, sum + a[p][j]);
		--cnt[j];
	}
	return;
}

void solve_tc() {
		n = rd();
	for (int i = 1; i <= n; ++i) for (int j = 0; j < 3; ++j) a[i][j] = rd();

	ans = 0;
	enm(1, 0);
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
	ignore = freopen("club_bf.out", "w", stdout);
	MyNamespace::NamespaceMain();
	return 0;
}