#include <bits/stdc++.h>
using namespace std;

const int N = 100010, M = 101;

int n;
int a[N][3];
int f[M][M][M];
priority_queue<int> q;

void solve() {
	int ans = 0;
	if (n > 200) {
		bool fl = 0;
		for (int i = 1; i <= n; i++)
			if (a[i][2]) { fl = 1; break; }
		if (!fl) {
			int x = 0, y = 0, z = 0;
			for (int i = 1; i <= n; i++) {
				if (a[i][0] > a[i][1]) x++, z += a[i][0];
				else y++, z += a[i][1];
			}
			while (q.size()) q.pop();
			if (x > n / 2) {
				for (int i = 1; i <= n; i++)
					if (a[i][0] > a[i][1]) q.push(a[i][1] - a[i][0]);
				while (x > n / 2) z += q.top(), q.pop(), x--;
			} else if (y > n / 2) {
				for (int i = 1; i <= n; i++)
					if (a[i][0] <= a[i][1]) q.push(a[i][0] - a[i][1]);
				while (y > n / 2) z += q.top(), q.pop(), y--;
			}
			cout << z << endl;
			return;
		}
		for (int i = 1; i <= n; i++)
			ans += max(a[i][0], max(a[i][1], a[i][2]));
		cout << ans << endl;
		return;
	}
	f[0][0][0] = 0;
	for (int i = 0; i <= n / 2; i++) {
		for (int j = 0; j <= min(n - j, n / 2); j++) {
			for (int k = 0; k <= min(n - i - j, n / 2); k++) {
				int t = i + j + k;
				int &p = f[i][j][k];
				p = 0;
				if (i) p = max(p, f[i - 1][j][k] + a[t][0]);
				if (j) p = max(p, f[i][j - 1][k] + a[t][1]);
				if (k) p = max(p, f[i][j][k - 1] + a[t][2]);
				if (t == n) ans = max(ans, p);
			}
		}
	}
	cout << ans << endl;
}

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int T;
	cin >> T;
	while (T--) {
		cin >> n;
		for (int i = 1; i <= n; i++)
			scanf("%d%d%d", &a[i][0], &a[i][1], &a[i][2]);
		solve();
	}
	return 0;
}
