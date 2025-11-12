#include <bits/stdc++.h>
using namespace std;
int n, m, a[105], cnt;
int main () {
	freopen ("seat.in", "r", stdin);
	freopen ("seat.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n * m; i++) {
		cin >> a[i];
		if (a[i] >= a[1]) {
			cnt++;
		}
	}
	int ans = 0;
	for (int i = 0; i < m;) {
		i++;
		int j = 0;
		while (j <= n) {
			j++;
			if (j == n + 1) {
				ans--;
			}
			ans++;
			if (cnt == ans) {
				cout << i << ' ' << j;
				return 0;
			}
		}
		i++;
		while (j > 0) {
			j--;
			ans++;
			if (j == 0) {
				ans--;
			}
			if (cnt == ans) {
				cout << i << ' ' << j;
				return 0;
			}
		}
		
	}
	return 0;
}