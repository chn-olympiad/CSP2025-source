#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int N = 1e5 + 10;

int t, n, a[N][5], n1, n2, n3, rk[N];
long long ans;

vector <int> v1, v2, v3;

signed main(void) {
	cin.tie(nullptr);
	cout.tie(nullptr);
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin >> t;
	while (t--) {
		cin >> n;
		n1 = n2 = n3 = 0;
		ans = 0;
		v1.clear();
		v2.clear();
		v3.clear();
		for (int i = 1; i <= n; ++i) {
			cin >> a[i][1] >> a[i][2] >> a[i][3];
			if (a[i][1] >= a[i][2] && a[i][1] >= a[i][3]) {
				v1.push_back(i);
				++n1;
				ans += a[i][1];
			} else if (a[i][2] >= a[i][1] && a[i][2] >= a[i][3]) {
				v2.push_back(i);
				++n2;
				ans += a[i][2];
			} else {
				v3.push_back(i);
				++n3;
				ans += a[i][3];
			}
		}
		if (n1 > n / 2) {
			for (int i = 0; i < n1; ++i) rk[i] = a[v1[i]][1] - max(a[v1[i]][2], a[v1[i]][3]);
			sort(rk, rk + n1);
			for (int i = 0; i < n1 - (n / 2); ++i) ans -= rk[i];
		} else if (n2 > n / 2) {
			for (int i = 0; i < n2; ++i) rk[i] = a[v2[i]][2] - max(a[v2[i]][1], a[v2[i]][3]);
			sort(rk, rk + n2);
			for (int i = 0; i < n2 - (n / 2); ++i) ans -= rk[i];
		} else if (n3 > n / 2) {
			for (int i = 0; i < n3; ++i) rk[i] = a[v3[i]][3] - max(a[v3[i]][1], a[v3[i]][2]);
			sort(rk, rk + n3);
			for (int i = 0; i < n3 - (n / 2); ++i) ans -= rk[i];
		} cout << ans << '\n';
	}
}
