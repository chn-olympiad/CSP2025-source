#include <bits/stdc++.h>
using namespace std;
const int N = 1e2+10;
int n, m, c, temp, grades[N], hl[N][N], a, b;

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	c = n * m;
	for (int i = 1; i <= c; i++) {
		cin >> grades[i];
	}
	temp = grades[1];
	sort(grades, grades + c, greater<int>());
	while (c--) {
		for (int i = 1; i <= m; i++) {
			for (int j = 1; j <= n; j++) {
				hl[i][j] = grades[c];
			}
		}
		for (int i = 1; i <= m; i++) {
			if (i % 2 != 0) {
				for (int j = 1; j <= n; j++) {
					if (hl[i][j] = temp) {
						a = i;
						b = j;
						break;
					}
				}
			} else {
				for (int j = n; j >= 1; j--) {
					if (hl[i][j] = temp) {
						a = i;
						b = j;
						break;
					}
				}
			}
		}
	}
	cout << b << ' ' << a;
	return 0;
}