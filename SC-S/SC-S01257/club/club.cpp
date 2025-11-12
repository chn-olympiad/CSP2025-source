#include<bits/stdc++.h>
#define int long long
using namespace std;
int t, n;
int a[100005][5];
int maxnum;
int maxx;
void dfs(int x, int p, int q, int k, int sum) {
	//cout << "x:" << x << " p:" << p << " q:" << q << " k:" << k << " sum:" << sum << "\n";
	if (x == n + 1) {
		maxx = max(maxx, sum);
		return;
	}
	if (p < maxnum) {
		dfs(x + 1, p + 1, q, k, sum + a[x][1]);
	}
	if (q < maxnum) {
		dfs(x + 1, p, q + 1, k, sum + a[x][2]);
	}
	if (k < maxnum) {
		dfs(x + 1, p, q, k + 1, sum + a[x][3]);
	}
}
signed main() {
	freopen("club.in", "r", stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> t;
	while (t--) {
		maxx = 0;
		cin >> n;
		maxnum = n / 2;
		for (int i = 1; i <= n; i++) {
			cin >> a[i][1] >> a[i][2] >> a[i][3];
		}
		dfs(1, 0, 0, 0, 0);
		cout << maxx << "\n";
	}
	return 0;
}