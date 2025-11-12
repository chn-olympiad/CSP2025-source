#include <bits/stdc++.h>
using namespace std;

int in[100002][3];
int mid[100002][4];
int a[3] = {0};
int n;
int m;
int t;
int res = 0;


void dfs(int k, int sum) {

	if (k == n) {
		res = max(res, sum);
		return;
	}
	for (int i = 0; i <= 2; i++) {
		if (a[i] + 1 <= m) {
			a[i]++;
			dfs(k + 1, sum + in[k + 1][i]);
			a[i]--;
		}
	}
}

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin >> t;
	while (t--) {
		memset(a, 0, 3);
		res = 0;
		cin >> n;
		m = n >> 1;
		for (int i = 1; i <= n; i++) {
			for (int j = 0; j <= 2; j++) {
				cin >> in[i][j];
			}
		}
		dfs(0, 0);
		cout << res << endl;
	}

	return 0;
}