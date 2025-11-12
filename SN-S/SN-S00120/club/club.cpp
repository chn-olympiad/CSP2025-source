#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int t;
int a[N], b[N], c[N];
bool cmp1(int x, int y) {
	return x > y;
}
void solve() {
	int n;
	cin >> n;
	int fb = 1, fc = 1;
	for (int i = 1; i <= n; i++) {
		cin >> a[i] >> b[i] >> c[i];
		if (b[i] != 0) fb = 0;
		if (c[i] != 0) fc = 0;
	}
	if (fb == 1 and fc == 1) {
		int ans = 0;
		sort(a + 1, a + n + 1, cmp1);
		for (int i = 1; i <= n; i++) ans += a[i];
		cout << ans << ' ';
	}
	if (n == 2) {
		int ans = 0;
		ans = max(ans, a[1] + b[2]);
		ans = max(ans, a[1] + c[2]);
		ans = max(ans, b[1] + a[2]);
		ans = max(ans, b[1] + c[2]);
		ans = max(ans, c[1] + a[2]);
		ans = max(ans, c[1] + c[2]);
		cout << ans;
	}
}
int main(){
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);

	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}
