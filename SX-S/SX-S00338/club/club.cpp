#include <bits/stdc++.h>
using namespace std;
int n;
int a[100005][4];
int vis[100005][4], ans[4];
int maxi = 0;
int ans1 = 0, ans2 = 0;

void dfs(int i, int sum) {
	if (i == n + 1) {
		maxi = max(maxi, sum);
		return;
	}
	for (int j = 1; j <= 3; j++) {
		if (!vis[i][j] && ans[j] < n / 2) {
			vis[i][j] = 1;
			ans[j]++;
			dfs(i + 1, sum + a[i][j]);
			ans[j]--;
			vis[i][j] = 0;
		}
	}


}



int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int T;
	cin >> T;
	while (T--) {
		cin >> n;
		maxi = 0;
		ans1 = 0, ans2 = 0;
		for (int i = 1; i <= n; i++) {
			cin >> a[i][1] >> a[i][2] >> a[i][3];
			for (int j = 1; j <= 3; j++)
				vis[i][j] = 0;
			ans1 += (a[i][1] == 0 && a[i][2] == 0);

		}

		for (int i = 1; i <= 3; i++)
			ans[i] = 0;

		if (ans1 == n) {
			int a1[100005];
			for (int i = 1; i <= n; i++)
				a1[i] = a[i][1];
			sort(a1 + 1, a1 + 1 + n);
			int sum = 0;
			for (int i = n / 2; i <= n; i++) {
				sum += a1[i];
			}
			cout << sum;
			continue;
		}
		dfs(1, 0);
		cout << maxi << endl;
	}

	return 0;
}