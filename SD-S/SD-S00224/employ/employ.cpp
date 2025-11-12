#include <cstdio>
#include <tuple>
#include <vector>
#include <algorithm>
#define BFR 1048576
#define MXN 513
#define MOD 998244353
#define uint unsigned int
#define iword long long
#define word unsigned iword
#define inl inline
#define reg register
#define fname "employ"
using namespace std;
char ibuf[BFR], obuf[BFR], s[MXN];
int optr, iptr, ilmt = BFR, n, m;

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
inl int rds(reg char *s) {
	reg char c;
	reg int res = 0;
	while((c = rdc()) != char(255) && c <= ' ');
	while(c > ' ') *(s++) = c, ++res, c = rdc();
	*s = 0;
	return res;
}
int c[MXN], order[16];

int od(int x) {
	int res = 0;
	if(x) {
		for(int i = 1; i <= n; ++i) {
			if(order[i]) continue;
			order[i] = x;
			res += od(x - 1);
			order[i] = 0;
		}
		return res;
	}
	for(int i = 1; i <= n; ++i){
		if(s[i] == '1' && i - res <= c[order[i]]) ++res;
		if(res >= m) return 1;
	}
	return 0;
}

int main(void) {
	freopen(fname".in", "rb", stdin);
	freopen(fname".out", "wb", stdout);
	n = rdi(), m = rdi();
	rds(s + 1);
	for(reg int i = 1; i <= n; ++i) c[i] = rdi();
	if(n <= 10) wti(od(n));
	else if(m == 1) {
		iword res = 0;
		for(int i = 1; i <= n; ++i) {
			if(s[i] == '0') continue;
			int x = 0, y = 1;
			for(int j = 1; j <= n; ++j) x += c[j] >= i;
			if(n - x < i - 1) continue;
			for(int j = 1; j < i; ++j) y = long(y) * j % MOD;
			for(int j = 1; j <= n - i; ++j) y = long(y) * j % MOD;
			res = long(res + y) * x % MOD;
		}
		wti(res);
	} else {
		int c = 0; 
		wti(0);
	}
	if(optr) fwrite(obuf, optr, 1, stdout);
	return 0;
}
