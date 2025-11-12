#include <bits/stdc++.h>
#define ll long long
using namespace std;
int n, m, p, cnt = 1;
int score[15][15];
int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> score[i][j];
			if (score[i][j] > score[1][1]) {
				cnt++;
			}
		}
	}
	int r = ceil(1.0 * cnt / n), c;
	if (r % 2) {
		c = cnt % n;
		if (c == 0) c = n;
	} else {
		c = n + 1 - cnt % n;
		if (c == n + 1) c = 1;
	}
	cout << r << " " << c;
	return 0;
}
