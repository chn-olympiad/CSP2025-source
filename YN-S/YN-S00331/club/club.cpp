#include <bits/stdc++.h>
using namespace std;
#define int long long
int a[10005], b[10005], c[10005];

signed main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> t;
	for (int i = 1; i <= t; i++) {
		int n, cnt = 0;
		int x = 0, y = 0, z = 0;
		cin >> n;
		int d = n / 2;
		for (int j = 1; j <= n; j++) {
			cin >> a[j] >> b[j] >> c[j];
		}
		sort(b + 1, b + n + 1);
		for (int j = n; j >= n / 2; j--) {
			cnt += b[j];
		}
		cout << cnt << endl;
	}
	return 0;
}