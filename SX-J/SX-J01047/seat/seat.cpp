#include <bits/stdc++.h>
using namespace std;
int n, m, a[105];

int main() {
	freopen("seat.in", "r", stdin), freopen("seat.out", "w", stdout);
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n >> m;
	int nm = n * m;
	for (int i = 1; i <= nm; i++) {
		cin >> a[i];
	}
	int r = a[1];
	sort(a + 1, a + nm + 1);
	reverse(a + 1, a + nm + 1);
	int len;
	for (int i = 1; i <= nm; i++) {
		if (r == a[i]) {
			len = i;
			break;
		}
	}
	int x = 1, y = 1;
	len--;
	while (len) {
		len--;
		if ((y % 2 == 1 && x == n) || (y % 2 == 0 && x == 1)) {
			y++;
			continue;
		}
		if (y % 2 == 1)
			x++;
		else
			x--;
	}
	cout << y << ' ' << x;
	return 0;
}
