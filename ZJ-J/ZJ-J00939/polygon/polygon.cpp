/*luoguUID: 995899*/
#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 5005;
int ans, n, a[N];
inline void dfs (int i, int sum, int lst, int num) {
	if (i > n) {
		if (num >= 3 && lst != 0 && sum > lst * 2) {
			ans++;
			ans %= 998244353;
		}
		return;
	}
	dfs (i + 1, sum, lst, num);
	dfs (i + 1, sum + a[i], a[i], num + 1);
}
signed main () {
	freopen ("polygon.in", "r", stdin);
	freopen ("polygon.out", "w", stdout);
	ios :: sync_with_stdio (0);
	cin.tie (0), cout.tie (0);
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	sort (a + 1, a + n + 1);
	dfs (1, 0, 0, 0);
	cout << ans;
	return 0;
}