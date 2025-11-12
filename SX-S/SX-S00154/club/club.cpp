#include <bits/stdc++.h>
using namespace std;
int T, n;

struct cb {
	int a;
	int b;
	int c;
} R[100010];

bool vis[100010];

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> T;
	priority_queue<pair<int, int> > q1, q2, q3;
	while (T--) {
		cin >> n;
		memset(vis, 0, sizeof(vis));
		int AS = 0, BS = 0, CS = 0, ans = 0;
		for (int i = 1; i <= n; i++) {
			int u, v, w;
			cin >> u >> v >> w;
			R[i].a = u;
			R[i].b = u;
			R[i].c = w;
			q1.push({u, i});
			q2.push({v, i});
			q3.push({w, i});
		}
		while (1) {
//			cout << q1.top().first << " " << q2.top().first << " " << q3.top().first << endl;
//			cout << q1.top().second << " " << q2.top().second << " " << q3.top().second << endl;
			bool f = 0;
			for (int i = 1; i <= n; i++) {
//				cout << vis[i] << " ";
				if (!vis[i]) {
					f = 1;
				}
			}
			if (!f) {
				break;
			}
//			cout << endl;
			if (q1.empty()) {
				if (q1.top().first >= q2.top().first && q1.top().first >= q3.top().first) {
					if (vis[q1.top().second] || AS >= n / 2) {
						q1.pop();
						continue;
					}
					ans += q1.top().first;
					vis[q1.top().second] = 1;
					AS++;
					q1.pop();
				}
				if (q2.top().first >= q3.top().first) {
					if (vis[q2.top().second] || BS >= n / 2) {
						q2.pop();
						continue;
					}
					ans += q2.top().first;
					vis[q2.top().second] = 1;
					BS++;
					q2.pop();
				} else if (q3.top().first >= q2.top().second) {
					if (vis[q3.top().second] || CS >= n / 2) {
						q3.pop();
						continue;
					}
					ans += q3.top().first;
					vis[q3.top().second] = 1;
					CS++;
					q3.pop();
				}
			} else if (q2.empty()) {
				if ( q1.top().first >= q3.top().first) {
					if (vis[q1.top().second] || AS >= n / 2) {
						q1.pop();
						continue;
					}
					ans += q1.top().first;
					vis[q1.top().second] = 1;
					AS++;
					q1.pop();
				} else if (q3.top().first >= q1.top().first) {
					if (vis[q3.top().second] || CS >= n / 2) {
						q3.pop();
						continue;
					}
					ans += q3.top().first;
					vis[q3.top().second] = 1;
					CS++;
					q3.pop();
				}
			} else if (q3.empty()) {
				if (q1.top().first >= q2.top().first ) {
					if (vis[q1.top().second] || AS >= n / 2) {
						q1.pop();
						continue;
					}
					ans += q1.top().first;
					vis[q1.top().second] = 1;
					AS++;
					q1.pop();
				} else if (q2.top().first >= q1.top().first ) {
					if (vis[q2.top().second] || BS >= n / 2) {
						q2.pop();
						continue;
					}
					ans += q2.top().first;
					vis[q2.top().second] = 1;
					BS++;
					q2.pop();
				}
			}
			if (q1.top().first >= q2.top().first && q1.top().first >= q3.top().first) {
				if (vis[q1.top().second] || AS >= n / 2) {
					q1.pop();
					continue;
				}
				ans += q1.top().first;
				vis[q1.top().second] = 1;
				AS++;
				q1.pop();
			} else if (q2.top().first >= q1.top().first && q2.top().first >= q3.top().first) {
				if (vis[q2.top().second] || BS >= n / 2) {
					q2.pop();
					continue;
				}
				ans += q2.top().first;
				vis[q2.top().second] = 1;
				BS++;
				q2.pop();
			} else if (q3.top().first >= q2.top().first && q3.top().first >= q1.top().first) {
				if (vis[q3.top().second] || CS >= n / 2) {
					q3.pop();
					continue;
				}
				ans += q3.top().first;
				vis[q3.top().second] = 1;
				CS++;
				q3.pop();
			}
		}
		cout << ans << endl;
	}
	return 0;
}
/*
1
4
4 2 1
3 2 4
5 3 4
3 5 1
*/
