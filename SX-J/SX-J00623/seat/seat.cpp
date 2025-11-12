#include <bits/stdc++.h>
using namespace std;
int n, m, a[1005], fraction, arr[15][15], tot, brr[15][15];

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n * m; i++)
		cin >> a[i];
	fraction = a[1];
	sort(a + 1, a + n *m + 1, greater<int>());
	for (int i = 1; i <= m; i ++) {
		for (int j = 1; j <= n; j++) {
			arr[i][j] = a[++tot];
		}
	}

	for (int i = 1; i <= n; i++) {
		if (i % 2 != 0) {
			sort(arr[i] + 1, arr[i] + max(n, m) + 1);
		} else {
			sort(arr[i] + 1, arr[i] + max(n, m) + 1, greater<int>());
		}
	}
	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= n; j++) {
			if (arr[i][j] == fraction) {
				cout << i << " " << n - j + 1;
			}
		}

	}
	return 0;
}
