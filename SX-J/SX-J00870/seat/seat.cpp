#include <bits/stdc++.h>
using namespace std;
int n, m, a[105], s[15][15];

bool cmp(int x, int y) {
	return x > y;
}

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n * m; i++)
		cin >> a[i];
	int x = a[1];
	sort(a + 1, a + n *m + 1, cmp);
	for (int i = 1, xx = 1, yy = 1; i <= n * m;) {
		if (a[i] == x) {
			cout << yy << " " << xx;
			return 0;
		}
		if (yy % 2 == 1)
			xx++, i++;
		else
			xx--, i++;
		if (a[i] == x) {
			cout << yy << " " << xx;
			return 0;
		}
		if (xx == 1 || xx == n)
			yy++, i++;
	}
	return 0;
}
