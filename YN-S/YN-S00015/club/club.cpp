#include <bits/stdc++.h>
using namespace std;
int n, t;

struct asd {
	int a, b, c;
} f[10086];

struct wasd {
	int id, s;
} x[10086];
wasd y[10086], a1[10086], b1[10086], c1[10086];

bool cmp(wasd a, wasd b) {
	return a.s > b.s;
}

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin >> t;
	for (int i = 1; i <= t; i++) {
		cin >> n;
		for (int j = 1; j <= n; j++) {
			cin >> f[j].a >> f[j].b >> f[j].c;
			x[j].s = max(f[j].a, max(f[j].b, f[j].c));
			if (x[j].s == f[j].a) {
				x[j].id = 1;
			} else if (x[j].s == f[j].b) {
				x[j].id = 2;
			} else {
				x[j].id = 3;
			}
			y[j].s = f[j].a + f[j].b + f[j].c - x[j].s - min(f[j].a, min(f[j].b, f[j].c));
			if (y[j].s == f[j].a) {
				y[j].id = 1;
			} else if (y[j].s == f[j].b) {
				y[j].id = 2;
			} else {
				y[j].id = 3;
			}
		}
		int ag = 0, bg = 0, cg = 0;
		int k = n / 2;
		for (int j = 1; j <= n; j++) {
			if (x[j].id == 1) {
				ag++;
				a1[ag].s = x[j].s;
				a1[ag].id = j;
			} else if (x[j].id == 2) {
				bg++;
				b1[bg].s = x[j].s;
				b1[bg].id = j;
			} else {
				cg++;
				c1[cg].s = x[j].s;
				c1[cg].id = j;
			}
		}
		sort(a1 + 1, a1 + ag + 1, cmp);
		sort(b1 + 1, b1 + bg + 1, cmp);
		sort(c1 + 1, c1 + cg + 1, cmp);
		if (ag > k) {
			for (int l = ag; l > k; l--) {
				if (y[a1[l].id].id == 2 && bg < k && y[a1[l - 1].id].s + a1[l].s <= y[a1[l].id].s + a1[l - 1].s) {
					bg++;
					b1[bg].s = y[a1[l].id].s;
					sort(b1 + 1, b1 + bg + 1, cmp);
				} else if (y[a1[l].id].id == 2 && y[a1[l].id].s > b1[bg].s && bg == k) {
					cg++;
					c1[cg].s = b1[bg].s;
					c1[cg].id = b1[bg].id;
					b1[bg].s = y[a1[l].id].s;
					b1[bg].id = l;
				} else if (y[a1[l - 1].id].s + a1[l].s > y[a1[l].id].s + a1[l - 1].s) {
					bg++;
					b1[bg].s = y[a1[l - 1].id].s;
					sort(b1 + 1, b1 + bg + 1, cmp);
					a1[l - 1].s = a1[l].s;
					a1[l - 1].id = a1[l].id;
				} else {
					cg++;
					c1[cg].s = a1[l].s;
					c1[cg].id = a1[l].id;
				}
				ag--;
			}
		}
		if (bg > k) {
			for (int l = bg; l > k; l--) {
				if (y[b1[l].id].id == 1 && ag < k && y[b1[l - 1].id].s + b1[l].s <= y[b1[l].id].s + b1[l - 1].s) {
					ag++;
					a1[ag].s = y[b1[l].id].s;
					sort(a1 + 1, a1 + ag + 1, cmp);
				} else if (y[b1[l].id].id == 1 && y[b1[l].id].s > a1[ag].s && ag == k) {
					cg++;
					c1[cg].s = a1[ag].s;
					c1[cg].id = a1[ag].id;
					a1[ag].s = y[b1[l].id].s;
					a1[ag].id = l;
				} else if (y[b1[l - 1].id].s + b1[l].s > y[b1[l].id].s + b1[l - 1].s) {
					ag++;
					a1[ag].s = y[b1[l - 1].id].s;
					sort(a1 + 1, a1 + ag + 1, cmp);
					b1[l - 1].s = b1[l].s;
					b1[l - 1].id = b1[l].id;
				} else {
					cg++;
					c1[cg].s = b1[l].s;
					c1[cg].id = b1[l].id;
				}
				bg--;
			}
		}
		if (cg > k) {
			for (int l = cg; l > k; l--) {
				if (y[c1[l].id].id == 1 && ag < k && y[b1[l - 1].id].s + b1[l].s <= y[b1[l].id].s + b1[l - 1].s) {
					ag++;
					a1[cg].s = y[c1[l].id].s;
					sort(a1 + 1, a1 + ag + 1, cmp);
				} else if (y[c1[l].id].id == 1 && y[c1[l].id].s > a1[ag].s && ag == k) {
					bg++;
					b1[cg].s = a1[ag].s;
					b1[cg].id = a1[ag].id;
					a1[ag].s = y[c1[l].id].s;
					a1[ag].id = l;
				} else if (y[b1[l - 1].id].s + b1[l].s > y[b1[l].id].s + b1[l - 1].s) {
					ag++;
					a1[ag].s = y[b1[l - 1].id].s;
					sort(a1 + 1, a1 + ag + 1, cmp);
					b1[l - 1].s = b1[l].s;
					b1[l - 1].id = b1[l].id;
				} else {
					bg++;
					b1[bg].s = c1[l].s;
					b1[bg].id = c1[l].id;
				}
				cg--;
			}
		}
		int ans = 0;
		for (int l = 1; l <= ag; l++) {
			ans += a1[l].s;
		}
		for (int l = 1; l <= bg; l++) {
			ans += b1[l].s;
		}
		for (int l = 1; l <= cg; l++) {
			ans += c1[l].s;
		}
		cout << ans << endl;
	}
	return 0;
}