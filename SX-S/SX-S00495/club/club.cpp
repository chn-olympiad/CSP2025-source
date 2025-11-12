#include <bits/stdc++.h>
using namespace std;
int n, t, arr[100005][5], ans[5], sum = 0, mysum = 0;
bool vis[100005];

void dfs(int step) {
	for (int i = 1; i <= 3; i++) {
		if (ans[i] < n / 2 && vis[step] == 0) {
			ans[i]++;
			vis[step] = 1;
			sum += arr[step][i];
			mysum = max(mysum, sum);
			dfs(step + 1);
			ans[i]--;
			vis[step] = 0;
			sum -= arr[step][i];
		}
	}
}

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin >> t;
	while (t--) {
		mysum = 0, sum = 0;
		memset(ans, 0, sizeof(ans));
		memset(arr, 0, sizeof(arr));
		memset(vis, 0, sizeof(vis));
		cin >> n;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= 3; j++) {
				cin >> arr[i][j];
			}
		}
		dfs(1);
		cout << mysum << endl;
	}
	return 0;
}