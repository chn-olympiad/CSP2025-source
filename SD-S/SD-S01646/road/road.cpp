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

bool _st;

const int N = 1e4 + 5;
const int M = 1e6 + 5;
int a[12][N], n, m, cst[12];
struct T {
	int u, v, w, i;
} e[M + N * 10];
int ep, k;

int fa[N], siz[N];
int F(int x) {
	while(x ^ fa[x]) x = fa[x] = fa[fa[x]];
	return x;
}
bool merge(int u, int v) {
	int x = F(u), y = F(v);
	if(x == y) return 0;
	if(siz[x] < siz[y]) ::std::swap(x, y);
	fa[y] = x;
	siz[x] += y;
	return 1;
}

namespace Subtask1 {

int cs[22];

ll ans = LINF;
void mst() {
	ll res = 0;
	rep(i, 1, n + k) fa[i] = i, siz[i] = 1;
	int cnt = n;
	rep(i, 1, k) cnt += cs[i], res += cs[i] * cst[i];
	rep(i, 1, ep)
	{
		if(cnt == 1) break;
		if(!cs[e[i].i]) continue;
		int u = e[i].u, v = e[i].v;
		if(!merge(u, v)) continue;
		res += e[i].w;
		cnt--;
	}
	cmin(ans, res);
}

void run()  {
	int sk = (1 << k) - 1;
	cs[0] = 1;
	ep = m;
	rep(i, 1, k)
	{
		rep(j, 1, n)
			e[++ep] = {n + i, j, a[i][j], i};
	}
	::std::sort(e + 1, e + 1 + ep, [](const T& lhs, const T& rhs) {
		return lhs.w < rhs.w;
	});
	rep(s, 0, sk)
	{
		rep(i, 1, k) if((s >> (i - 1)) & 1) cs[i] = 1; else cs[i] = 0;
		mst();
	}
	qw(ans), pn;
}

}

bool _ed;
int main() { // ::std::cerr << (&_st - &_ed) / 1024. / 1024 << ::std::endl;
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	qr(n), qr(m), qr(k);
	rep(i, 1, m)
	{
		int u, v, w;
		qr(u), qr(v), qr(w);
		e[i] = {u, v, w, 0};
	}
	rep(i, 1, k)
	{
		qr(cst[i]);
		rep(j, 1, n)
			qr(a[i][j]);
	}
	Subtask1::run();
	return 0;
}

/*
4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
1 1 8 2 4
100 1 3 2 4
*/



















