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

const int maxn = 1e5 + 5; 
int n, ans; vector<int> v1, v2, v3; 
struct Node{ int d1, d2, d3; } a[maxn];
int tmp[maxn], cnt;

inline void work()
{
	v1.clear(); v2.clear(); v3.clear(); ans = cnt = 0; 
	read(n); rep(i, 1, n) read(a[i].d1, a[i].d2, a[i].d3);
	rep(i, 1, n)
	{
		int mx = max({a[i].d1, a[i].d2, a[i].d3}); ans+= mx;
		if (a[i].d1 == mx) { v1.pbk(i); continue; }
		if (a[i].d2 == mx) { v2.pbk(i); continue; }
		if (a[i].d3 == mx) { v3.pbk(i); continue; }
	}
	if (v1.size() <= n / 2 && v2.size() <= n / 2 && v3.size() <= n / 2) { write(ans); pc(0xa); return; }
	if (v1.size() > n / 2) { for (int i : v1) tmp[++cnt] = max(a[i].d2, a[i].d3) - a[i].d1; }
	if (v2.size() > n / 2) { for (int i : v2) tmp[++cnt] = max(a[i].d1, a[i].d3) - a[i].d2; }
	if (v3.size() > n / 2) { for (int i : v3) tmp[++cnt] = max(a[i].d1, a[i].d2) - a[i].d3; }
	sort(tmp + 1, tmp + cnt + 1); 
	for (int i = n / 2 + 1; i <= cnt; ++i) ans+= tmp[i];
	write(ans); pc(0xa); 
}

int main()
{
	freopen("club.in", "r", stdin); freopen("club.out", "w", stdout); 
	int _; read(_); while (_--) work(); 
	return 0; 
}