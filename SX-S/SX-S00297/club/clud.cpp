#include <bits/stdc++.h>
using namespace std;

struct node {
	int a, b, c, d;
	bool s;
} st[100010];
int b[10], n;

void ma(int x, int y) {
	if (y == 2) {
		if (st[x].d == st[x].a && b[1] >= n / 2) {
			st[x].a = 0;
		}
		if (st[x].d == st[x].b && b[2] >= n / 2) {
			st[x].b = 0;
		}
		if (st[x].d == st[x].c && b[3] >= n / 2) {
			st[x].c = 0;
		}
	}
	st[x].d = max(max(st[x].a, st[x].b), st[x].c);
}

bool pi(node x, node y) {
	return x.d > y.d;
}

int main() {
	freopen("clud.in", "r", stdin);
	freopen("clud.out", "w", stdout);
	int t;
	cin >> t;
	for (int i = 1; i <= t; i++) {
		memset(b, 0, sizeof b);
		int a = 1, m = 0;
		cin >> n;
		for (int j = 1; j <= n; j++) {
			cin >> st[j].a >> st[j].b >> st[j].c;
			ma(j, a);
			st[j].s = false;
		}
		sort(st + 1, st + 1 + n, pi);
		for (int j = 1; j <= n; j++) {
			if (st[j].s == false) {
				st[j].s = true;
				m += st[j].d;
				if (st[j].d == st[j].a) {
					b[1]++;
				}
				if (st[j].d == st[j].b) {
					b[2]++;
				}
				if (st[j].d == st[j].c) {
					b[3]++;
				}
				cout << j << " ";
			}
			if ((b[1] >= n / 2 || b[2] >= n / 2 || b[3] >= n / 2) && a != 2) {
				j = 1;
				a = 2;
				for (int k = 1; k <= n; k++) {
					ma(k, a);
				}
				sort(st + 1, st + n + 1, pi);
			}
		}
		cout << m << endl;
	}
	return 0;
}
