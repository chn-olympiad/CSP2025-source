#include <bits/stdc++.h>
using namespace std;
#define int long long
#define mod 998244353
#define endl '\n'
const int N = 5e3 + 5;
int n;
int a[N];
long long sum[N];
namespace subtask1 {
	int ans = 0;
	void dfs (int dis, int cnt, int num) {
//		cout << dis << " " << num << " " << cnt + a[dis] << " " << a[dis] * 2 << endl;
		if (num >= 3 && cnt + a[dis] > 2 * a[dis]) {
//			cout << num << " " << cnt + a[dis] << " " << a[dis] * 2 << endl << endl << endl;
			ans++;
			ans %= mod;
		}
		for (int i = dis + 1; i <= n; i++) {
			dfs (i, cnt + a[dis], num + 1);
		}
	}
//	3 7 6
	void main () {
		for (int i = 1; i <= n; i++) {
			ans %= mod;
			dfs (i, 0, 1);
		}
		cout << ans % mod << endl;
		return ;
	}
}

namespace subtask2 {
	void main () {
		long long ans = 0;
		for (int i = 3; i <= n; i++) {
			long long cnt = 1;
			for (int j = 1; j <= i; j++) {
				cnt = cnt * (n - j + 1) % mod;
				cnt = cnt / j % mod;
			}
			ans += cnt % mod;
		}
		cout << ans << endl;
	}
}

signed main () {
	freopen ("polygon.in", "r", stdin);
	freopen ("polygon.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	sort (a + 1, a + n + 1);
	
	
	if (n == 3) {
		if (a[1] + a[2] <= a[3] * 2) cout << 0;
		else cout << 1;
		return 0;
	}
	if (a[n] == 1) {
		subtask2::main();
		return 0;
	}
	subtask1::main();
	return 0;
}
