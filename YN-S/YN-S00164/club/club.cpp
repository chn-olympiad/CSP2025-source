#include <bits/stdc++.h>
using namespace std;
int a[1101][1101];

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	int t;
	cin >> t;
	while (t--) {
		int n, ans = 0;
		cin >> n;
		int maxx = n / 2;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= 3; j++) {
				cin >> a[i][j];
			}
		}
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= 3; j++) {
				ans += a[i][j];
			}
		}
		cout << ans << '\n';
	}
	return 0;
}