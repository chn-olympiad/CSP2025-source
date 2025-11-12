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
constexpr int N = 1e5 + 5;
int T, n, a[N][4];

namespace BF {
	int ans, cnt[4];
	void dfs(int i, int cur) {
		if(i == n + 1) return ans = std::max(ans, cur), void();
		for(auto& o : {1, 2, 3}) {
			if(cnt[o] >= (n >> 1)) continue;
			cnt[o]++;
			dfs(i + 1, cur + a[i][o]);
			cnt[o]--;
		}
	}
	void main() {
		ans = cnt[1] = cnt[2] = cnt[3] = 0;
		dfs(1, 0);
		printf("%d\n", ans);
	}
}

namespace subtaskA {
	void main() {
		int ans = 0;
		std::vector<int> vec;
		for(int i = 1; i <= n; i++) vec.push_back(a[i][1]);
		std::sort(vec.begin(), vec.end(), std::greater<int>());
		for(int i = 1; i <= (n >> 1); i++) ans += vec[i - 1];
		printf("%d\n", ans);
	}
}

namespace subtaskB {
	void main() {
		int ans = 0;
		std::vector<int> vec;
		for(int i = 1; i <= n; i++) ans += a[i][1], vec.push_back(a[i][2] - a[i][1]);
		std::sort(vec.begin(), vec.end(), std::greater<int>());
		for(int i = 1; i <= (n >> 1); i++) ans += vec[i - 1];
		printf("%d\n", ans);
	}
}

namespace sol {
	constexpr int M = 1e3 + 5;
	int u[N], v[N], w[N], dp[M][M];
	bool vis[N];
	inline int calc(int _w, int _u, int _v) {
		int res = 0;
		for(int i = 1; i <= n; i++) u[i] = a[i][_u], v[i] = a[i][_v], w[i] = a[i][_w];
		for(int i = 1; i <= n; i++) res += w[i], u[i] -= w[i], v[i] -= w[i];
		for(int i = 1; i <= n; i++) for(int j = 1; j <= n; j++) dp[i][j] = 0;
		dp[1][1] = u[1], dp[1][0] = v[1];
		int _ = 0;
		if(1 >= (n >> 1)) _ = std::max(dp[1][1], dp[1][0]);
		for(int i = 2; i <= n; i++) {
			for(int j = 0; j <= i; j++) {
				if(j == 0) dp[i][j] = dp[i - 1][j] + v[i];
				else if(j == i) dp[i][j] = dp[i - 1][j - 1] + u[i];
				else dp[i][j] = std::max(dp[i - 1][j - 1] + u[i], dp[i - 1][j] + v[i]);
				if(i >= (n >> 1) && j <= (n >> 1) && i - j <= (n >> 1)) _ = std::max(_, dp[i][j]);
			}
		}
		res += _;
		return res;
	}
	void main() {
		int ans = std::max({calc(1, 2, 3), calc(2, 1, 3), calc(3, 1, 2)});
		printf("%d\n", ans);
	}
}

inline void solve() {
	read(n);
	bool A = 1, B = 1;
	for(int i = 1; i <= n; i++) read(a[i][1], a[i][2], a[i][3]);
	for(int i = 1; i <= n; i++) {
		A &= a[i][2] == 0 && a[i][3] == 0;
		B &= a[i][3] == 0;
	}
	if(n <= 10) return BF::main();
	if(A) return subtaskA::main();
	if(B) return subtaskB::main();
	sol::main();
}

signed main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	for(read(T); T--; ) solve();
	return 0;
}
/*
3
4
4 2 1
3 2 4
5 3 4
3 5 1
4
0 1 0
0 1 0
0 2 0
0 2 0
2
10 9 8
4 0 0

18
4
13
*/
