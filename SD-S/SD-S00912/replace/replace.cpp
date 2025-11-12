#include <bits/stdc++.h>
using namespace std;

const int N1 = 200005, N2 = 5000005;
typedef long long ll;
#define rep(i, a, b) for (int i(a); i <= (b); ++i) 
template <class T> inline void ckmn(T &a, T b) { (a > b) && (a = b); }
template <class T> inline void ckmx(T &a, T b) { (a < b) && (a = b); }

bool Mbe;

int n, q, a[N2][26], b[N2][26], tot1, tot2;
char s1[N2], s2[N2];
int f[N2], fail[N2];
int qu[N2], ql, qr;

bool Med;

inline void rd(int &a, int c = 0) {
	while (!isdigit(c = getchar()));
	for (a = 0; isdigit(c); c = getchar()) a = (a << 3) + (a << 1) + (c ^ 48);
}
template <class T> void wrt(T x) {
	if (x > 9) wrt(x / 10);
	putchar(x % 10 ^ 48);
}
void ins(int len) {
	int p = 0;
	rep(i, 1, len) {
		int c1 = s1[i] - 'a', c2 = s2[i] - 'a';
		if (!a[p][c1]) a[p][c1] = ++tot1;
		if (!b[a[p][c1]][c2]) b[a[p][c1]][c2] = ++tot2;
		p = b[a[p][c1]][c2];
	}
	f[p]++;
}
void build_acam() {
	ql = 1, qr = 0;
	rep(i, 0, 25) {
		if (!a[0][i]) continue;
		rep(j, 0, 25) {
			if (b[a[0][i]][j]) qu[++qr] = b[a[0][i]][j];
		}
	}
	while (qr >= ql) {
		int u = qu[ql++];
//		cout << "+ " <<  u << endl;
		rep(i, 0, 25) {
//			cout << u << " " << i << " " << a[u][i] << endl;
			if (!a[u][i]) continue;
			int p = fail[u];
			while (p && !a[p][i]) p = fail[p];
			rep(j, 0, 25) {
				int &v = b[a[u][i]][j];
//				cout << u << "   " << v << endl; 
				if (v) fail[v] = b[a[p][i]][j], f[v] += f[fail[v]], qu[++qr] = v;
				else v = b[a[p][i]][j];
			}
		}
	}
} 
ll play(int len, int st, int tog) {
	int p = 0;
	ll ans = 0;
	rep(i, st, len) {
		int c1 = s1[i] - 'a', c2 = s2[i] - 'a';
		while (p && !a[p][c1]) p = fail[p];
		p = b[a[p][c1]][c2];
		if (i >= tog) ans += f[p]; 
	}
	return ans;
}
int main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	rd(n), rd(q);
	int sm1 = 0;
	rep(i, 1, n) {
		scanf("%s %s", s1 + 1, s2 + 1);
//		cout << "  " << s1 + 1 << " " << s2 + 1 << endl;
		int len = strlen(s1 + 1);
		ins(len);
		sm1 += len;
	}
	build_acam();
//	rep(i, 0, tot2) {
//		cout << i << " " << fail[i] << endl;
//		rep(j, 0, 25) {
//			rep(k, 0, 25) {
//				if (b[a[i][j]][k]) cout << i << " " << j << " " << k << " " << b[a[i][j]][k] << endl;
//			}
//		}
//	}
	int sm2 = 0;
	while (q--) {
		scanf("%s %s", s1 + 1, s2 + 1);
		int len = strlen(s1 + 1);
		sm2 += len;
		int mn = 1e9, mx = 0;
		rep(i, 1, len) {
			if(s1[i] != s2[i]) {
				ckmn(mn, i);
				ckmx(mx, i);
			}
		}
//		cout << mn << "  " << mx << endl;
		wrt(play(len, 1, mx) - play(len, mn + 1, mx)), putchar(10);
	}
//	cerr << sm1 << "  " << sm2;
	return 0;
}

