#include <bits/stdc++.h>
#define endl "\n"

using namespace std;

int n, m, r, t;
priority_queue<int, vector<int>> pq;

signed main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n >> m >> r, pq.push(r);
	for (int i = 2; i <= n * m; ++i) {
		cin >> t, pq.push(t);
	}

	for (int i = 1; i <= n; ++i) {
		if (i % 2 == 1) {
			for (int j = 1; j <= m; ++j) {
				if (pq.top() == r) {
					cout << i << ' ' << j << endl;
					return 0;
				}
				pq.pop();
			}
		} else {
			for (int j = m; j >= 1; --j) {
				if (pq.top() == r) {
					cout << i << ' ' << j << endl;
					return 0;
				}
				pq.pop();
			}
		}
	}

	return 0;
}
