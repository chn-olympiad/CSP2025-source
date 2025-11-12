#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll t, n, a[100005][5], m;
priority_queue<int> c[4];

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin >> t;
	for (int ci = 1; ci <= t; ci++) {
		cin >> n;
		m = 0;
		for (int i = 1; i <= n; i++) {
			cin >> a[i][1] >> a[i][2] >> a[i][3];
			m += max(a[i][2], max(a[i][1], a[i][3]));
			if (a[i][1] >= a[i][2] && a[i][1] >= a[i][3]) {
				if (a[i][2] >= a[i][3]) {
					c[1].push(a[i][2] - a[i][1]);
				} else {
					c[1].push(a[i][3] - a[i][1]);
				}

			} else {
				if (a[i][2] >= a[i][3]) {
					if (a[i][1] >= a[i][3]) {
						c[2].push(a[i][1] - a[i][2]);
					} else {
						c[2].push(a[i][3] - a[i][2]);
					}

				} else {
					if (a[i][1] >= a[i][2]) {
						c[3].push(a[i][1] - a[i][3]);
					} else {
						c[3].push(a[i][2] - a[i][3]);
					}

				}
			}
		}

		for (int i = 1; i <= 3; i++) {
			if (c[i].size() > (n / 2)) {
				while (c[i].size() > (n / 2)) {
					m += c[i].top();

					c[i].pop();
				}
			}

		}
		cout << m << endl;
		while (!c[1].empty()) {
			c[1].pop();
		}
		while (!c[2].empty()) {
			c[2].pop();
		}
		while (!c[3].empty()) {
			c[3].pop();
		}
	}
}