#include <bits/stdc++.h>
using namespace std;
int n, a[500005], ans;

int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for (int l = 1; l < n - 1; l++) {
		for (int r = l + 2; r <= n; r++) {
			int maxx = INT_MIN, s = 0;
			for (int i = l; i <= r; i++) {
				if (a[i] > maxx) {
					maxx = a[i];
				}
				s += a[i];
			}
			if (s > maxx * 2) {
				ans++;
				for (int i = l; i <= r; i++) {
					cout << a[i] << " ";
				}
				cout << endl;
			}
		}
	}
	cout << ans;
	return 0;
}
