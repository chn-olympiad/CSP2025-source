#include<bits/stdc++.h>
using namespace std;
int n, t, a[100050][10], ra[100050];
long long ans = 0;
void dfs(int x, int cnt1, int cnt2, int cnt3, long long res) {
	if (x > n) {
		ans = max(ans, res);
		return;
	}
	if (cnt1 < n / 2)dfs(x + 1, cnt1 + 1, cnt2, cnt3, res + a[x][1]);
	if (cnt2 < n / 2)dfs(x + 1, cnt1, cnt2 + 1, cnt3, res + a[x][2]);
	if (cnt3 < n / 2)dfs(x + 1, cnt1, cnt2, cnt3 + 1, res + a[x][3]);
}

bool reca() {
	int cnt = 0;
	for (int i = 1; i <= n; i++) {
		if (a[i][2] != 0 && a[i][3] != 0) cnt++;
	}
	if (cnt == 0)return 1;
	else return 0;
}

int main() {

	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> t;
	for (int k = 1; k <= t; k++) {
		ans = 0;
		cin >> n;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= 3; j++) {
				cin >> a[i][j];
			}
		}
		if (n <= 10) {
			dfs(1, 0, 0, 0, 0);
		} else if (reca() == 1) {
			for (int i = 1; i <= n; i++) {
				ra[i] = a[i][3];
			}
			sort(ra + 1, ra + n + 1);
			for (int i = n / 2; i >= 1; i++) {
				ans += ra[i];
			}
		} else {
			for (int i = 1; i <= n; i++) {
				ans += max(a[i][1], max(a[i][2], a[i][3]));
			}
		}
		cout << ans << endl;
	}
	return 0;
}
