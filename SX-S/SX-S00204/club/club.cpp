#include <bits/stdc++.h>
using namespace std;

int t, n, cnt;
int a1[100005], a2[100005], a3[100005];

int main() {

	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);

	cin >> t;
	for (int i = 1; i <= t; i++) {
		cin >> n;
		for (int j = 1; j <= n; j++) {
			int u = 0, v = 0, w = 0;
			cin >> u >> v >> w;
			if (u >= v && u >= w) {
				cnt += u;
			} else if (v >= w && v >= u) {
				cnt += v;
			} else if (w >= v && w >= u) {
				cnt += w;
			}
			cout << cnt << endl;
		}
	}

	return 0;
}