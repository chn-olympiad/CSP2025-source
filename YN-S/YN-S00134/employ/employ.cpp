#include <bits/stdc++.h>
using namespace std;
#define int long long
int n, k;
string s;
const int N = 505;
int a[N];
int mod = 998244353;
int sum[N];

signed main() {
	ios::sync_with_stdio(0), cin.tie(0);
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	cin >> n >> k;
	cin >> s;
	sum[0] = 1;
	for (int i = 1; i <= n; i++) {
		sum[i] = (sum[i - 1] * i) % mod;
		//cout << sum[i] << " ";
	}
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	int ans = 1;
	for (int i = k; i <= n; i++) {
		ans += sum[i];
	}
	cout << ans;
	return 0;
}