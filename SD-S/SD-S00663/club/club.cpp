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

const int N = 100010;

int n, a[N], b[N], c[N];
struct node {
	int x, v;
	bool operator < (const node &cmp) const {
		return v > cmp.v;
	}
};

void mymain() {
	read(n);
	priority_queue <node> q1, q2, q3;
	int res = 0;
	F(i, 1, n) {
		read(a[i]), read(b[i]), read(c[i]);
		int mx = max(max(a[i], b[i]), c[i]);
		if (a[i] == mx) q1.push({i, a[i]-max(b[i],c[i])});
		else if (b[i] == mx) q2.push({i, b[i]-max(a[i],c[i])});
		else q3.push({i, c[i]-max(a[i],b[i])});
		res += mx;
	}
	while (max(max(SZ(q1), SZ(q2)), SZ(q3)) > n/2) {
		if (SZ(q1) > n/2) res -= q1.top().v, q1.pop();
		else if (SZ(q2) > n/2) res -= q2.top().v, q2.pop();
		else res -= q3.top().v, q3.pop();
	}
	printf("%d\n", res);
}

void myclear() {
}

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int _ = 1;
	read(_);
	F(ca, 1, _) {
		mymain();
		if (ca < _) myclear();
	}
	return 0;
}

