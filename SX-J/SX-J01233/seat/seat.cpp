#include <bits/stdc++.h>
using namespace std;
int f[105];
int m, n, rs, nows, wh, am, an;

bool cmp(int x, int y) {
	return x > y;
}

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			nows++;
			cin >> f[nows];
			if (nows == 1)
				rs = f[nows];
		}
	}
	sort(f + 1, f + (m *n) + 1, cmp);
	for (int i = 1; i <= m * n; i++) {
		if (f[i] == rs) {
			wh = i;
			break;
		}
	}
	if (m == 1 && an == 1) {
		am = 1;
		an = 1;
	} else {
		if (wh % n == 0) {
			am = wh / n;
			if (am % 2 == 0)
				an = 1;
			else
				an = n;
		} else {
			am = wh / n + 1;
			wh -= (am - 1) * n;
			if (am % 2 == 0)
				an = n - wh + 1;
			else
				an = wh;
		}
	}
	if (an == 0)
		an = 1;
	cout << am << " " << an;
	return 0;
}
