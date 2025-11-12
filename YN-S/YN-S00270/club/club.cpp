//by.pcx 2025.11.1 YN-S00270
#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int a[N][10], tmp[N];

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= 3; j++) {
				cin >> a[i][j];
				tmp[i] = a[i][1];
			}
		}
		sort(tmp + 1, tmp + n + 1);
		int ans = 0;
		for (int i = n; i > n / 2; i--) {
			ans += tmp[i];
		}
		cout << ans << "\n";
	}
	return 0;
}