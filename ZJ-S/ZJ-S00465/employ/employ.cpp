#include <bits/stdc++.h>
#define gc() (iS == iT && (iT = (iS = buf) + fread(buf, 1, 1 << 20, stdin), iS == iT) ? EOF : *iS++)
char buf[1 << 20], *iS = buf, *iT = buf;
template <typename _Tp> inline void read(_Tp& x) {
	x = 0; char c = gc(); bool f = 0;
	for(; !std::isdigit(c); c = gc()) f |= c == '-';
	for(; std::isdigit(c); c = gc()) x = x * 10 + (c ^ 48);
	if(f) x = ~x + 1;
}
template <> inline void read(std::string& x) {
	x.clear(); char c = gc();
	for(; !std::isgraph(c); c = gc());
	for(; std::isgraph(c); c = gc()) x += c;
}
template <typename _Tp, typename ...Args>
inline void read(_Tp& x, Args& ...args) {
	read(x), read(args...);
}
typedef long long i64;
constexpr int N = 505;
constexpr int mod = 998244353;
inline void inc(int& x, int y) { (x += y) >= mod && (x -= mod); }
inline void dec(int& x, int y) { (x += mod - y) >= mod && (x -= mod); }
inline int add(int x, int y) { inc(x, y); return x; }
inline int sub(int x, int y) { dec(x, y); return x; }
int n, m, a[N], c[N], p[N];
std::string s;

namespace BF {
	bool vis[N];
	int dfs(int i, int cnt, int res) {
		if(res + (n - i + 1) < m) return 0;
		if(i == n + 1 && res >= m) return 1;
		int ret = 0;
		for(int pi = 1; pi <= n; pi++) {
			if(vis[pi]) continue;
			if(cnt >= c[pi] || a[i] == 0) {
				vis[pi] = 1;
				ret += dfs(i + 1, cnt + 1, res);
				vis[pi] = 0;
			} else {
				vis[pi] = 1;
				ret += dfs(i + 1, cnt, res + 1);
				vis[pi] = 0;
			}
		}
		return ret;
	}
	signed main() {
		printf("%d\n", dfs(1, 0, 0));
		return 0;
	}
}

namespace subtaskA {
	signed main() {
		int fac = 1;
		for(int i = 1; i <= n; i++) fac = 1ll * fac * i % mod;
		printf("%d\n", fac);
		return 0;
	}
}

namespace subtaskM {
	signed main() {
		bool f = 1;
		for(int i = 1; i <= n; i++) f &= a[i];
		if(!f) puts("0");
		else {
			int fac = 1;
			for(int i = 1; i <= n; i++) fac = 1ll * fac * i % mod;
			printf("%d\n", fac);
		}
		return 0;
	}
}

namespace leq18 {
	signed main() {
		std::vector<int> pos;
		for(int i = 1; i <= n; i++) if(a[i]) pos.push_back(i);
		int popcnt = pos.size();
		std::sort(c + 1, c + n + 1);
		for(int S = 0; S < (1 << popcnt); S++) {
			std::vector<int> p;
			for(int i = 0; i < popcnt; i++) {
				if(S >> i & 1) p.push_back(pos[i]);
			}
			std::sort(p.begin(), p.end());
			for(int i = 1; i <= n; i++) {
				;
			}
		}
		return 0;
	}
}

signed main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	read(n, m, s);
	bool A = 0; int cnt = 0;
	for(int i = 1; i <= n; i++) a[i] = s[i - 1] - '0', A &= a[i], cnt += a[i];
	for(int i = 1; i <= n; i++) read(c[i]);
//	if(cnt <= 18) leq18::main();
	if(A) return subtaskA::main();
	if(m == n) return subtaskM::main();
	return BF::main();
}
/*
3 2
101
1 1 2

2

10 5
1101111011
6 0 4 2 1 2 5 4 3 3

2204128
*/
