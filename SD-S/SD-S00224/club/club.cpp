#include <cstdio>
#include <tuple>
#include <queue>
#include <algorithm>
#define BFR 1048576
#define MXN 200008
#define MOD 998244353
#define uint unsigned int
#define iword long long
#define word unsigned iword
#define inl inline
#define reg register
#define fname "club"
// Ren5Jie4Di4Ling5%
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
typedef tuple<int, int, int, int>t4i;
typedef tuple<int, int> t2i;
vector<t4i> as, bs, cs;
priority_queue<int> dif;

int main(void) {
	freopen(fname".in", "r", stdin);
	freopen(fname".out", "w", stdout);
	int T = rdi();
	while(T--) {
		int n = rdi(), hn = n >> 1;
		iword ans = 0;
		as.clear(), bs.clear(), cs.clear();
		for(reg int i = 0; i < n; ++i) {
			int x = rdi(), y = rdi(), z = rdi();
			int mx = max({x, y, z});
			if(mx == x) as.emplace_back(i, x, y, z);
			else if(mx == y) bs.emplace_back(i, x, y, z);
			else cs.emplace_back(i, x, y, z);
		}
		int mxc = max({as.size(), bs.size(), cs.size()});
		if(mxc > hn) {
			while(!dif.empty()) dif.pop();
			if(as.size() == mxc) {
				for(const t4i &at : as) {
					int a = get<1>(at);
					int b = max(get<2>(at), get<3>(at));
					int d = b - a;
					ans += a, dif.push(d);
				}
				int r = as.size() - hn;
				while(r--) ans += dif.top(), dif.pop();
				for(const t4i &at : bs) ans += get<2>(at);
				for(const t4i &at : cs) ans += get<3>(at);
			} else if(bs.size() == mxc) {
				for(const t4i &at : bs) {
					int a = get<2>(at);
					int b = max(get<3>(at), get<1>(at));
					int d = b - a;
					ans += a, dif.push(d);
				}
				int r = bs.size() - hn;
				while(r--) ans += dif.top(), dif.pop();
				for(const t4i &at : as) ans += get<1>(at);
				for(const t4i &at : cs) ans += get<3>(at);
			} else {
				for(const t4i &at : cs) {
					int a = get<3>(at);
					int b = max(get<2>(at), get<1>(at));
					int d = b - a;
					ans += a, dif.push(d);
				}
				int r = cs.size() - hn;
				while(r--) ans += dif.top(), dif.pop();
				for(const t4i &at : as) ans += get<1>(at);
				for(const t4i &at : bs) ans += get<2>(at);
			}
		} else {
			for(const t4i &at : as) ans += get<1>(at);
			for(const t4i &at : bs) ans += get<2>(at);
			for(const t4i &at : cs) ans += get<3>(at);
		}
		wti(ans), wtc(10);
	}
	if(optr) fwrite(obuf, optr, 1, stdout);
	return 0;
}
