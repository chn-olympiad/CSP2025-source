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
const int mod(998244353);
const int N = 500;
int n, m, a[N], c[N], d[N];
ll ans;
bool p[N], ops(1);
inline void dfs(int dep, int ex, int pass) {
	if (d[dep] + pass < m) return ;
	if (pass >= m) {
		ll ops(1);
		foru(i, 2, n - dep + 1) (ops *= i) %= mod;
		(ans += ops) %= mod;
		return ;
	}
	if (dep > n)
		return (ans += (pass >= m)) %= mod, void();
	foru(i, 1, n) if (!p[i]) {
		p[i] = 1;
		if (a[dep] && ex < c[i]) dfs(dep + 1, ex, pass + 1);
		else dfs(dep + 1, ex + 1, pass);
		p[i] = 0;
	}
}
inline void Hridaya() {
	n = read(), m = read();
	foru(i, 1, n) {
		while (ch != '0' && ch != '1') ch = getchar();
		a[i] = ch == '1', ch = getchar(), ops = ops && a[i];
	}
	foru(i, 1, n) c[i] = read();
	ford(i, n, 1) d[i] = d[i + 1] + a[i];
	
//	if (ops) {
//		ans = 1; int l(0);
//		foru(i, 1, n) if (c[i]) ++l;
//		foru(i, 2, l) (ans *= i) %= mod;
//		writes(ans);
//		return ;
//	}
	
	dfs(1, 0, 0), writes(ans);
}
signed main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	int T(1);
	while(T--) Hridaya();
	fclose(stdin); fclose(stdout);
	return 0;
}
