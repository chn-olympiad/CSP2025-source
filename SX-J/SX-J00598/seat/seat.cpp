#include <bits/stdc++.h>
using namespace std;
int n, m, a[105], b[11][11];

bool cmp(int x, int y) {
	return x > y;
}

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n * m; i++) {
//		cin >> a[i];
		scanf("%d", &a[i]);
	}
	int ls = a[1];
	sort(a + 1, a + n *m + 1, cmp);
	for (int j = 1; j <= m; j++) {
		if (j % 2 != 0) {
			int ww = (j - 1) * n + 1;
			for (int i = 1; i <= n; i++) {
				b[i][j] = a[ww++];
			}
		} else {
			int ww = j * n;
			for (int i = 1; i <= n; i++) {
				b[i][j] = a[ww--];
			}
		}
	}
//	for (int i = 1; i <= n; i++) {
//		for (int j = 1; j <= m; j++) {
//			cout << b[i][j] << " ";
//		}
//		cout << endl;
//	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (ls == b[i][j]) {
//				cout << j << " " << i;
				printf("%d %d", j, i);
				return 0;
			}
		}
	}
	return 0;
}
