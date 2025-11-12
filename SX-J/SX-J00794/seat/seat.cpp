#include <bits/stdc++.h>
using namespace std;
int seat[11][11], chengji[11];

int cmp(int A, int B) {
	if (A > B)
		return A > B;
	return A < B;
}

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	int n, m, cj, sum = 0;
	cin >> n >> m;
	for (int j = m * n; j >= 1; j--) {
		cin >> chengji[j];
	}
	cj = chengji[n * m];
	sort(chengji + 1, chengji + n + 1, cmp);
	for (int i = 1; i <= n; i++) {
		sum++;
		if (i % 2 == 0) {
			i++;
			for (int j = 1; j <= m; j++) {
				seat[j][i] = chengji[sum];
			}
		} else if (i % 2 == 1) {
			for (int j = m; j >= 1; j--) {
				seat[j][i] = chengji[sum];
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
//			if (seat[i][j] == cj) {
//				cout << i << ' ' << j;
//				return 0;
//			}
			cout << seat[i][j] << ' ';
		}
		cout << endl;
	}
	return 0;
}