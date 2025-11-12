#include <bits/stdc++.h>

using namespace std;

#define int long long

int _;
inline int read() {int s = 0, w = 1;char ch = getchar();while (ch < '0' || ch > '9') {if (ch == '-') w *= -1;ch = getchar();}while (ch >= '0' && ch <= '9') {s = (s << 3) + (s << 1) + (ch ^ 48);ch = getchar();}return s * w;}
inline void write(int x) {if (x < 0) x = -x, putchar('-');if (x > 9) write(x / 10);putchar(x % 10 + '0');}

int n, m;

inline void solve() {
	n = read(), m = read();
	write(m);
}

signed main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
//	_ = read();
	_ = 1;
	for (int i = 1; i <= _; ++i) solve();
	return 0;
}
