//2025.11.1  zyb  T1 club
#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int n, a[N][5], c[5], ans;
int res[N], sum;

void dfs(int pos) {
	if (pos == n + 1) {
		ans = max(ans, sum);
		return ;
	}
	for (int i = 1; i <= 3; i++) {
		if (c[i] + 1 <= n / 2) {
			c[i]++;
			res[pos] = i;
			sum += a[pos][i];
			dfs(pos + 1);
			sum -= a[pos][i];
			c[i]--;
		}
	}
}

int T;
int b[N];
bool vis[N];
priority_queue<pair<int, int> >q1, q2;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin >> T;
	while (T--) {
		cin >> n;
		bool flag1 = true, flag2 = true;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= 3; j++) {
				cin >> a[i][j];
			}
			if (a[i][2]) {
				flag1 = false;
			}
			if (a[i][3]) {
				flag1 = false;
				flag2 = false;
			}
		}
		ans = 0;
		if (n < 18) {
			dfs(1);
			cout << ans << '\n';
		} else if (flag1) {
			for (int i = 1; i <= n; i++) {
				b[i] = a[i][1];
			}
			sort(b + 1, b + n + 1);
			for (int i = 1; i <= (n >> 1); i++) {
				ans += b[i];
			}
			cout << ans << '\n';
		} else if (flag2) {
			while (!q1.empty())
				q1.pop();
			while (!q2.empty())
				q2.pop();
			for (int i = 1; i <= n; i++) {
				q1.push({a[i][1], i});
				q2.push({a[i][2], i});
			}
			ans = 0;
			for (int i = 1; i <= n; i++) {
				if (i & 1) {
					while (!q1.empty() && vis[q1.top().second])
						q1.pop();
					if (!q1.empty()) {
						vis[q1.top().second] = true;
						ans += q1.top().first;
					}
				} else {
					while (!q2.empty() && vis[q2.top().second])
						q2.pop();
					if (!q2.empty()) {
						vis[q2.top().second] = true;
						ans += q2.top().first;
					}
				}
			}
			cout << ans << '\n';
		}
	}
	return 0;
}