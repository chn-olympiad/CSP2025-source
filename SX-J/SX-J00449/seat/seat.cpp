#include <bits/stdc++.h>
using namespace std;
int a[2025], n, m, scoreR;

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			scanf("%d", &a[(i - 1)*m + j]);
			if (i == 1 && j == 1)
				scoreR = a[i];
		}
	}
	sort(a + 1, a + n *m + 1, greater<int>());
	for (int i = 1; i <= n; i++) {
		if (i % 2 == 1) { //奇数行
			for (int j = 1; j <= m; j++) {
				//cout << a[(i - 1)*m + j] << ' ';
				if (a[(i - 1) * m + j] == scoreR) {
					printf("%d %d\n", i, j);
					return 0;
				}
			}
		} else {
			//偶数行
			for (int j = 1; j <= m; j++) {
				//cout << a[(i - 1)*m + (m - j + 1)] << ' ';
				if (a[(i - 1) * m + (m - j + 1)] == scoreR) {
					printf("%d %d\n", i, j);
					return 0;
				}
			}
		}
		//cout << endl;
	}
	return 0;
}