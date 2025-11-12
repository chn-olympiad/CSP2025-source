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

const int N = 510;

int fac[N], ifac[N];
int n, m, s[N], a[N], c[N], f[N][N];
char str[N];
int res = 0;
bool mark[N];

void dfs(int dep, int cnt) {
	if (dep == n+1) {
		if (n-cnt >= m) res++;
		return;
	}
	F(i, 1, n) {
		if (!mark[i]) {
			mark[i] = true;
			dfs(dep+1, cnt+(!s[dep] ? 1 : (cnt>=c[i]?1:0)));
			mark[i] = false;
		}
	}
}

void mymain() {
	fac[0] = ifac[0] = fac[1] = ifac[1] = 1;
	F(i, 2, N-1) ifac[i] = 1ll*ifac[mod%i]*(mod-mod/i)%mod;
	F(i, 2, N-1) fac[i] = 1ll*fac[i-1]*i%mod, ifac[i] = 1ll*ifac[i-1]*ifac[i]%mod;
	read(n), read(m);
	scanf("%s", str+1);
	F(i, 1, n) {
		s[i] = str[i]-'0';
		read(c[i]);
	}
	if (m == n) {
		F(i, 1, n) {
			if (!s[i] || !c[i]) {
				puts("0"); return;
			}
		}
		printf("%d\n", fac[n]);
		return;
	}
	if (n <= 10) {
		dfs(1, 0);
		printf("%d\n", res);
		return;
	}
	int Ss = 0;
	F(i, 1, n) Ss += s[i];
	if (Ss == n) {
		F(i, 1, n) a[c[i]]++;
		f[0][a[0]] = 1;
		F(i, 1, n) {
			if (!a[i]) {
				F(j, 0, n) f[i][j] = f[i-1][j];
				continue;
			}
		}
		return;
	}
}

void myclear() {
}

int main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	int _ = 1;
//	read(_);
	F(ca, 1, _) {
		mymain();
		if (ca < _) myclear();
	}
	return 0;
}

