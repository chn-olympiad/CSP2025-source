#include <bits/stdc++.h>
using namespace std;
int a[110];

bool cmp(int a, int b) {
	return a > b;
}

signed main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n, m;
	cin >> n >> m;
	int t = n * m;
	for (int i = 1; i <= t; i++) {
		cin >> a[i];
	}
	int mb = a[1];
	sort(a + 1, a + 1 + t, cmp);
	//for (int i = 1; i <= t; i++) {
	//	cout << a[i] << " ";
	//}
	int j = 1;
	while (a[j] != mb && j < t)
		j++;
	int x = 1, y = 1;
	while (j > 1) {
		j--;
		if (x % 2 == 1) {
			if (y == n)
				x++;
			else
				y++;
		} else {
			if (y == 1)
				x++;
			else
				y--;
		}
	}
	cout << x << " " << y;
	return 0;
}