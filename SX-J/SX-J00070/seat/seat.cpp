#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	int score[n * m + 5] = {};
	for (int i = 1; i <= n * m; i++) {
		cin >> score[i];
	}
	int R = score[1];
	sort(score + 1, score + n *m + 1);
	int seat[m][n] = {};
	int si = 1, sj = 1, r = m * n;
	for (int i = 1; i <= m; i++) {
		if (si % 2 == 0) {
			sj = n;
		} else {
			sj = 1;
		}
		for (int j = 1; j <= n; j++) {
			seat[si][sj] = score[r];
			if (score[r] == R) {
				cout << si << " " << sj;
				return 0;
			}
			if (si % 2 == 0) {
				sj --;
			} else {
				sj ++;
			}
			r--;
		}
		si++;
	}

	return 0;
}
