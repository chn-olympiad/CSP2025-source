#include <bits/stdc++.h>
using namespace std;

using P = pair<int, int>;
using PPP = pair<P, P>;
const int N = 1e5 + 10;
int tot[N];
PPP a[N];

int comp(PPP a, PPP b) {
	return a.first.first - a.second.first > b.first.first - b.second.first;
}

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(0);
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		for (int i = 1; i <= n; i++) {
			P b[4];
			for (int j = 1; j <= 3; j++) {
				tot[j] = 0;
				cin >> b[j].first;
				b[j].second = j;
			}
			sort(b + 1, b + 3 + 1);
			a[i].first = b[3], a[i].second = b[2];
		}
		sort(a + 1, a + n + 1, comp);
		int ans = 0;
		for (int i = 1; i <= n; i++) {
			if (tot[a[i].first.second] < n / 2) {
				tot[a[i].first.second]++;
				ans += a[i].first.first;
			} else {
				tot[a[i].second.second]++;
				ans += a[i].second.first;
			}
		}
		cout << ans << "\n";
	}
	return 0;
}