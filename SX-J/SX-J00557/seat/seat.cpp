#include <bits/stdc++.h>
using namespace std;
#define int long long
int a[105];

int cmp(int x, int y) {
	return x > y;
}

signed main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	int r;
	cin >> r;
	a[1] = r;
	for (int i = 2; i <= n * m; i++) {
		cin >> a[i];
	}
	sort(a + 1, a + 1 + n *m, cmp);
	int mc;
	for (int i = 1; i <= n * m; i++) {
		if (a[i] == r)
			mc = i;
	}
	int hang = mc % n, lie = mc / n;
	if (mc % n > 0) {
		lie++;
	}
	if (lie % 2 == 0)
		hang = hang - (lie % n) + 1;
	if (hang == 0)
		hang = n;
	cout << lie << ' ' << hang << endl;
	return 0;
}
