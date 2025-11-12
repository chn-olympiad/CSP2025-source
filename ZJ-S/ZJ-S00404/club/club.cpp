#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 100;
int n, x[N], y[N], z[N];
long long ans;
priority_queue<int > q[5];
void solve() {
	ans = 0;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> x[i] >> y[i] >> z[i];
		if (x[i] >= y[i] && x[i] >= z[i]) {
			int sizee = q[1].size();
			if (sizee == n / 2) {
				int c = -q[1].top();
				if (x[i] - max(y[i], z[i]) > c) {
					ans -= c;
					q[1].pop();
					q[1].push(-(x[i] - max(y[i], z[i])));
					ans += x[i];
				}
				else {
					ans += max(y[i], z[i]);
				}
			}
			else {
				q[1].push(-(x[i] - max(y[i], z[i])));
				ans += x[i];
			}
		}
		else if (y[i] >= x[i] && y[i] >= z[i]) {
			int sizee = q[2].size();
			if (sizee == n / 2) {
				int c = -q[2].top();
				if (y[i] - max(x[i], z[i]) > c) {
					ans -= c;
					q[2].pop();
					q[2].push(-(y[i] - max(x[i], z[i])));
					ans += y[i];
				}
				else {
					ans += max(x[i], z[i]);
				}
			}
			else {
				q[2].push(-(y[i] - max(x[i], z[i])));
				ans += y[i];
			}			
		}
		else {
			int sizee = q[3].size();
			if (sizee == n / 2) {
				int c = -q[3].top();
				if (z[i] - max(x[i], y[i]) > c) {
					ans -= c;
					q[3].pop();
					q[3].push(-(z[i] - max(x[i], y[i])));
					ans += z[i];
				}
				else {
					ans += max(x[i], y[i]);
				}
			}
			else {
				q[3].push(-(z[i] - max(x[i], y[i])));
				ans += z[i];
			}			
		}
	}
	while (!q[1].empty())q[1].pop();
	while (!q[2].empty())q[2].pop();
	while (!q[3].empty())q[3].pop();
	cout << ans << "\n";
	return ;
}
signed main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	int T;
	cin >> T;
	while (T --) solve();
	return 0;
}