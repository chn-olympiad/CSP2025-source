#include <cstdio>
#include <tuple>
#include <vector>
#include <algorithm>
#define BFR 1048576
#define MXN 10008
#define MOD 998244353
#define uint unsigned int
#define iword long long
#define word unsigned iword
#define inl inline
#define reg register
#define fname "road"
using namespace std;
char ibuf[BFR], obuf[BFR];
int optr, iptr, ilmt = BFR;

inl void wtc(char c) {
	if(optr == BFR) fwrite(obuf, BFR, 1, stdout), optr = 0;
	obuf[optr++] = c;
}
inl char rdc(void) {
	if(iptr == ilmt)
		if(ilmt == BFR) ilmt = fread(ibuf, 1, BFR, stdin), iptr = 0;
		else ibuf[ilmt = iptr = 0] = 255;
	return ibuf[iptr++];
}
inl iword rdi(void) {
	reg iword res = 0;
	reg char c, s = 0;
	while((c = rdc()) != char(255) && (c < '0' || c > '9'))
		s ^= c == '-';
	while(c >= '0' && c <= '9')
		res = (res << 3) + (res << 1) + (c - '0'), c = rdc();
	return s ? -res : res;
}
void wti(reg iword x) {
	static char buf[32];
	reg int ptr = 0;
	if(x == 0) return wtc('0');
	if(x < 0) wtc('-'), x = -x;
	while(x) buf[ptr++] = x % 10 + '0', x /= 10;
	while(ptr) wtc(buf[--ptr]);
}

typedef tuple<int, int, int> t3i;
int fat[MXN], c[10], a[10][MXN];
int n, m, k;
vector<t3i> eg;
inl int getf(int u) {
	if(u == fat[u]) return u;
	return fat[u] = getf(fat[u]);
}
inl void uni(int u, int v) {
	fat[getf(u)] = getf(v);
}
inl void solve0(void) {
	iword ans = 0;
	for(reg int i = 1; i <= n; ++i) fat[i] = i;
	for(const t3i &e : eg) {
		int u, v, w;
		tie(u, v, w) = e;
		if(getf(u) == getf(v)) continue;
		uni(u, v), ans += w;
	}
	wti(ans);
}


int main(void) {
	freopen(fname".in", "rb", stdin);
	freopen(fname".out", "wb", stdout);
	n = rdi(), m = rdi(), k = rdi();
	eg.reserve(m);
	for(int i = 0; i < m; ++i) {
		int u = rdi(), v = rdi(), w = rdi();
		eg.emplace_back(u, v, w);
	}
	sort(eg.begin(), eg.end(), [](const t3i &x, const t3i &y) {
		return get<2>(x) < get<2>(y);
	});
	if(!k) {
		solve0();
		goto endian;
	}
	for(int i = 0; i < k; ++i) {
		c[i] = rdi();
		for(int j = 1; j <= n; ++j) a[i][j] = rdi();
	}
	wti(0);
endian:
	if(optr) fwrite(obuf, optr, 1, stdout);
	return 0;
}
