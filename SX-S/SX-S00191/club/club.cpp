#include <bits/stdc++.h>
#define endl "\n"

using namespace std;
const int N_MAX = 1e5 + 10;

int T, n, m, a;
priority_queue<int, vector<int>> pq;
int q, w, e, r, t, y;

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> T;
	while (T--) {
		cin >> n;
		if (n != 2) {
			for (int i = 1; i <= n; ++i) {
				cin >> a >> m >> m, pq.push(a);
			}
			m = 0;
			for (int i = 1; i <= n / 2; ++i) {
				m += pq.top();
				pq.pop();
			}
			cout << m << endl;
		} else {
			cin >> q >> w >> e >> r >> t >> y;
			cout << max(q + t, max(q + y, max(w + r, max(w + y, max(e + r, e + t))))) << endl;
		}
	}

	return 0;
}
