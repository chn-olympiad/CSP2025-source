#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
const int N = 1e5+5;
int T, n;

struct node {
	int a, b, c, mx, op;
	int tu;
} a[N];

bool cmp(node x, node y) {
	return x.mx > y.mx;
}

signed main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin >> T;
	while (T--) {
		cin >> n;
		int m = n / 2;
		for (int i = 1; i <= n; i++) {
			cin >> a[i].a >> a[i].b >> a[i].c;
			a[i].mx = max(a[i].a, max(a[i].b, a[i].c));
			if (a[i].mx == a[i].a) {
				a[i].op = 1;
				a[i].tu = a[i].mx - max(a[i].b, a[i].c);
			} else if (a[i].mx == a[i].b) {
				a[i].op = 2;
				a[i].tu = a[i].mx - max(a[i].a, a[i].c);
			} else if (a[i].mx == a[i].c) {
				a[i].op = 3;
				a[i].tu = a[i].mx - max(a[i].b, a[i].a);
			}
		}
		sort(a + 1, a + 1 + n, cmp);
		int vis[4] = {0};
		int sum = 0;
		priority_queue<int>q[5];
		for (int i = 1; i <= n; i++) {
			vis[a[i].op]++;
			q[a[i].op].push(-a[i].tu);
			sum += a[i].mx;
		}
		for (int l = 1; l <= 3; l++) {
			if (vis[l] > m) {
				for (int i = m + 1; i <= vis[l]; i++) {
					sum += q[l].top();
					q[l].pop();
				}
			}
		}
		cout << sum << endl;
	}
	return 0;
}
/*
1
4
0 1 0
0 1 0
0 2 0
0 2 0
*/