#include <bits/stdc++.h>
const int MOD =  998244353;
using namespace std;
int n, a[100010], cnt = 0;

void dfs(int i, int ma, int sum, bool flag) {
//	cout << i << ' ' << ma << ' ' << sum << ' ' << cnt << endl;
//	if (vis[i][ma][sum])
//		return vis[i][ma][sum];
	if (flag and ma * 2 < sum)
		cnt++;
	if (i == n)
		return;
//	vis[i][ma][sum]
	dfs(i + 1, max(ma, a[i + 1]), sum + a[i + 1], 1);
	dfs(i + 1, ma, sum, 0);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	int flag = 1;
//	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		if (a[i] != 1)
			flag = 0;
	}
	if (flag) {
		int cnt = 0;
		for (long long i = 3; i <= n; i++) {
			long long t = n, cnt1 = 1, t1 = 1;
			for (long long j = n; j >= n - i + 1; j--) {
				t = t * j;
				t1 = t1 * cnt1;
				cnt1++;
			}
			cnt = (cnt + t / t1) % MOD;
		}
		return 0;
	}
	dfs(0, 0, 0, 0);
	cout << cnt;
	return 0;
}
