#include <bits/stdc++.h>
using namespace std;
int n, m;
int a[105];

bool cmp(int x, int y) {
	return x > y;
}

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n * m; i++) {
		cin >> a[i];
	}
	int s = a[1];
	sort(a + 1, a + n *m + 1, cmp);
	int c = 1, r = 1;
	for (int i = 1; i <= n * m; i++) {
		if (a[i] == s) {
			cout << c << ' ' << r;
			return 0;
		}
		if ((r == n && c % 2 == 1) || (r == 1 && c % 2 == 0))
			c++;
		else if (c % 2 == 0)
			r--;
		else
			r++;
	}
}