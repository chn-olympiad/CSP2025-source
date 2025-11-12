#include <bits/stdc++.h>
using namespace std;
int tx[10005], zw[105][105];

int cmp(int a, int b) {
	return a > b;
}

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	long long n, m, l;
	cin >> n >> m;
	for (int i = 1; i <= n * m; i++) {
		cin >> tx[i];
	}
	l = tx[1];
	sort(tx + 1, tx + n *m + 1, cmp);
	int i = 1, j = 1, z = 1;
	for (i = 1; i <= m; i++) {
		int flag = 0;
		if (j == 1 || j == 0) {
			for (j = 1; j <= n; j++) {
				if (tx[z] == l) {
					cout << i << " " << j;
					return 0;
				}
				z++;
			}
			flag = 1;
		}
		if (j == n + 1 && flag == 0) {
			for (j = n; j >= 1; j--) {
				if (tx[z] == l) {
					cout << i << " " << j;
					return 0;
				}
				z++;
			}
		}
	}
	return 0;
}
