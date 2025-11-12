#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 10;
int n0, n, ans, cnta, cntb, cntc;

struct node {
	int a, b, c, opt;
};
node il[MAXN];

bool cmp(node a, node b) {
	int ca, cb, c1a, c1b;
	if (a.opt == 1)
		ca = a.a - a.b, c1a = a.b - a.c;
	else if (a.opt == 2)
		ca = a.a - a.c, c1a = a.c - a.b;
	else if (a.opt == 3)
		ca = a.b - a.a, c1a = a.a - a.c;
	else if (a.opt == 4)
		ca = a.b - a.c, c1a = a.c - a.a;
	else if (a.opt == 5)
		ca = a.c - a.a, c1a = a.a - a.b;
	else
		ca = a.c - a.b, c1a = a.b - a.a;
	if (b.opt == 1)
		cb = b.a - b.b, c1b = b.b - b.c;
	else if (b.opt == 2)
		cb = b.a - b.c, c1b = b.c - b.b;
	else if (b.opt == 3)
		cb = b.b - b.a, c1b = b.a - b.c;
	else if (b.opt == 4)
		cb = b.b - b.c, c1b = b.c - b.a;
	else if (b.opt == 5)
		cb = b.c - b.a, c1b = b.a - b.b;
	else
		cb = b.c - b.b, c1b = b.b - b.a;
	if (ca > cb)
		return true;
	else if (ca == cb && c1a > c1b)
		return true;
	return false;
}

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> n0;
	while (n0--) {
		cin >> n;
		for (int i = 1; i <= n; i++) {
			cin >> il[i].a >> il[i].b >> il[i].c;
			if (il[i].a >= il[i].b && il[i].b >= il[i].c)
				il[i].opt = 1;
			else if (il[i].a >= il[i].c && il[i].c >= il[i].b)
				il[i].opt = 2;
			else if (il[i].b >= il[i].a && il[i].a >= il[i].c)
				il[i].opt = 3;
			else if (il[i].b >= il[i].c && il[i].c >= il[i].a)
				il[i].opt = 4;
			else if (il[i].c >= il[i].a && il[i].a >= il[i].b)
				il[i].opt = 5;
			else
				il[i].opt = 6;
		}
		sort(il + 1, il + n + 1, cmp);
		ans = 0;
		cnta = 0, cntb = 0, cntc = 0;
		for (int i = 1; i <= n; i++) {
			if (il[i].opt == 1) {
				if (cnta < n / 2) {
					ans += il[i].a;
					cnta++;
				} else {
					ans += il[i].b;
					cntb++;
				}
			} else if (il[i].opt == 2) {
				if (cnta < n / 2) {
					ans += il[i].a;
					cnta++;
				} else {
					ans += il[i].c;
					cntc++;
				}
			} else if (il[i].opt == 3) {
				if (cntb < n / 2) {
					ans += il[i].b;
					cntb++;
				} else {
					ans += il[i].a;
					cnta++;
				}
			} else if (il[i].opt == 4) {
				if (cntb < n / 2) {
					ans += il[i].b;
					cntb++;
				} else {
					ans += il[i].c;
					cntc++;
				}
			} else if (il[i].opt == 5) {
				if (cntc < n / 2) {
					ans += il[i].c;
					cntc++;
				} else {
					ans += il[i].a;
					cnta++;
				}
			} else if (il[i].opt == 6) {
				if (cntc < n / 2) {
					ans += il[i].c;
					cntc++;
				} else {
					ans += il[i].b;
					cntb++;
				}
			}
		}
		cout << ans << '\n';
	}
	return 0;
}