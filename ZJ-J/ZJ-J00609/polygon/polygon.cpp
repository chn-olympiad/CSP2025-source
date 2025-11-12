#include <bits/stdc++.h>
#define ll long long
#define Fcin; ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
int a[5050], cnt, n, sum, vis[25], c[25];
ll f[5050];
const int mod = 998244353;
void dfs (int step, int ans, int maxn, int k, int now) {
	c[k] = now;
	if (k >= maxn && step <= n + 1) {
		for (int i = 1; i <= n; i++) vis[i] = 0;
		for (int i = 1; i <= k; i++) {
			vis[c[i]] = 1;
		}
		int p = 0;
		for (int i = n; i >= 1; i--)
		  if (!vis[i]) {
		  	p = i;
		  	break;
		  }
		if ((sum - ans) > (a[p] * 2)) {
			cnt = (cnt + 1) % mod;
		}
		return;
	}
	if (step > n) return;
	dfs (step + 1, ans + a[step], maxn, k + 1, step);
	dfs (step + 1, ans, maxn, k, now);
	return;
}
int main () {
	Fcin;
	freopen ("polygon.in", "r", stdin);
	freopen ("polygon.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i], sum += a[i];
	sort (a + 1, a + n + 1);
	if (a[n] == 1) {
		f[0] = 1;
		for (int i = 1; i <= n; i++)
		  for (int j = i; j <= n; j++)
		    f[j] = (f[j] + f[j - i]) % mod;		
		cout << f[n] % mod;
		return 0;
	}
	for (int i = 0; i <= n - 3; i++) {
		if (i == 0) {
			if (sum > a[n] * 2) cnt++;
			continue;
		}
		dfs (1, 0, i, 0, 0);
	}
	cout << cnt % mod;
	return 0;
}
