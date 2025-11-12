#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int t, a[100][100], n, d[100], myd = 0;
	cin >> t;
	for (int i = 1; i <= 99; i++) {
		d[i] = 0;
	}
	while (t--) {
		cin >> n;
		myd = 0;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= 3; j++) {
				cin >> a[i][j];
			}
		}
		for (int i = 1; i <= n; i++) {
			if (a[i][1] > a[i][2] && a[i][1] > a[i][3] && d[1] < n / 2) {
				d[1]++;
				myd += a[i][1];
			} else if (a[i][2] > a[i][1] && a[i][2] > a[i][3] && d[2] < n / 2) {
				d[2]++;
				myd += a[i][2];
			} else if (a[i][3] > a[i][2] && a[i][3] > a[i][1] && d[3] < n / 2) {
				d[3]++;
				myd += a[i][3];
			}
		}
		cout << myd << endl;
	}

	fclose(stdin);
	fclose(stdout);
	return 0;
}
