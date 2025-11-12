#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int t, n ;
	cin >> t;
	for (int T = 1; T <= t; T++) {
		int ans = 0, count[3] = {0, 0, 0};
		cin >> n;
		int next[n], next_[n], c[n];
		vector < vector<int> > v(n);
		for (int i = 0; i < n; i++) {
			v[i].resize(3);
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j <= 2; j++) {
				cin >> v[i][j];
			}
		}
		for (int i = 0; i < n; i++) {
			int Max = max(v[i][1], max(v[i][2], v[i][0]));
			for (int tmp = 0; tmp <= 2; tmp++) {
				if (v[i][tmp] == Max)
					c[i] = tmp;
			}
			count[c[i]] += 1;
			next[i] = 1 << 30;
			for (int tmp = 0; tmp <= 2; tmp++) {
				if (tmp != c[i]) {
					if (next[i] > v[i][c[i]] - v[i][tmp]) {
						next[i] = v[i][c[i]] - v[i][tmp];
						next_[i] = tmp;
					}
				}
			}
		}
		for (int i = 0; i <= 2; i++) {
			while (count[i] > n / 2) {
				int min = 1 << 30;
				int min_i = 0;
				for (int j = 0; j < n; j++) {
					if (c[j] == i && (min > next[j])) {
						min = next[j];
						min_i = j;
					}
				}
				c[min_i] = next_[min_i];
				count[i] -= 1;
				count[c[min_i]] += 1;
				for (int tmp = 0; tmp <= 2; tmp++) {
					if (next[min_i] > v[min_i][tmp]) {
						next[min_i] = v[min_i][tmp];
						next_[min_i] = tmp;
					}
				}
			}
		}
		for (int i = 0; i < n; i++) {
			ans += v[i][c[i]];
		}
		cout << ans << endl;
	}
	return 0;
}