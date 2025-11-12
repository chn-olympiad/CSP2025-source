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
const int N (1e6 + 10);
struct Node {
	int u, v;
	ll w;
} a[N];
int f[N];
ll ans;
inline int find(int x) { return f[x] == x ? x : f[x] = find(f[x]); }
inline bool cmp(Node x, Node y) { return x.w < y.w; }
inline void Hridaya() {
	int n(read()), m(read()), k(read());
	foru(i, 1, m) a[i].u = read(), a[i].v = read(), a[i].w = read<ll>();
	if (k == 0) {
		foru(i, 1, n) f[i] = i;
		sort(a + 1, a + 1 + m, cmp);
		foru(i, 1, m) {
			int x(find(a[i].u)), y(find(a[i].v));
			if (x == y) continue;
			if (x < y) swap(x, y);
			ans += a[i].w;
			f[x] = y;
		}
		return writes(ans), void();
	}
	writes(0);
}
signed main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	int T(1);
	while(T--) Hridaya();
	fclose(stdin); fclose(stdout);
	return 0;
}
