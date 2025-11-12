#include <bits/stdc++.h>
using namespace std;
int T, n, a[100005][3];
long long ans;
vector<int> club[3];
int main(void) {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	
	cin >> T;
	while (T--) {
		club[0].clear();
		club[1].clear();
		club[2].clear();
		ans = 0;
		cin >> n;
		for (int i = 1; i <= n; i++) {
			cin >> a[i][0] >> a[i][1] >> a[i][2];
			if (a[i][0] >= a[i][1] && a[i][0] >= a[i][2]) {
				club[0].push_back(i);
				ans += a[i][0];
			}
			else if (a[i][1] >= a[i][0] && a[i][1] >= a[i][2]) {
				club[1].push_back(i);
				ans += a[i][1];
			}
			else {
				club[2].push_back(i);
				ans += a[i][2];
			}
		}
		if (club[0].size() > n / 2) {
			sort(club[0].begin(), club[0].end(), [](int x, int y) -> bool {
				int disx = a[x][0] - max(a[x][1], a[x][2]);
				int disy = a[y][0] - max(a[y][1], a[y][2]);
				return disx > disy;
			});
			while (club[0].size() > n / 2) {
				int p = club[0][club[0].size() - 1];
				ans -= a[p][0] - max(a[p][1], a[p][2]);
				club[0].pop_back();
			}
		}
		else if (club[1].size() > n / 2) {
			sort(club[1].begin(), club[1].end(), [](int x, int y) -> bool {
				int disx = a[x][1] - max(a[x][0], a[x][2]);
				int disy = a[y][1] - max(a[y][0], a[y][2]);
				return disx > disy;
			});
			while (club[1].size() > n / 2) {
				int p = club[1][club[1].size() - 1];
				ans -= a[p][1] - max(a[p][0], a[p][2]);
				club[1].pop_back();
			}
		}
		else if (club[2].size() > n / 2) {
			sort(club[2].begin(), club[2].end(), [](int x, int y) -> bool {
				int disx = a[x][2] - max(a[x][0], a[x][1]);
				int disy = a[y][2] - max(a[y][0], a[y][1]);
				return disx > disy;
			});
			while (club[2].size() > n / 2) {
				int p = club[2][club[2].size() - 1];
				ans -= a[p][2] - max(a[p][0], a[p][1]);
				club[2].pop_back();
			}
		}
		cout << ans << endl;
	}
	return 0;
}
