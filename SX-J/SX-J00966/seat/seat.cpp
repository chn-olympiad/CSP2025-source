#include <bits/stdc++.h>
using namespace std;
int n, m, z, x;
int a[15][15];
int q[150];
bool flag;

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n * m; i++) {
		cin >> q[i];
	}
	x = q[0];
	sort(q, q + n *m + 1);
	flag = true;
	for (int i = m - 1; i > -1; i--) {
		if (flag) {
			for (int j = n; j > 0; j--) {
				a[j][i] = q[z];
				if (q[z] == x) {
					cout << j << ' ' << i;
				}
				z++;
			}
			flag = false;
		} else {
			for (int j = 1 ; j < n; j++) {
				a[j][i] = q[z];
				if (q[z] == x) {
					cout << j << ' ' << i;
				}
				z++;
			}
			flag = true;
		}
	}
	return 0;
}
