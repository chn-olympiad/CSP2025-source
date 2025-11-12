#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e5 + 10;
int n, T, clubs[N], emp, ans = -1;
int a[N];

struct person {
	int c[4];
} p[N];

void qinlin() {
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= 3; j++)
			p[i].c[j] = 0;
	}
	return;
}

void dfs(int dep, int sum) {
	if (dep == n + 1) {
		ans = max(ans, sum);
		return ;
	}

	for (int i = 1; i <= 3; i++) {
		if (clubs[i] < emp) {
			clubs[i]++;
			dfs(dep + 1, sum + p[dep].c[i]);
			clubs[i]--;
		}
	}
}

signed main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> T;
	while (T--) {
		cin >> n;
		emp = n / 2;
		int flag = 0;
		for (int i = 1; i <= n; i++) {
			cin >> p[i].c[1] >> p[i].c[2] >> p[i].c[3];
			a[i] = p[i].c[1];
		}
		if (n <= 30) {
			dfs(1, 0);
		} else {
			sort(a + 1, a + n + 1);
			for (int i = n; i >= n - emp; i--) {
				ans += a[i];
			}
		}
		cout << ans << '\n';
		ans = 0;
		qinlin();
		memset(clubs, 0, sizeof(clubs));
	}
	return 0;
}