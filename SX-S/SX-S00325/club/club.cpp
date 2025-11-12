#include <bits/stdc++.h>
using namespace std;
long long t, n, m, a[100007][5], num, b, ans, s[10000007], k;

void dfs(int x, int y, int p) {

	if (a[0][1] > b || a[0][2] > b || a[0][3] > b) {

		num -= a[x][p];
		a[0][p]--;
		return;
	}
	if (x == n + 1) {
		s[k] = num;
		k++;
		return ;
	}
	for (int j = 1; j <= 3; j++) {
		if (a[0][j] > b - 1) {
			continue;
		}

		num += a[x][j];
		a[0][j]++;
		//cout << num << " ";
		dfs(x + 1, 1, j);
	}
}

int main() {
//	freopen("club.in", "r", stdin);
//	freopen("club.out", "w", stdout);
	cin >> t;
	while (t--) {
		memset(s, 0, sizeof(s));
		ans = -1;

		cin >> n;
		b = n / 2;
		for (int i = 1; i <= n; i++) {
			cin >> a[i][1] >> a[i][2] >> a[i][3];
		}

		k = 1;
		num = a[1][1];
		a[0][1] = 1;
		a[0][2] = 0;
		a[0][3] = 0;
		dfs(2, 1, 1);

		//cout << endl;
		num = a[1][2];
		a[0][1] = 0;
		a[0][2] = 1;
		a[0][3] = 0;
		dfs(2, 1, 1);

		//cout << endl;
		num = a[1][3];
		a[0][1] = 0;
		a[0][2] = 0;
		a[0][3] = 1;
		dfs(2, 1, 1);

		//	cout << endl;

		for (int i = 1; i <= 3; i++) {
			//cout << s[i] << " ";
			ans = max(ans, s[i]);
		}
		cout << ans << endl;
	}
	return 0;
}
