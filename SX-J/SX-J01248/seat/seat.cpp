#include <bits/stdc++.h>
using namespace std;
int a[105];

bool cmp(int x, int y) {
	return x > y;
}

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	int n, m, id, c, r;
	cin >> n >> m;
	for (int i = 1; i <= n * m; i++)
		cin >> a[i];
	int flag = a[1];
	sort(a + 1, a + n *m + 1, cmp);
	for (int i = 1; i <= n * m; i++) {
		if (a[i] == flag) {
			id = i;
			break;
		}
	}
	if (id % n != 0)
		c = id / n + 1;
	else
		c = id / n;
	if (c % 2 != 0) {
		if (id % n != 0)
			r = id % n;
		else
			r = m;
	} else {
		if (id % n != 0)
			r = n - id % n + 1;
		else
			r = 1;
	}
	cout << c << " " << r;
	return 0;
}
