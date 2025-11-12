#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int N = 1e5 + 10, mod = 998244353;
int T, n, a[N][5];
vector<int>c[5], tmp;
int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	ios::sync_with_stdio(false); cin.tie(0);
	cin >> T;
	while (T--) {
		tmp.clear();
		for (int i = 1; i <= 3; i++) c[i].clear();
		cin >> n;
		ll ans = 0;
		for (int i = 1; i <= n; i++) {
			int p = 1;
			for (int j = 1; j <= 3; j++) {
				cin >> a[i][j];
				if (a[i][j] > a[i][p]) p = j;
			}
			c[p].push_back(i);
			ans += a[i][p];
		}
		for (int j = 1; j <= 3; j++) if ((int)c[j].size() > n / 2) {
			for (auto i : c[j]) {
				int mx = 0;
				for (int k = 1; k <= 3; k++) if (j != k) {
					mx = max(mx, a[i][k]);
				}
				tmp.push_back(a[i][j] - mx);
			}
			int d = (int)c[j].size() - (n / 2);
			sort(tmp.begin(), tmp.end());
			for (int i = 0; i < d; i++) ans -= tmp[i];
			break;
		}
		cout << ans << '\n';
	}
	return 0;
}

