#include <bits/stdc++.h>
using namespace std;

struct node {
	int vis;
	bool flag;
};
node a[105];

bool cmp(node x, node y) {
	return x.vis > y.vis;
}

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	a[1].flag = true;
	for (int i = 1; i <= n * m; i++) {
		cin >> a[i].vis;
	}
	sort(a + 1, a + n *m + 1, cmp);
	int l = 1, h = 1, vis = 0;
	while (a[++vis].flag != true && vis < n * m) {
		if (h % 2 != 0) {
			l++;
		} else {
			l--;
		}
		if (l > m) {
			h++;
			l = m;
		}
		if (l < 1) {
			h++;
			l = 1;
		}

	}
	cout << h << ' ' << l;
	return 0;
}
