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

constexpr int fn = 1e6;
constexpr int N = fn + 10;

int n, qn;
string a[N][2], b[2];

void NamespaceMain() {
	n = rd(), qn = rd();
	for (int i = 1; i <= n; ++i) cin >> a[i][0] >> a[i][1];
	for (int h = 1; h <= qn; ++h) {
		cin >> b[0] >> b[1];
		// cerr bug(b[0]) bug(b[1]) << endl;
		ll ans = 0;
		for (int j = 0; j < siz(b[0]); ++j) {
			for (int i = 1; i <= n; ++i) {
				if (j + siz(a[i][0]) <= siz(b[0]) && b[0].substr(j, siz(a[i][0])) == a[i][0]) {
					if (string(b[0]).replace(j, siz(a[i][0]), a[i][1]) == b[1]) {
						// cerr bug(b[0]) bug(j) bug(i) bug(a[i][0]) bug(a[i][1]) bug(string(b[0]).substr(j, siz(a[i][0]), a[i][1])) << endl;
						++ans;
					}
				}
			}
		}
		wrln(ans);
	}
	return;
}
}
int main() {
	ignore = freopen("replace.in", "r", stdin);
	ignore = freopen("replace_bf.out", "w", stdout);
	MyNamespace::NamespaceMain();
	return 0;
}