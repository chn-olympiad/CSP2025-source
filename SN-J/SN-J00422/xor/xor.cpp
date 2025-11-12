#include <bits/stdc++.h>
#define il inline

using namespace std;

const int bufsz = 1 << 20;
char ibuf[bufsz], *p1 = ibuf, *p2 = ibuf;
#define getchar() (p1 == p2 && (p2 = (p1 = ibuf) + fread(ibuf, 1, bufsz, stdin), p1 == p2) ? EOF : *p1++)
il int read() {
	int x = 0; char ch = getchar(); bool t = 0;
	while (ch < '0' || ch > '9') {t ^= ch == '-'; ch = getchar();}
	while (ch >= '0' && ch <= '9') {x = (x << 1) + (x << 3) + (ch ^ 48); ch = getchar();}
	return t ? -x : x;
}
bool Beg;
const int INF = 0x3f3f3f3f;
const int N = 5e5 + 10, M = 3e6 + 10;
int n, kk, a[N];
int s[N], f[N], p[M];
bool End;
il void Usd() {cerr << "\nUse: " << (&Beg - &End) / 1024.0 / 1024.0 << "MB " << (double)clock() * 1000.0 / CLOCKS_PER_SEC << "ms\n";}
signed main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
//	freopen("xor6.in", "r", stdin);
//	freopen("mine.out", "w", stdout);
//	system("fc xor6.ans mine.out"); return 0;
	n = read(), kk = read();
	for (int i = 1; i <= n; i++) a[i] = read();
	for (int i = 1; i <= n; i++) {
		s[i] = (s[i - 1] ^ a[i]);
	}
	for (int i = 0; i <= n; i++) f[i] = -INF;
	f[0] = 0;
	for (int i = 1; i <= n; i++) {
		f[i] = f[i - 1];
		if (p[kk ^ s[i]] || s[i] == kk) {
			f[i] = max(f[i], f[p[kk ^ s[i]]] + 1);
		}
		p[s[i]] = i;
	}
//	cout << "F "; for (int i = 1; i <= n; i++) cout << f[i] << " "; cout << "\n";
	printf("%d\n", f[n]);
	
//	Usd();
	return 0;
}
