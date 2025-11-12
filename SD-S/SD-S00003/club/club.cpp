#include <bits/stdc++.h>

using namespace std;

const int N = 100010;

int T;
int n;
int a[N][4];

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);

	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> T;
	while (T--) {
		cin >> n;
		for (int i = 1; i <= n; ++i) {
			cin >> a[i][0] >> a[i][1] >> a[i][2];
		}
		
		multiset<int> se0, se1, se2;
		
		int ans = 0;
		for (int i = 1; i <= n; ++i) {
			int mx = max({a[i][0], a[i][1], a[i][2]});

			if (mx == a[i][0]) {
				ans += a[i][0];
				se0.insert(a[i][0] - max(a[i][1], a[i][2]));
			} else if (mx == a[i][1]) {
				ans += a[i][1];
				se1.insert(a[i][1] - max(a[i][0], a[i][2]));
			} else {
				ans += a[i][2];
				se2.insert(a[i][2] - max(a[i][0], a[i][1]));
			}
		}

		if (se1.size() > n / 2) swap(se1, se0);
		if (se2.size() > n / 2) swap(se2, se0); 

		while (se0.size() > n / 2) {
			ans -= *se0.begin();
			se0.erase(se0.begin());
		}
		
		cout << ans << "\n";
	}
	cout.flush();

	return 0;
}

