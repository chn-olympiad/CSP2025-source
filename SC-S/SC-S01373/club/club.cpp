#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 100005;
int a[N], b[N], c[N];
int ans = LONG_LONG_MIN;
int ida, idb, idc;
void dfs(int x, int y, int z, int sum, int n, int res) {
	if (res == n + 1) {
		ans = max(ans, sum);
		return ;
	}
	if (x == n / 2 && y == n / 2 && z < n / 2) {
		dfs(x, y, z + 1, sum + c[res], n, res + 1);
	} else if (y == n / 2 && z == n / 2 && x < n / 2) {
		dfs(x + 1, y, z, sum + a[res], n, res + 1);
	} else if (x == n / 2 && z == n / 2 && y < n / 2) {
		dfs(x, y + 1, z, sum + b[res], n, res + 1);
	} else if (x == n / 2 && y < n / 2 && z < n / 2) {
		dfs(x, y + 1, z, sum + b[res], n, res + 1), dfs(x, y, z + 1, sum + c[res], n, res + 1);
	} else if (y == n / 2 && x < n / 2 && z < n / 2) {
		dfs(x + 1, y, z, sum + a[res], n, res + 1), dfs(x, y, z + 1, sum + c[res], n, res + 1);
	} else if (z == n / 2 && y < n / 2 && x < n / 2) {
		dfs(x + 1, y, z, sum + a[res], n, res + 1), dfs(x, y + 1, z, sum + b[res], n, res + 1);
	} else if (x < n / 2 && y < n / 2 && z < n / 2) {
		dfs(x + 1, y, z, sum + a[res], n, res + 1), dfs(x, y + 1, z, sum + b[res], n, res + 1), dfs(x, y, z + 1, sum + c[res], n, res + 1);
	} else {
		return ;
	}
}
bool cmp(int x, int y) {
	return x > y;
}
signed main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		int cnt0 = 0, cnt1 = 0;
		for (int i = 1; i <= n; i++) {
			cin >> a[i] >> b[i] >> c[i];
			if (b[i] == 0 && c[i] == 0) {
				cnt0++;
			}
			if (c[i] == 0 && b[i] != 0) {
				cnt1++;
			}
		}
		if (cnt0 == n) {
			stable_sort(a + 1, a + n + 1, cmp);
			int sum = 0;
			for (int i = 1; i <= n / 2; i++) {
				sum += a[i];
			}
			cout << sum << endl;
			return 0;
		}
		ans = LONG_LONG_MIN;
		dfs(0, 0, 0, 0, n, 1);
		cout << ans << endl;
	}
	
	return 0;
}