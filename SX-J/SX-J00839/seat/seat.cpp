#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	int a[n + 5][m + 5];
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> a[i][j];
		}
	}
	int sum = a[1][1], a1[n + m + 5], a2[n + m + 5], s1 = 0, s2 = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			a1[++s1] = a[i][j];
		}
	}
	sort(a1 + 1, a1 + s1 + 1);
	for (int i = s1; i >= 1; i--) {
		a2[++s2] = a1[i];
	}
	int s3 = 0;
	int t[n + 5][m + 5];
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			t[i][j] = a2[++s3];
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (t[i][j] == sum) {
				cout << i << " " << j;
				return 0;
			}
		}
	}
	return 0;
}
