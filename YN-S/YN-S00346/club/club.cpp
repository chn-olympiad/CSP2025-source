#include <bits/stdc++.h>
using namespace std;
int t, n, ans = INT_MIN;

struct cy {
	int y, e, s;
} a[100050];
int vis[100050];

void dfs(int dep, int cnt1, int cnt2, int cnt3, int sum) {
	if (dep > n) {
		ans = max(ans, sum);
		return;
	}
	if (cnt1 < n / 2)
		dfs(dep + 1, cnt1 + 1, cnt2, cnt3, sum + a[dep].y);
	if (cnt2 < n / 2)
		dfs(dep + 1, cnt1, cnt2 + 1, cnt3, sum + a[dep].e);
	if (cnt3 < n / 2)
		dfs(dep + 1, cnt1, cnt2, cnt3 + 1, sum + a[dep].s);
}

bool cmp(cy i, cy j) {
	return i.y > j.y;
}

bool cmp2(cy i, cy j) {
	return i.e > j.e;
}

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> t;
	while (t--) {
		cin >> n;
		ans = INT_MIN;
		int flag = 1, flag2 = 1;
		for (int i = 1; i <= n; i++) {
			cin >> a[i].y >> a[i].e >> a[i].s;
			if (a[i].e != 0 || a[i].s != 0)
				flag = 0;
			if (a[i].s != 0)
				flag2 = 0;
		}
		if (flag == 1) {
			ans = 0;
			sort(a + 1, a + n + 1, cmp);
			for (int i = 1; i <= n / 2; i++) {
				ans += a[i].y;
			}
			cout << ans;
			continue;
		}
		dfs(1, 0, 0, 0, 0);
		cout << ans << "\n";
	}
	return 0;
}