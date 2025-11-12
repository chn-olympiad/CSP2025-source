#include <bits/stdc++.h>
#define LL long long
using namespace std;
const int N = 12212;
LL t, n, ans, nn;
LL c[N], a[N][4];



void dfs(int k, LL sum) {
	if (k > n) {
		ans = max(ans, sum);
		return;
	}
	for (int i = 1; i <= 3; i++) {
		if (c[i] < nn) {
			c[i]++;
			dfs(k + 1, sum + a[k][i]);
			c[i]--;
		}
	}
}

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin >> t;
	while (t--) {
		ans = -1;
		cin >> n;
		nn = n / 2;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= 3; j++) {
				cin >> a[i][j];
			}
		}
		dfs(1, 0);
		cout << ans << "\n";
	}
	return 0;
}