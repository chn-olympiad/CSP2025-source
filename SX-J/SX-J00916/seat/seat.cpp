#include <bits/stdc++.h>
using namespace std;
int a[520];
int sum = 0;
int cj[15][15];
int ans = 0;

int mp(int c, int d) {
	if (c < d) {
		return d;
	}
}

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n * m; i++) {
		cin >> a[i];
		sum++;
	}
	ans = a[1];
	sort(a + 1, a + sum + 1, mp);
	for (int i = 1; i <= sum; i++) {
		for (int j = 1; j <= sum; j++) {
			if (a[j] < a[j + 1]) {
				swap(a[j], a[j + 1]);
			}
		}
	}//ÅÅÐò
	int c = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			c++;
			cj[i][j] = a[c];
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (i % 2 == 0 && j != m && i != 1 && j + 2 <= m) {
				swap(cj[i][j], cj[i][j + 2]);
			}
		}
	}
//	for (int i = 1; i <= n; i++) {
//		for (int j = m; j >= 1; j--) {
//			if (i == j && j == i) {
//				swap(cj[i][j], cj[j][i]);
//			}
//		}
//	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cout << cj[i][j] << " ";
		}
		cout << endl;
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (cj[i][j] == ans) {
				if (n > 2 && m > 2) {
					if (i % 2 != 0 && j % 2 != 0) {
						cout << i << " " << j;
					} else {
						cout << i - 1 << " " << j;
					}
				} else {
					cout << i << " " << j + 1;
				}
				return 0;
			}
		}
	}
	return 0;
}
// 3 3
//100 99 98 97 96 95 94 93 92