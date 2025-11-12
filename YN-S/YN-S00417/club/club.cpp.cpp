#include <bits/stdc++.h>
using namespace std;
int t;
int n, a[1000][1000], b[1000], c[3];

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin >> t;
	int ans[t];
	for (int i = 0; i < t; i++) {
		ans[i] = 0;
	}
	for (int q = 0; q < t ; q++) {
		cin >> n;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < 3; j++) {
				cin >> a[i][j];
			}
		}
		for (int i = 0; i < n; i++) {
			if (a[i][0] < a[i][1] && a[i][2] < a[i][1]) {
				b[i] = a[i][1];
				c[1]++;
			}
			if (a[i][0] < a[i][2] && a[i][1] < a[i][2]) {
				b[i] = a[i][2];
				c[2]++;
			}
			if (a[i][0] > a[i][1] && a[i][0] > a[i][2]) {
				b[i] = a[i][0];
				c[0]++;
			}
		}
		for (int j = 0; j < 3; j++) {
			for (int i = 0; i < n; i++) {
				if (c[j] > n / 2) {
					c[j]--;
					if (b[i] > a[i][0] && b[i] != a[i][0] && (a[i][0] >= a[i][1] || a[i][0] >= a[i][2])) {
						b[i] = a[i][0];
						c[0]++;
					}
					if (b[i] > a[i][1] && b[i] != a[i][1] && (a[i][1] >= a[i][2] || a[i][1] >= a[i][0])) {
						b[i] = a[i][1];
						c[1]++;
					}
					if (b[i] > a[i][2] && b[i] != a[i][2] && (a[i][2] >= a[i][1] && a[i][2] >= a[i][0])) {
						b[i] = a[i][2];
						c[2]++;
					}
				}
			}
		}
		for (int i = 0; i < n; i++) {
			ans[q] = b[i] + ans[q];
		}
		for (int i = 0; i < 3; i++) {
			c[i] = 0;
		}
	}
	for (int i = 0; i < t; i++) {
		cout << ans[i] << endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}