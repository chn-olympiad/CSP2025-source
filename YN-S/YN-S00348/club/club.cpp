#include <bits/stdc++.h>
using namespace std;
int t, f[100001];
int ans = -1, sum = 0;

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin >> t;

	while (t--) {
		int n;
		pair<int, pair<int, int>>a[100001];
		cin >> n;

		for (int i = 1; i <= n; i++) {

			cin >> a[i].first.first >> a[i].first.second >> a[i].second.first;
			ans = max(ans, a[i].first.first);
		}

		cout << ans << endl;
	}

	return 0;
}