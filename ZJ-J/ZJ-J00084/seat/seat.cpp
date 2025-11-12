#include <bits/stdc++.h>

using namespace std;

int _;
inline int read() {int s = 0, w = 1;char ch = getchar();while (ch < '0' || ch > '9') {if (ch == '-') w *= -1;ch = getchar();}while (ch >= '0' && ch <= '9') {s = (s << 3) + (s << 1) + (ch ^ 48);ch = getchar();}return s * w;}
inline void write(int x) {if (x < 0) x = -x, putchar('-');if (x > 9) write(x / 10);putchar(x % 10 + '0');}

const int N = 15;
int n, m, x;
int cnt = 1;
int a1, a2;

inline void solve() {
	n = read(), m = read();
	x = read();
	for (int i = 2; i <= n * m; ++i) {
		int y = read();
		if (y > x) cnt++;
	}
	int l = ceil(cnt * 1.0 / n), r = cnt % n;
	a1 = l;
	if (r == 0) {
		a2 = (l % 2 == 1 ? m : 1);
	} else if (l & 1) {
		a2 += r;
	} else {
		a2 += (m - r + 1);
	}
	write(a1), putchar(' '), write(a2);
}

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
//	_ = read();
	_ = 1;
	for (int i = 1; i <= _; ++i) solve();
	return 0;
}
