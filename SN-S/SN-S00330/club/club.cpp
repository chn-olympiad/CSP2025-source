#include <bits/stdc++.h>

using namespace std;
int t;

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> t;
	for (int _ = 0; _ < t; ++_) {
		int n;
		cin >> n;

		struct person {
			int first, second, a, b;

			person() = default;
		};
		vector<person> a(n + 2, person());

		for (int i = 1; i <= n; ++i) {
			array<pair<int, int>, 3> c;
			for (int j = 0; j < 3; ++j) {
				cin >> c[j].first;
				c[j].second = j;
			}

			sort(c.begin(), c.end());

			a[i].first = c[2].first, a[i].a = c[2].second;
			a[i].second = c[1].first, a[i].b = c[1].second;
		}

		sort(a.begin() + 1, a.begin() + n + 1, [](auto x, auto y) -> bool {
			return x.first - x.second > y.first - y.second;
		});

		int ans = 0;
		array<int, 5> cnt {};
		fill(cnt.begin(), cnt.end(), 0);
		
		for (int i = 1; i <= n; ++i) {
			if (cnt[a[i].a] == n / 2) {
				ans += a[i].second;
				cnt[a[i].b]++;
			} else {
				ans += a[i].first;
				cnt[a[i].a]++;
			}
		}
		cout << ans << "\n";
	}
	return 0;
}
