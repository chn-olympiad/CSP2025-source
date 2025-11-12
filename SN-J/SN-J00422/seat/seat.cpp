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
const int N = 110;
int n, m;
struct node {
	int v, id;
	il bool operator < (const node & cmp) const {
		return v > cmp.v;
	}
} a[N];
bool End;
il void Usd() {cerr << "\nUse: " << (&Beg - &End) / 1024.0 / 1024.0 << "MB " << (double)clock() * 1000.0 / CLOCKS_PER_SEC << "ms\n";}
signed main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	n = read(), m = read();
	for (int i = 1; i <= n * m; i++) {
		a[i].v = read();
		a[i].id = i;
	}
	sort(a + 1, a + 1 + n * m);
	int id = 0;
	for (int i = 1; i <= n * m && !id; i++) {
		if (a[i].id == 1) id = i;
	}
	int x = 0, y = 0;
	y = id / (2 * n) * 2;
	id %= (2 * n);
	if (id <= n) {
		y++;
		x = id;
	} else {
		y += 2;
		x = n - (id - n) + 1;
	}
	printf("%d %d\n", y, x);
	
//	Usd();
	return 0;
}
