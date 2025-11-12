#include <bits/stdc++.h>

using namespace std;

namespace IO
{
#define gc getchar
#define pc putchar
template<typename T> inline void read(T& x) 
{
	x = 0; char ch = gc(); bool w = 1;
	while (!isdigit(ch)) { if (ch == 0x2d) w = 0; ch = gc(); }
	while (isdigit(ch)) { x = x * 0xa + (ch ^ 0x30); ch = gc(); }
	x = w ? x : -x; 
}
template<typename T, typename... Args> 
inline void read(T& x, Args&... args) { read(x); read(args...); }
template<typename T> inline void write(T x)
{
	if (x < 0) pc(0x2d), x = -x; if (x > 9) write(x / 0xa); pc(x % 0xa + 0x30); 
}
} using namespace IO;

typedef long long ll; 
typedef unsigned long long ull; 
#define pii pair<int, int>
#define pil pair<int, ll>
#define pli pair<ll, int>
#define pll pair<ll, ll>
#define mems(arr, v) memset(arr, v, sizeof(arr))
#define rep(i, x, y) for (int i = (x); i <= (y); ++i)
#define fep(i, y, x) for (int i = (y); i >= (x); --i)
#define pbk push_back
#define mkp make_pair
#define fst first
#define sec second

const int maxn = 505, mod = 998244353; 
int n, m, a[maxn], s[maxn], b[maxn]; 
int comb[maxn][maxn], g[maxn]; 

void init()
{
	comb[1][0] = comb[1][1] = 0; 
	rep(i, 2, n) { comb[i][0] = comb[i][i] = 1; rep(j, 1, i - 1) comb[i][j] = (comb[i - 1][j - 1] + comb[i - 1][j]) % mod; }
}


namespace Sub1
{
int vis[maxn], p[maxn], ans, count = 0;
inline int chk()
{
	int cnt = 0, cnt2 = 0; 
	rep(i, 1, n) { if (b[p[i]] > cnt2 && a[i]) ++cnt; else ++cnt2; }
	return cnt >= m ? 1 : 0; 
}
inline void dfs(int x)
{
	if (x == n + 1) { ans+= chk(); return; }
	rep(i, 1, n) if (!vis[i]) { p[x] = i; vis[i] = 1; dfs(x + 1); vis[i] = 0; }
}
inline void work()
{
	ans = 0; dfs(1); write(ans); pc(0xa);
}
}

namespace Sub2 
{
int ans = 0;
inline void work()
{
	ans = 1; rep(i, 1, n) ans = (ll)ans * i % mod; 
	write(ans); pc(0xa); 
}
}

int main()
{
	freopen("employ.in", "r", stdin); freopen("employ.out", "w", stdout); 
	read(n, m); 
	char ch = gc(); while (!isdigit(ch)) { ch = gc(); }
	rep(i, 1, n) { a[i] = ch ^ 0x30; ch = gc(); s[i] = s[i - 1] + a[i]; }
	rep(i, 1, n) read(b[i]);
	if (m > s[n]) { puts("0"); return 0; }
	init(); 
	if (n <= 18) { Sub1::work(); return 0; }
	if (n == s[n]) { Sub2::work(); return 0; } 
	return 0; 
}
/*
3 2
101
1 1 2

10 5
1101111011
6 0 4 2 1 2 5 4 3 3 
*/
