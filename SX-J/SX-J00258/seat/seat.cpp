#include <bits/stdc++.h>
#include <iostream>
using namespace std;
int a[15][15];
int h[105];

int main() {
	freopen("seat.in", "r", stdin)
	freopen("seat.out", "w", stdout)
	int n, m;
	cin >> n;
	cin >> m;
	for (int i = 1; i <= n * m; i++) {
		cin >> h[i];
	}
	int w = h[1];
	int f = w;
	for (int b = 1; b <= n * m; b++) {
		for (int j = 1; j < n * m; j++) {
			int u;
			u = h[j];
			if (u < h[j + 1]) {
				h[j] = h[j + 1];
				h[j + 1] = u;
			}
		}
	}
	int l = 1;
	for (int p = 1; p <= m ; p++) {
		for (int d = 1; d <= n ; d++) {
			a[p][d] = h[l];
			l++;
			cout << a[p][d];
		}
	}
	for (int e = 1; e <= m ; e++) {
		for (int b = 1; b <= n ; b++) {
			if (a[e][b] == f) {
				cout << e << " " << b;
				return 0;
			}
		}
		cout << endl;
	}
	return 0;
}