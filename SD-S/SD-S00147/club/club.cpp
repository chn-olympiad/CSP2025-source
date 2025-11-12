#include <bits/stdc++.h>
using namespace std;
const int N = 110000;
int t, n;
int a[N][5];
int ans, now;
struct node {
	int fir, sec;
	bool operator < (const node& cmp) const {
		return fir - sec < cmp.fir - cmp.sec;
	}
};
inline int read() {
	int x = 0, f = 1;
	char ch = getchar();
	while (ch < '0' || ch > '9') {
		if (ch == '-') f = -1;
		ch = getchar();
	}
	while (ch >= '0' && ch <= '9') {
		x = x * 10 + ch - '0';
		ch = getchar();
	}
	return x * f;
}
multiset<node> x, y, z;
int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	t = read();
	while (t--) {
		x.clear(), y.clear(), z.clear();
		ans = 0;
		n = read();
		for (int i = 1; i <= n; i++) {
			a[i][1] = read(), a[i][2] = read(), a[i][3] = read();
			if (a[i][1] >= a[i][2] && a[i][1] >= a[i][3]) {
				if ((int)x.size() < (n / 2)) {
					ans += a[i][1];
					x.insert(node{a[i][1], max(a[i][2], a[i][3])});
				} else {
					now = a[i][1] - max(a[i][2], a[i][3]);
					node sum = *(x.begin());
					if (now > sum.fir - sum.sec) {
						ans -= sum.fir;
						ans += sum.sec;
						ans += a[i][1];
						x.erase(x.begin());
						x.insert(node{a[i][1], max(a[i][2], a[i][3])});
					} else {
						ans += max(a[i][2], a[i][3]);
					} 
				}
			} else if (a[i][2] >= a[i][1] && a[i][2] >= a[i][3]) {
				if ((int)y.size() < (n / 2)) {
					ans += a[i][2];
					y.insert(node{a[i][2], max(a[i][1], a[i][3])});
				} else {
					now = a[i][2] - max(a[i][1], a[i][3]);
					node sum = *(y.begin());
					if (now > sum.fir - sum.sec) {
						ans -= sum.fir;
						ans += sum.sec;
						ans += a[i][2];
						y.erase(y.begin());
						y.insert(node{a[i][2], max(a[i][1], a[i][3])});
					} else {
						ans += max(a[i][1], a[i][3]);
					}
				}
			} else {
				if ((int)z.size() < (n / 2)) {
					ans += a[i][3];
					z.insert(node{a[i][3], max(a[i][1], a[i][2])});
				} else {
					now = a[i][3] - max(a[i][1], a[i][2]);
					node sum = *(z.begin());
					if (now > sum.fir - sum.sec) {
						ans -= sum.fir;
						ans += sum.sec;
						ans += a[i][3];
						z.erase(z.begin());
						z.insert(node{a[i][3], max(a[i][1], a[i][2])});
					} else {
						ans += max(a[i][1], a[i][2]);
					}
				}
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}
