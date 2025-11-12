#include <algorithm>
#include <iostream>
using namespace std;
const int MAXN = 205, MAXN2 = 1e5 + 5;
int a[MAXN][5], f[MAXN / 2][MAXN / 2][MAXN / 2], s[MAXN];
int main(void) {
	ios_base :: sync_with_stdio(false);
	cin . tie(0);
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int t;
	cin >> t;
	while (t--) {
		int ans = -1, n;
		cin >> n;
		if (n <= 100) {
			for (int i = 1;i <= n; ++i) {
				for (int j = 1;j <= 3; ++j)
					cin >> a[i][j];
				for (int j = i;j >= 0; --j)
					for (int k = min(i - j, n / 2);k >= 0; --k) {
						int l = i - j - k;
						f[j][k][l] = max(f[j - 1][k][l] + a[i][1], max(f[j][k][l - 1] + a[i][2], f[j][k - 1][l] + a[i][3]));
					}
			}
			for (int i = 0;i <= n / 2; ++i)
				for (int j = 0;j <= n - i && j <= n / 2; ++j) {
					int k = n - i - j;
					ans = max(ans, f[i][j][k]);
				}
			cout << ans << '\n';
			continue;
		}
		for (int i = 1;i <= n; ++i) {
			cin >> s[i];
			int l;
			cin >> l;
			cin >> l;
		}
		ans = 0;
		sort(s + 1, s + 1 + n, greater<int>());
		for (int i = 1;i <= n / 2; ++i)
			ans += s[i];
		cout << ans << '\n';
	}
	return 0;
} 
