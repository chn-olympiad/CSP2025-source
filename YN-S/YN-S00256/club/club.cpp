#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
#define int long long
int T, n;

struct node {
	int x, y, z;
} a[N];
vector<int>e[5];

signed main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> T;
	while (T--) {
		for (int i = 1; i <= 3; i++)
			e[i].clear();
		int cx = 0, cy = 0, cz = 0, ans = 0;
		cin >> n;
		for (int i = 1; i <= n; i++) {
			cin >> a[i].x >> a[i].y >> a[i].z;
			int w = max(a[i].x, max(a[i].y, a[i].z));
			ans += w;
			if (w == a[i].x) {
				e[1].push_back(min(a[i].x - a[i].y, a[i].x - a[i].z));
				cx++;
			} else if (a[i].y == w) {
				e[2].push_back(min(a[i].y - a[i].x, a[i].y - a[i].z));
				cy++;
			} else {
				e[3].push_back(min(a[i].z - a[i].y, a[i].z - a[i].x));
				cz++;
			}
		}
		int h = cx - n / 2;
		if (h > 0) {
			sort(e[1].begin(), e[1].end());
			for (int i = 0; i < h; i++) {
				ans -= e[1][i];
			}
		} else if (cy - n / 2 > 0) {
			sort(e[2].begin(), e[2].end());
			for (int i = 0; i < cy - n / 2; i++) {
				ans -= e[2][i];
			}
		} else if (cz - n / 2 > 0) {
			sort(e[3].begin(), e[3].end());
			for (int i = 0; i < cz - n / 2; i++) {
				ans -= e[3][i];
			}
		}
		cout << ans << "\n";
	}
	return 0;
}