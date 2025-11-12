#include <bits/stdc++.h>
using namespace std;

struct s {
	int cj;
	bool r = 0;
} a[1005];

bool cmp(s a, s b) {
	return a.cj > b.cj;
}

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	int n, m, rcj, rr;
	cin >> n >> m;
	int v[n][m];
	for (int i = 1; i <= n * m; i++)
		cin >> a[i].cj;
	a[1].r = 1;

	sort(a + 1, a + 1 + n *m, cmp);

	for (int i = 1; i <= n * m; i++) {
		if (a[i].r == 1) {
			rr = i;
			break;
		}
	}

	int rn = rr / n, rm = rr % n, ansn, ansm;
	if (rm != 0)
		ansn = rn + 1;
	else
		ansn = rn;
	if (rm == 0 && rn % 2 == 0 )
		ansm = m;
	else if (rm == 0 && (rn - 1) % 2 != 0 )
		ansm = 1;
	else if (rm != 0 && rn % 2 != 0 )
		ansm = rm;
	else if (rm != 0 && rn % 2 == 0 )
		ansm = m - rm + 1;
	cout << ansn << " " << ansm;
	return 0;
}
