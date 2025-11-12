#include <bits/stdc++.h>
using namespace std;
int t, n, a[100005][4];
int m1, m2, m3;
int az[100005];

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin >> t;
	while (t) {
		t--;
		int ans = 0;
		cin >> n;
		m1 = m2 = m3 = n / 2;
		for (int i = 1; i <= n; i++) {
			cin >> a[i][1] >> a[i][2] >> a[i][3];
			ans += max(a[i][1], max(a[i][2], a[i][3]));
		}
		cout << ans;
	}
	return 0;
}