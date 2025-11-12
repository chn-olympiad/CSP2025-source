#include <bits/stdc++.h>
using namespace std;
#define maxn 100005
int t, n, a[maxn][4], x[maxn], ma;
int vis[maxn];

void dfs(int k) {
	if (k == n + 1 ) {
		int ans = 0;
		for (int i = 1; i <= n; i++) {
			ans += x[i];
			//cout << x[i] << ' ';
		}
		//cout << endl;
		if (ans > ma)
			ma = ans;
		return;
	}
	for (int j = 1; j <= 3; j++) {
		if (vis[j] >= n / 2)
			continue;
		x[k] = a[k][j];
		vis[j]++;
		dfs(k + 1);
		vis[j]--;
	}



}

int main() {
	freopen("club.in", "r", stdin);
	freopen("club,out", "w", stdout);
	cin >> t;
	//t = 1;
	while (t--) {
		cin >> n;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= 3; j++)
				cin >> a[i][j];
		}
		dfs(1);
		cout << ma << endl;
		ma = 0;
		memset(vis, 0, sizeof(vis));
	}
	return 0;
}
