#include <bits/stdc++.h>
using namespace std;
int n, m, a[1005], arr[1005][1005], a1, cnt = 1;

bool cmp(int x, int y) {
	return x > y;
}

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n * m; i++) {
		cin >> a[i];
	}
	a1 = a[1];
	sort(a + 1, a + n *m + 1, cmp);
	for (int j = 1; j <= m; j++) {
		if (j % 2 == 1) {
			for (int i = 1; i <= n; i++) {
				arr[i][j] = a[cnt++];
				if (arr[i][j] == a1) {
					cout << j << " " << i;
					return 0;
				}
			}
		}
		if (j % 2 == 0) {
			for (int i = n; i > 0; i--) {
				arr[i][j] = a[cnt++];
				if (arr[i][j] == a1) {
					cout << j << " " << i;
					return 0;
				}
			}
		}
	}
	return 0;
}
