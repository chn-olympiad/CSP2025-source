#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1e5+5;
int TT, n;

struct Q {
	int a, b, c;
} q[N];

struct T {
	int a, b, c, id;
	int f;
	int zab, zac, zbc, zcd;
} p[N];

bool cmp1(T a, T b) {
	return a.zab > b.zab;
}

bool cmp2(T a, T b) {
	return a.zcd > b.zcd;
}

bool cmp3(T a, T b) {
	return max(a.a, a.c) > max(b.a, b.c);
}

bool cmp4(T a, T b) {
	return max(a.b, a.c) > max(b.b, b.c);
}

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> TT;
	while (TT--) {
		cin >> n;
		memset(p, 0, sizeof p);
		for (int i = 1; i <= n; i++) {
			cin >> q[i].a >> q[i].b >> q[i].c;
			int t = max(q[i].a, max(q[i].b, q[i].c));
			p[i].a = q[i].a - t;
			p[i].b = q[i].b - t;
			p[i].c = q[i].c - t;
			p[i].id = i;
			p[i].zab = p[i].a - p[i].b;
			p[i].zac = p[i].a - p[i].c;
			p[i].zbc = p[i].b - p[i].c;
		}
		int ta = 0, tb = 0;
		sort(p + 1, p + n + 1, cmp1);
		for (int i = 1; i <= n; i++) {
			if (p[i].zab > 0) {
				p[i].f = 1;
				ta = i;
			} else {
				if (ta <= n / 2 && p[i].zab >= 0) {
					p[i].f = 1;
					ta = i;
				} else {
					p[i].f = 2;
				}
			}
			if (p[i].f == 1)
				p[i].zcd = -p[i].zac;
			else
				p[i].zcd = -p[i].zbc;
		}
		tb = n - ta;
		sort(p + 1, p + n + 1, cmp2);
		for (int i = 1; i <= n / 2; i++) {
			if (p[i].zcd >= 0) {
				if (p[i].f == 1)
					ta--;
				else
					tb--;
				p[i].f = 3;
			}
		}
		if (tb > (n / 2)) {
			sort(p + 1, p + n + 1, cmp3);
			for (int i = 1; i <= n; i++) {
				if (tb <= (n / 2)) {
					break;
				}
				if (p[i].f != 2)
					continue;
				tb--;
				if (p[i].a > p[i].c) {
					p[i].f = 1;
				} else {
					p[i].f = 3;
				}
			}
		}
		if (ta > (n / 2)) {
			sort(p + 1, p + n + 1, cmp4);
			for (int i = 1; i <= n; i++) {
				if (ta <= (n / 2)) {
					break;
				}
				if (p[i].f != 1)
					continue;
				ta--;
				if (p[i].b > p[i].c) {
					p[i].f = 2;
				} else {
					p[i].f = 3;
				}
			}
		}
		ll sum = 0;
		for (int i = 1; i <= n; i++) {
			if (p[i].f == 1) {
				sum += q[p[i].id].a;
			} else if (p[i].f == 2) {
				sum += q[p[i].id].b;
			} else {
				sum += q[p[i].id].c;
			}
		}
		cout << sum << '\n';
	}
	return 0;
}/*3
4
4 2 1
3 2 4
5 3 4
3 5 1
4
0 1 0
0 1 0
0 2 0
0 2 0
2
10 9 8
4 0 0*/
