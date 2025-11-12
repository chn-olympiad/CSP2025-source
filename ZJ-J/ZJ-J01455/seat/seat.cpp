#include <bits/stdc++.h>
using namespace std;
int a[200];
bool cmp(int l, int r) {
	return l > r;
}
signed main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);	cout.tie(0);
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n * m; i ++) 	cin >> a[i];
	int R = a[1], id = 0;
	sort(a + 1, a + n * m + 1, cmp);
	for (int i = 1; i <= n * m; i ++) {
		if (R == a[i]) {
			id = i;
			break;
		}
	}
	if (id % n == 0) {
		if ((id / n) % 2 == 0)	cout << id / n << " " << 1;
		else					cout << id / n << " " << n;
	} else {
		if ((id / n + 1) % 2 == 0)	cout << id / n + 1 << " " << n - id % n + 1;
		else						cout << id / n + 1 << " " << id % n;					
	}
	return 0;
}
