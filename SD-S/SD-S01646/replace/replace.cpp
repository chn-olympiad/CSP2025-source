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
using ul = unsigned long long;

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

const int L = 5e6 + 5;
const int N = 2e5 + 5;
const ul P = 131;
ul pw[L], hs1[L], hs2[L], h1[N], h2[N];
int len[N];
int n, q;
char s[L], t[L];
ul geths(int l, int r, ul* hs) {
	return hs[r] - hs[l - 1] * pw[r - l + 1];
}

bool _ed;
int main() { //::std::cerr << (&_st - &_ed) / 1024. / 1024 << ::std::endl;
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	pw[0] = 1;
	Rep(i, 1, L) pw[i] = pw[i - 1] * P;
	qr(n), qr(q);
	rep(i, 1, n)
	{
		scanf("%s", s + 1);
		int w = strlen(s + 1);
		len[i] = w;
		rep(j, 1, w) h1[i] = h1[i] *P + s[j];
		scanf("%s", s + 1);
		rep(j, 1, w) h2[i] = h2[i] *P + s[j];
	}
	while(q--)
	{
		scanf("%s %s", s + 1, t + 1);
		int w1 = strlen(s + 1), w2 = strlen(t + 1);
		if(w1 != w2) {
			puts("0");
			continue;
		}
		int ans = 0, w = w1, lp = 0, rp = 0;
		rep(i, 1, w) hs1[i] = hs1[i - 1] * P + s[i];
		rep(i, 1, w) hs2[i] = hs2[i - 1] * P + t[i];
		rep(i, 1, w) if(s[i] != t[i]) {
			lp = i;
			break;
		}
		per(i, 1, w) if(s[i] != t[i]) {
			rp = i;
			break;
		}
//		printf("[%d %d]", lp, rp);
		rep(i, 1, n)
		{
			if(len[i] < rp - lp + 1) continue;
			rep(j, 1, w)
			{
				if(j + len[i] - 1 > w) break;
				if(geths(j, j + len[i] - 1, hs1) == h1[i] &&
				   geths(j, j + len[i] - 1, hs2) == h2[i] &&
				   j <= lp && j + len[i] - 1 >= rp) {
					ans++;
					break;
				}
			}
		}
		qw(ans), pn;
	}
	return 0;
}

/*
10 5
1101111011
6 0 4 2 1 2 5 4 3 3
*/



















