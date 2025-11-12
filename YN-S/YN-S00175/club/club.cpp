//T1
#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int x[N], y[N], z[N];
int T, n, ans;

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin >> T;
	while (T--) {
		cin >> n;
		for (int i = 1; i <= n; i++) {
			cin >> x[i] >> y[i] >> z[i];
		}
		sort(x + 1, x + n + 1, greater<int>());
		int m = n / 2;
		for (int i = 1; i <= m; i++) {
			ans += x[i];
		}
		cout << ans << endl;
	}
	return 0;
}