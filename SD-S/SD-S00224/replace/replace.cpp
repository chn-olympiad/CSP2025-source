#include <cstdio>
#include <cstring>
#include <map>
#include <tuple>
#include <bitset>
#include <vector>
#define BFR 1048576
#define MXN 200008
#define MXL 5000008
#define MOD 998244353
#define uint unsigned int
#define iword long long
#define word unsigned iword
#define inl inline
#define reg register
#define fname "replace"
using namespace std;
char bufr[2][MXL], obuf[BFR], ibuf[BFR];
word ksmv[MXL][2];
int n, m, optr, iptr, ilmt = BFR;

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
void wti(reg int x) {
	static char buf[32];
	reg int ptr = 0;
	if(x == 0) return wtc('0');
	if(x < 0) wtc('-'), x = -x;
	while(x) buf[ptr++] = x % 10 + '0', x /= 10;
	while(ptr) wtc(buf[--ptr]);
}
inl int rdi(void) {
	reg int res = 0;
	reg char c, s = 0;
	while((c = rdc()) != char(255) && (c < '0' || c > '9'))
		s ^= c == '-';
	while(c >= '0' && c <= '9')
		res = (res << 3) + (res << 1) + (c - '0'), c = rdc();
	return s ? -res : res;
}
inl int rds(reg char *s) {
	reg char c;
	reg int res = 0;
	while((c = rdc()) != char(255) && c <= ' ');
	while(c > ' ') *(s++) = c, ++res, c = rdc();
	*s = 0;
	return res;
}
inl word hash0(reg const char *s, reg int len) {
	reg word res = 0;
	for(reg int i = 0; i < len; ++i)
		res = res * 131 + (s[i] - 'a');
	return res;
}
inl word hash1(reg const char *s, reg int len) {
	reg word res = 0;
	for(reg int i = 0; i < len; ++i)
		res = res * 1007 + s[i];
	return res;
}

typedef tuple<int, word, word, word, word> hash_pair;
typedef tuple<int, int> root_pair;
struct node {
	int son[26];
	vector<int> endian;
	inl node() {
		memset(son, 0, sizeof son);
	}
};
map<hash_pair, root_pair> pool;
vector<node> trie;
vector<int> clr;
bitset<MXN> vis;

inl const hash_pair calc(int len, int off) {
	return make_tuple(len,
	                  hash0(bufr[0] + off, len),
	                  hash1(bufr[0] + off, len),
	                  hash0(bufr[1] + off, len),
	                  hash1(bufr[1] + off, len)
	                 );
}
#define NEWNODEDEF(u) if(!u) u = trie.size(), trie.emplace_back()
inl int push_pre(int u, int rb, int idx) {
	NEWNODEDEF(u);
	int res = u;
	for(int i = rb; i;) {
		int c0 = bufr[0][--i] - 'a';
		NEWNODEDEF(trie[u].son[c0]);
		u = trie[u].son[c0];
	}
	trie[u].endian.push_back(idx);
	return res;
}
inl int push_suf(int u, int lb, int rb, int idx) {
	NEWNODEDEF(u);
	int res = u;
	for(int i = lb + 1; i < rb; ++i) {
		int c0 = bufr[0][i] - 'a';
		NEWNODEDEF(trie[u].son[c0]);
		u = trie[u].son[c0];
	}
	trie[u].endian.push_back(idx);
	return res;
}
inl void check_pre(int u, int rb) {
	if(!u) return ;
	for(int i : trie[u].endian) clr.push_back(i), vis[i] = 1;
	for(int i = rb; i;) {
		int c0 = bufr[0][--i] - 'a';
		u = trie[u].son[c0];
		if(!u) break;
		for(int i : trie[u].endian) clr.push_back(i), vis[i] = 1;
	}
}
inl int check_suf(int u, int lb, int rb) {
	if(!u) return 0;
	int res = 0;
	for(int i : trie[u].endian) res += !!vis[i];
	for(int i = lb + 1; i < rb; ++i) {
		int c0 = bufr[0][i] - 'a';
		u = trie[u].son[c0];
		if(!u) break;
		for(int i : trie[u].endian) res += !!vis[i];
	}
	return res;
}

int main (void) {
	freopen(fname".in", "r", stdin);
	freopen(fname".out", "w", stdout);
	n = rdi(), m = rdi();
	trie.emplace_back();
	for(int i = 0; i < n; ++i) {
		int l = rds(bufr[0]), lb = rds(bufr[1]), rb;
		for(lb = 0; lb < l && bufr[0][lb] == bufr[1][lb]; ++lb);
		for(rb = l; rb > 0 && bufr[0][rb] == bufr[1][rb]; --rb);
		if(lb == l) continue;
		hash_pair hp = calc(rb - lb + 1, lb);
		auto it = pool.find(hp);
		if(it == pool.end()) {
			int lrot = push_pre(0, lb, i);
			int rrot = push_suf(0, rb, l, i);
			pool.insert(make_pair(hp,root_pair(lrot, rrot)));
		} else {
			push_pre(get<0>(it->second), lb, i);
			push_suf(get<1>(it->second), rb, l, i);
		}
	}
	while(m--) {
		int l = rds(bufr[0]), lb, rb;
		if(l != rds(bufr[1])) {
noway:
			wtc('0'), wtc(10);
			continue;
		}
		for(lb = 0; lb < l && bufr[0][lb] == bufr[1][lb]; ++lb);
		for(rb = l; rb > 0 && bufr[0][rb] == bufr[1][rb]; --rb);
		hash_pair hp = calc(rb - lb + 1, lb);
		auto it = pool.find(hp);
		if(it == pool.end()) goto noway;
		check_pre(get<0>(it->second), lb);
		int ans = check_suf(get<1>(it->second), rb, l);
		for(int i : clr) vis[i] = 0;
		clr.clear();
		wti(ans), wtc(10);
	}
	if(optr) fwrite(obuf, optr, 1, stdout);
	return 0;
}
