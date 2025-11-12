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
const int N = 1e6 + 10;
char s[N], t[N];
int n, tot;
bool End;
il void Usd() {cerr << "\nUse: " << (&Beg - &End) / 1024.0 / 1024.0 << "MB " << (double)clock() * 1000.0 / CLOCKS_PER_SEC << "ms\n";}
signed main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
//	freopen("number4.in", "r", stdin);
//	freopen("mine.out", "w", stdout);
//	system("fc number4.ans mine.out"); return 0;
	ios::sync_with_stdio(0); cin.tie(0), cout.tie(0);
	cin >> (s + 1);
	n = strlen(s + 1);
	for (int i = 1; i <= n; i++) {
		if (s[i] >= '0' && s[i] <= '9') {
			t[++tot] = s[i];
		}
	}
	sort(t + 1, t + 1 + tot);
	for (int i = tot; i >= 1; i--) {
		cout << t[i];
	}
	
//	Usd();
	return 0;
}
