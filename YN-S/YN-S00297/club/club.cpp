#include <bits/stdc++.h>
using namespace std;
const int N = 2 * 1e5 + 10;
int t, n, ans[N], p1, p2, p3;
queue <int> g1, g2, g3;

struct node {
	int id;
	int sat1, sat2, sat3;
} a[N];

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin >> t;

	while (t --) {
		cin >> n;

		for (int i = 1; i <= n; i ++) {

			cin >> a[i].sat1 >> a[i].sat2 >> a[i].sat3;
			a[i].id = i;
		}

		for (int i = 1; i <= n; i ++) {

			ans += max(max(a[i].sat1, a[i].sat2), a[i].sat3);
		}
	}

	cout << ans;
	return 0;
}