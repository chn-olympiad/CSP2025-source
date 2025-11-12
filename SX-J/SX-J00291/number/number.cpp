#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	int n, m, c[10], d[10], e, x;
	cin >> n >> m;
	for (int i = 0; i < n * m; i++)
		cin >> c[i];
	sort(c, c + n *m);
	for (int i = m; i >= 0; i--)
		d[i] = c[i];
	for (int i = 1; i <= m; i++)
		if (d[i] == c[0])
			e = i;
	for (int i = 0; i < n * m; i++) {
		if (e >= n) {
			e -= n;
			x++;
		} else if (e < n) {
			if (x % 2 == 1) {
				cout << x + 1 << n + 1 - e % n;
			} else if (x % 2 == 0) {
				cout << x + 1 << e % n;
			}
		} else if (e == 0) {
			if (x % 2 == 1) {
				cout << x << n;
			} else if (x % 2 == 0) {
				cout << x << 1;
			}
		}
	}
	return 0;
	fclose(stdin);
	fclose(stdout);

}