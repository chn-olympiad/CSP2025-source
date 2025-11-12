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

const int maxn = 2e5, maxL = 2.5e6;
int n, q, flg = 1; 
struct Str{ string s1, s2; int len; } s[maxn]; vector<int> pos[maxL]; 
string t1, t2; 
int plc[maxn], dlt[maxn];

inline int chk(int l, int r, int p)
{
//	cerr << ' ' << l << ' ' << r << ' ' << p << endl; 
	for (int i = 0; i <= r - l; ++i) if (s[p].s1[i] != t1[l + i] || s[p].s2[i] != t2[l + i]) return 0; return 1; 
}

int main()
{
	freopen("replace.in", "r", stdin); freopen("replace.out", "w", stdout); 
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0); 
	cin >> n >> q;
	rep(i, 1, n) { cin >> s[i].s1 >> s[i].s2; s[i].len = s[i].s1.size(); pos[s[i].len].pbk(i); }
	rep(i, 1, n) 
	{ 
		int cnta = 0, cntb = 0;
		for (int j = 0; j < s[i].len; ++j) 
		{
			if (s[i].s1[j] == 'a') ++cnta; 
			else if (s[i].s1[j] == 'b') ++cntb; 
		}
		if (cnta + cntb != s[i].len || cntb != 1) { flg = 0; break; }
		cnta = cntb = 0; 
		for (int j = 0; j < s[i].len; ++j)
		{
			if (s[i].s2[j] == 'a') ++cnta; 
			else if (s[i].s2[j] == 'b') ++cntb; 
		}
		if (cnta + cntb != s[i].len || cntb != 1) { flg = 0; break; }
	}
	if (flg)
	{
		rep(i, 1, n)
		{
			int x1 = 0, x2 = 0;
			for (int j = 0; j < s[i].len; ++j) 
			{
				if (s[i].s1[j] == 'b') x1 = j; 
				if (s[i].s2[j] == 'b') x2 = j;
			}
			plc[i] = x1; dlt[i] = x2 - x1;
		}
	}
	while (q--)
	{
		cin >> t1 >> t2; 
		if (t1.size() != t2.size()) { puts("0"); continue; }
		int l = -1, r = -1, m = t1.size();
		if (flg)
		{
			int cnt = 0; 
			for (int j = 0; j < m && flg; ++j)
			{
				if (t1[j] == 'b' && l == -1) l = j; else if (t1[j] == 'b') flg = 0;  
				if (t2[j] == 'b' && r == -1) r = j; else if (t2[j] == 'b') flg = 0;
			}
			if (flg)
			{
				rep(i, 1, n)
				{
					if (dlt[i] != r - l) continue;  
					if (plc[i] > l || l - plc[i] + s[i].len > m) continue; 
					++cnt;
				}
				write(cnt); pc(0xa); 
			}
			
		}
		if (flg) continue; 
		l = r = -1; 
		for (int i = 0; i < m; ++i) if (t1[i] != t2[i]) { if (l == -1) l = i; r = i; }
		int cnt = 0;
		for (int i = 0; i <= l; ++i) for (int j = r; j < m; ++j)
		{
			for (int p : pos[j - i + 1]) cnt+= chk(i, j, p);
		}
		write(cnt); pc(0xa); 
	}
	return 0; 
}
/*
4 2
xabcx xadex
ab cd
bc de
aa bb
xabcx xadex
aaaa bbbb

3 4
a b
b c
c d
aa bb
aa b
a c
b a
*/

