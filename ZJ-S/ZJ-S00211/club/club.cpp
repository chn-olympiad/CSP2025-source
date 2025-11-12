#include<bits/stdc++.h>
using namespace std;
int n;
struct nn{
	int d, id;
	const bool operator < (const nn x) const {
		return d > x.d;
	}
};
priority_queue<nn> a, b, c;
int d[100010][5];
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int t;
	cin >> t;
	while (t--) {
		cin >> n;
		for (int i = 1; i <= n; i++) {
			cin >> d[i][0] >> d[i][1] >> d[i][2];
			if (d[i][0] >= d[i][1] && d[i][0] >= d[i][2]) {
				int mx = max(d[i][1], d[i][2]);
				a.push({d[i][0] - mx, i});
				if (a.size() > n / 2) {
					int j = a.top().id;
					a.pop();
					if (d[j][1] > d[j][2]) {
						b.push({d[j][1] - d[j][2], j});
					} else {
						c.push({d[j][2] - d[j][1], j});
					}
				}
			} else if (d[i][1] >= d[i][2] && d[i][1] >= d[i][0]) {
				int mx = max(d[i][0], d[i][2]);
				b.push({d[i][1] - mx, i});
				if (b.size() > n / 2) {
					int j = b.top().id;
					b.pop();
					if (d[j][0] > d[j][2]) {
						a.push({d[j][0] - d[j][2], j});
					} else {
						c.push({d[j][2] - d[j][0], j});
					}
				}
			} else if (d[i][2] >= d[i][1] && d[i][2] >= d[i][0]) {
				int mx = max(d[i][1], d[i][0]);
				c.push({d[i][2] - mx, i});
				if (c.size() > n / 2) {
					int j = c.top().id;
					c.pop();
					if (d[j][1] > d[j][0]) {
						b.push({d[j][1] - d[j][0], j});
					} else {
						a.push({d[j][0] - d[j][1], j});
					}
				}
			}
		}
		int ans = 0;
		while (!a.empty()) ans += d[a.top().id][0], a.pop();
		while (!b.empty()) ans += d[b.top().id][1], b.pop();
		while (!c.empty()) ans += d[c.top().id][2], c.pop();
		cout << ans << endl;;
	}
	return 0;
}
