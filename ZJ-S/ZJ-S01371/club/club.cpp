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
#define read() read<int>()
const int N(1e5 + 10);
int n, m, maxn[N], d[N], l[9], a[N];
short id_maxn[N];
ll ans;
inline void ban(short u) {
	m = 0;
	foru(i, 1, n) if (id_maxn[i] == u) a[++m] = d[i];
	sort(a + 1, a + 1 + m); int r(m - (n / 2));
	foru(i, 1, r) ans -= a[i];
}
inline void Hridaya() {
	n = read(), ans = 0, l[1] = l[2] = l[3] = 0;
	foru(i, 1, n) {
		maxn[i] = read(), id_maxn[i] = 1;
		int x(read());
		if (x > maxn[i]) {
			d[i] = x - maxn[i];
			maxn[i] = x;
			id_maxn[i] = 2;
		} else d[i] = maxn[i] - x;
		x = read();
		if (x > maxn[i]) {
			d[i] = x - maxn[i];
			maxn[i] = x;
			id_maxn[i] = 3;
		}
		ans += maxn[i], ++l[id_maxn[i]];
	}
	if (2 * l[1] > n) ban(1);
	else if (2 * l[2] > n) ban(2);
	else if (2 * l[3] > n) ban(3);
	writes(ans);
}
signed main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int T(read());
	while(T--) Hridaya();
	fclose(stdin); fclose(stdout);
	return 0;
}
