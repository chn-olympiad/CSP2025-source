#include <bits/stdc++.h>
using namespace std;
const int N = 100010;
int a[N][5], b[N];
vector <int> v[5];
int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int t; scanf("%d", &t);
	while (t--) {
		int n; scanf("%d", &n);
		int fa = 1, fb = 1;
		for (int i = 1; i <= n; i++) {
			scanf("%d%d%d", &a[i][1], &a[i][2], &a[i][3]);
			if (a[i][3] != 0) fa = fb = 0;
			if (a[i][2] != 0) fa = 0;
		}
		if (fa) {
			for (int i = 1; i <= n; i++) b[i] = -a[i][1];
			sort(b + 1, b + n + 1);
			int ans = 0;
			for (int i = 1; i <= n / 2; i++) ans -= b[i];
			printf("%d\n", ans);
			continue;
		}
		for (int i = 1; i <= 3; i++) {
			while (v[i].size())
				v[i].pop_back();
		}
		int one = 0, two = 0, three = 0;
		int ans = 0;
		for (int i = 1; i <= n; i++) {
			int mx = -1, mn = -1;
			int idmx = -1;
			for (int j = 1; j <= 3; j++) {
				if (a[i][j] > mx) {
					mn = mx; mx = a[i][j];
					idmx = j;
				}
				else if (a[i][j] > mn) {
					mn = a[i][j];
				}
			}
			ans += mx;
			if (idmx == 1) one++;
			if (idmx == 2) two++;
			if (idmx == 3) three++;
			v[idmx].push_back(mx - mn);
		}
		if (max(one, max(two, three)) > n / 2) {
			if (one > n / 2) {
				sort(v[1].begin(), v[1].end());
				int _ = one - n / 2;
				for (int i = 0; i < _; i++) ans -= v[1][i];
			}
			else if (two > n / 2) {
				sort(v[2].begin(), v[2].end());
				int _ = two - n / 2;
				for (int i = 0; i < _; i++) ans -= v[2][i];
			}
			else {
				sort(v[3].begin(), v[3].end());
				int _ = three - n / 2;
				for (int i = 0; i < _; i++) ans -= v[3][i];
			}
		}
		cout << ans << '\n';
	}
	return 0;
}