#include <bits/stdc++.h>
using namespace std;
const int M = 0x3f3f3f3f;
const int N = 100005;
int t, n, a[N], b[N], c[N], pa[N], pb[N], pc[N];
bool v[N];




int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> t;
	while (t--) {
		memset(a, 0, sizeof(a));
		memset(b, 0, sizeof(b));
		memset(c, 0, sizeof(c));
		cin >> n;
		int mid = n / 2;
		for (int i = 1; i <= n; i++) {
			cin >> a[i] >> b[i] >> c[i];
			pa[i] = a[i];
			pb[i] = b[i];
			pc[i] = c[i];
		}

		sort(a + 1, a + n + 1, greater<int>());
		sort(b + 1, b + n + 1, greater<int>());
		sort(c + 1, c + n + 1, greater<int>());

		int ans = 0;
		for (int i = 1; i <= mid; i++)
			ans += a[i];

		cout << ans << endl;

	}
}
