#include <bits/stdc++.h>
using namespace std;
int t, n, a[100010][5], b, ans;

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin >> t;
	for (int h = 1; h <= t; h++) {
		cin >> n;
		for (int i = 1; i <= n; i++) {
			cin >> a[i][1] >> a[i][2] >> a[i][3];
		}
		while (b != n - 1) {
			b = 0;
			for (int i = 1; i < n; i++) {
				if (a[i][1] < a[i + 1][1])
					swap(a[i][1], a[i + 1][1]);
			}
			for (int i = 1; i < n; i++) {
				if (a[i][1] >= a[i + 1][1])
					b++;
			}
		}
		b = 0;
		while (b != n - 1) {
			b = 0;
			for (int i = 1; i < n; i++) {
				if (a[i][2] < a[i + 1][2])
					swap(a[i][2], a[i + 1][2]);
			}
			for (int i = 1; i < n; i++) {
				if (a[i][1] >= a[i + 1][2])
					b++;
			}
		}
		b = 0;
		while (b != n - 1) {
			b = 0;
			for (int i = 1; i < n; i++) {
				if (a[i][3] < a[i + 1][3])
					swap(a[i][3], a[i + 1][3]);
			}
			for (int i = 1; i < n; i++) {
				if (a[i][1] >= a[i + 1][3])
					b++;
			}
		}
		if (a[1][2] == 0 && a[1][3] == 0 && a[1][1] != 0) {
			for (int i = 1; i <= n / 2; i++)
				ans += a[i][1];
		}
		cout << ans << endl;
	}
	return 0;
}
