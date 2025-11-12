#include <bits/stdc++.h>

using namespace std;

#define LL long long
#define LD long double
#define ull unsigned long long
#define x first
#define y second
#define F(i, a, b) for (int i = (a), i##E = (b); i <= i##E; ++i)
#define G(i, a, b) for (int i = (a), i##E = (b); i >= i##E; --i)
#define SZ(a) ((int)a.size())
#define ALL(a) a.begin(), a.end()
#define PB push_back

typedef pair <int, int> pii;
typedef pair <LL, LL> pll;
typedef pair <double, double> pdd;

inline void read(int &x) {
	x = 0; int w = 0; char ch = 0;
	while (!isdigit(ch)) w |= (ch == '-'), ch = getchar();
	while (isdigit(ch)) x = (x<<3)+(x<<1)+(ch^48), ch = getchar();
	if (w) x = -x;
}

inline void readl(LL &x) {
	x = 0; int w = 0; char ch = 0;
	while (!isdigit(ch)) w |= (ch == '-'), ch = getchar();
	while (isdigit(ch)) x = (x<<3)+(x<<1)+(ch^48), ch = getchar();
	if (w) x = -x;
}

const int mod = 998244353;

inline void ad(int &x, int y) {
	x += y;
	while (x >= mod) x -= mod;
}

const int N = 5000010, M = 200010;
const int mod1 = 1000009277, mod2 = 1000009279, P = 39509;

int n, m, c1[M], c2[M];
char a[N], b[N];
int bt1[N], bt2[N], ha1[N], hb1[N], ha2[N], hb2[N];
map <int, vector <int> > vec1[M], vec2[M];
map <pii, int> cnt[M];

inline int geta1(int l, int r) {
	return (ha1[r]-1ll*ha1[l-1]*bt1[r-l+1]%mod1+mod1)%mod1;
}
inline int geta2(int l, int r) {
	return (ha2[r]-1ll*ha2[l-1]*bt2[r-l+1]%mod2+mod2)%mod2;
}
inline int getb1(int l, int r) {
	return (hb1[r]-1ll*hb1[l-1]*bt1[r-l+1]%mod1+mod1)%mod1;
}
inline int getb2(int l, int r) {
	return (hb2[r]-1ll*hb2[l-1]*bt2[r-l+1]%mod2+mod2)%mod2;
}

void mymain() {
	read(n), read(m);
	bt1[0] = bt2[0] = 1;
	F(i, 1, N-1) bt1[i] = 1ll*bt1[i-1]*P%mod1, bt2[i] = 1ll*bt2[i-1]*P%mod2;
	map <pll, int> id, ans;
	map <LL, int> id1, id2;
	int idx = 0, idx1 = 0, idx2 = 0;
	F(u, 1, n) {
		scanf("%s%s", a+1, b+1);
		int len = strlen(a+1);
		int l = 0, r = 0;
		F(i, 1, len) {
			if (a[i] != b[i]) {
				l = i; break;
			}
		}
		if (!l) continue;
		G(i, len, 1) {
			if (a[i] != b[i]) {
				r = i; break;
			}
		}
		F(i, 1, len) {
			ha1[i] = (1ll*ha1[i-1]*P+a[i])%mod1;
			ha2[i] = (1ll*ha2[i-1]*P+a[i])%mod2;
			hb1[i] = (1ll*hb1[i-1]*P+b[i])%mod1;
			hb2[i] = (1ll*hb2[i-1]*P+b[i])%mod2;
		}
		pll h = {1ll*geta1(l,r)*mod2+geta2(l,r), 1ll*getb1(l,r)*mod2+getb2(l,r)};
		if (!id.count(h)) id[h] = ++idx;
		int o = id[h];
		LL hp = 1ll*geta1(r+1,len)*mod2+geta2(r+1,len);
		if (!id2.count(hp)) id2[hp] = ++idx2;
		int o2 = id2[hp];
		hp = 1ll*geta1(1,l-1)*mod2+geta2(1,l-1);
		if (!id1.count(hp)) id1[hp] = ++idx1;
		int o1 = id1[hp];
		vec1[o][o1].PB(o2), vec2[o][o2].PB(o1);
		cnt[o][{o1, o2}]++;
	}
	while (m--) {
		scanf("%s%s", a+1, b+1);
		int len = strlen(a+1), lenp = strlen(b+1);
		if (lenp != len) {
			puts("0"); continue;
		}
		int l = 0, r = 0;
		F(i, 1, len) {
			if (a[i] != b[i]) {
				l = i; break;
			}
		}
		if (!l) {
			puts("0"); continue;
		}
		G(i, len, 1) {
			if (a[i] != b[i]) {
				r = i; break;
			}
		}
		F(i, 1, len) {
			ha1[i] = (1ll*ha1[i-1]*P+a[i])%mod1;
			ha2[i] = (1ll*ha2[i-1]*P+a[i])%mod2;
			hb1[i] = (1ll*hb1[i-1]*P+b[i])%mod1;
			hb2[i] = (1ll*hb2[i-1]*P+b[i])%mod2;
		}
		pll h0 = {1ll*ha1[len]*mod2+ha2[len], 1ll*hb1[len]*mod2+hb2[len]};
		if (ans.count(h0)) {
			printf("%d\n", ans[h0]); continue;
		}
		pll h = {1ll*geta1(l,r)*mod2+geta2(l,r), 1ll*getb1(l,r)*mod2+getb2(l,r)};
		if (!id.count(h)) {
			puts("0"); continue;
		}
		int o = id[h];
		vector <int> v1, v2;
		F(i, 1, l) {
			LL hp = 1ll*geta1(i,l-1)*mod2+geta2(i,l-1);
			if (!id1.count(hp)) continue;
			int o1 = id1[hp];
			v1.PB(o1), c1[o1]++;
		}
		F(i, r, len) {
			LL hp = 1ll*geta1(r+1,i)*mod2+geta2(r+1,i);
			if (!id2.count(hp)) continue;
			int o2 = id2[hp];
			v2.PB(o2), c2[o2]++;
		}
		int res = 0;
		if (SZ(v2) < SZ(v1)) {
			for (int o2 : v2) {
				if (SZ(vec2[o][o2]) < SZ(v1)) {
					for (int o1 : vec2[o][o2]) res += c1[o1];
				} else {
					for (int o1 : v1) res += cnt[o][{o1, o2}];
				}
			}
		} else {
			for (int o1 : v1) {
				if (SZ(vec1[o][o1]) < SZ(v2)) {
					for (int o2 : vec1[o][o1]) res += c2[o2];
				} else {
					for (int o2 : v2) res += cnt[o][{o1, o2}];
				}
			}
		}
		for (int o1 : v1) c1[o1]--;
		for (int o2 : v2) c2[o2]--;
		printf("%d\n", res);
		ans[h0] = res;
	}
}

void myclear() {
}

int main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	int _ = 1;
//	read(_);
	F(ca, 1, _) {
		mymain();
		if (ca < _) myclear();
	}
	return 0;
}
