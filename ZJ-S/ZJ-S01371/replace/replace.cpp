#include <bits/stdc++.h>
using namespace std;
typedef int IT; typedef long long LG;
typedef short ST; typedef long long ll;
#define foru(i, l, r) for (int i = (l); i <= (r); ++i)
#define ford(i, r, l) for (int i = (r); i >= (l); --i)
char ch('~');
template<typename Type> inline Type read() {
	int x(0); bool m(0);
	while (!isdigit(ch)) {
		m |= (ch == '-');
		ch = getchar();
	}
	while (isdigit(ch)) {
		x = (x << 1) + (x << 3) + (ch - '0');
		ch = getchar();
	}
	return m ? (~x + 1) : x;
}
template<typename Type> inline void write(Type x) {
	if (x < 0) putchar('-'), x = (~x + 1);
	if (x > 9) write(x / 10);
	putchar(x % 10 + 48);
}
template<typename Type> inline void writes(Type x, char c = '\n') {
	write(x); putchar(c);
}
int id1, id2;
#define read() read<int>()
const int N(2e5 + 10);
int y_l[N], y_r[N], h_l[N], h_r[N];
inline void Hridaya() {
	int n(read()), q(read());
	foru(i, 1, n) {
		int o(0);
		while (ch < 'a' || ch > 'z') ch = getchar();
		while (ch >= 'a' && ch <= 'z') {
			++o;
			if (ch == 'b') id1 = o;
			ch = getchar();
		}
		o = 0;
		while (ch < 'a' || ch > 'z') ch = getchar();
		while (ch >= 'a' && ch <= 'z') {
			++o;
			if (ch == 'b') id2 = o;
			ch = getchar();
		}
		y_l[i] = id1 - 1, y_r[i] = n - id1;
		h_l[i] = id2 - 1, h_r[i] = n - id2;
	}
	foru(i, 1, q) {
		int o(0), x, y, ans(0);
		while (ch < 'a' || ch > 'z') ch = getchar();
		while (ch >= 'a' && ch <= 'z') {
			++o;
			if (ch == 'b') x = o;
			ch = getchar();
		}
		o = 0;
		while (ch < 'a' || ch > 'z') ch = getchar();
		while (ch >= 'a' && ch <= 'z') {
			++o;
			if (ch == 'b') y = o;
			ch = getchar();
		}
		int l_y(x - 1), r_y(o - x), l_h(y - 1), r_h(o - y);
		foru(j, 1, n) ans += (l_y >= y_l[j] && r_y >= y_r[j] && l_h >= h_l[j] && r_h >= h_r[j]);
		writes(ans);
	}
}
signed main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	int T(1);
	while(T--) Hridaya();
	fclose(stdin); fclose(stdout);
	return 0;
}
