#include <bits/stdc++.h>

#define rep(it, st, ed) for(int it = st; it <= (ed); it++)
#define per(it, st, ed) for(int it = ed; it >= (st); it--)
#define Rep(it, st, ed) for(int it = st; it < (ed); it++)
#define pn putchar('\n');
#define ps putchar(' ');

#define INF 0x3F3F3F3F
#define LINF ((ll)0x3F3F3F3F3F3F3F3F) 
using ll = long long;
using lf = double;
using ld = long double;

template<class T> void cmax(T& x, const T& y) { if(x < y) x = y; }
template<class T> void cmin(T& x, const T& y) { if(x > y) x = y; } 

template<class T>
void qr(T& x) {
	x = 0;
	int c, sg = 0;
	while(!isdigit(c = getchar())) if(c == '-') sg = 1;
	do x = (x << 3) + (x << 1) + (c ^ '0');
	while(isdigit(c = getchar()));
	if(sg) x = -x;
}
template<class T>
void qw(T x) {
	static int bf[123];
	int bp = 0;
	if(x == 0) return putchar('0'), void();
	if(x < 0) putchar('-'), x = -x;
	while(x)
	{
		bf[++bp] = x % 10;
		x /= 10;
	}
	per(i, 1, bp) putchar(bf[i] + '0');
}

#define M 998244353ll
void ADD(ll& x, ll y) {
	x += y;
	if(x >= M) x -= M;
}
ll MOD(ll x, ll y) {
	ADD(x, y);
	return x;
}

bool _st;

const int N = 500 + 5;
int n, m, c[N];
char w[N];

ll f[1 << 19][20];
::std::vector<int> st[20];
int popc[1 << 19];

bool _ed;
int main() { //::std::cerr << (&_st - &_ed) / 1024. / 1024 << ::std::endl;
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	qr(n), qr(m);
	scanf("%s", w + 1);
	rep(i, 1, n) qr(c[i]);
	int sn = (1 << n) - 1;
	rep(s, 0, sn)
	{
		int x = s;
		while(x) popc[s]++, x -= x & -x;
		st[popc[s]].emplace_back(s);
	}
	f[0][0] = 1;
	Rep(i, 0, n)
	{
		for(int s : st[i])
		{
			rep(j, 0, i)
			{
				rep(k, 1, n) if(!((s >> (k - 1)) & 1))
				{
					if(j >= c[k] || w[i + 1] == '0')
						ADD(f[s ^ (1 << (k - 1))][j + 1], f[s][j]);
					else
						ADD(f[s ^ (1 << (k - 1))][j], f[s][j]);
				}
			}
		}
	}
	ll ans = 0;
//	rep(i ,1, n)
//	{
//		for(int s : st[i])
//		{
//			rep(j, 0, i)
//			{
//				Rep(k, 0, n) qw((s >> k) & 1);
//				ps;
//				qw(j);
//				ps;
//				qw(f[s][j]), pn;
//			}
//		}
//		pn;
//	}
	rep(i, 0, n) if(n - i >= m) ADD(ans, f[sn][i]);
	qw(ans), pn;
	return 0;
}

/*
10 5
1101111011
6 0 4 2 1 2 5 4 3 3
*/



















