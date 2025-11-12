#include <bits/stdc++.h>
using namespace std;

int a[1005][1005], c[1000005], d[1000005];

int main() {
	//freopen("seat.in", "r", stdin);
	//freopen("seat.out", "w", stdout);

	int n, m, a1, w, z;
	cin >> n >> m;
	for (int i = 1; i <= n * m; i++) {
		cin >> c[i];
	}
	a1 = c[1];
	z = n * m;
	sort(c, c + z + 1);
	int q = 1;
	for (int i = z; i >= 0; i--) {
		d[q] = c[i];
		q++;
	}
	for (int i = 1; i <= n * m; i++) {
		if (a1 == d[i]) {
			w = i;
			break;
		}
	}
	if (w <= n) {
		cout << 1 << " " << w;
	} else {
		if (w % n == 0) {
			if (w / n / 2 == 0) {
				cout << w / n << " " << 1;
			} else {
				cout << w / n << " " << n;
			}
		} else {
			if (w / 2 % 2 == 0) {
				cout << w / n + 1 << " " << n - (w % n - 1);
			} else {
				cout << w / n + 1 << " " << w % n;
			}
		}
	}


	//fclose(stdin);
	//fclose(stdout);
	return 0;
}