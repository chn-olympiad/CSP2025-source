#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	int n, m, a[105] = {0};
	cin >> n >> m;
	for (int i = 0; i < n * m; i++) {
		cin >> a[i];
	}
	int xr = a[0], l = 0, o = 0;
	sort(a, a + n *m);
	for (int i =  n * m - 1; i >= 0 ; i--) {
		o++;
		if (a[i] == xr)
			l = o;
	}
	int q = 1, j = 1, h = -1;
	for (int i = 1; i <= m; i++) {
		if (h == -1)
			while (j <= n) {
				if (l == q) {
					cout << i << " " << j;
					return 0;
				}
				q++;
				j++;
			} else {
			while (j > 0) {
				if (l == q) {
					cout << i << " " << j;
					return 0;
				}
				q++;
				j--;
			}
		}


		if (h == -1)
			j--;
		else
			j++;
		h *= -1;
	}
	return 0;
	fclose(stdin);
	fclose(stdout);
	return 0;
}