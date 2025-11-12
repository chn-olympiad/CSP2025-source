// 苦心人，天不负，加油！
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 5010, MX = 5010;
const int mod = 998244353;
int n, a[N];
ll dp[MX], sum[MX], pow2[N];
ll ans1[N], ans;

ll _abs(int x) {return (x % mod + mod) % mod;}

int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	sort(a + 1, a + n + 1);
	memset(dp, 0, sizeof(dp));
	pow2[0] = sum[0] = dp[0] = 1;
	for (int i = 1; i <= n; i++)
		pow2[i] = pow2[i - 1] * 2 % mod;
	for (int i = 1; i <= n; i++) {
		if (i >= 3) ans1[i] = _abs(pow2[i - 1] - sum[a[i]]);
		for (int j = 5000; j >= a[i]; j--)
			dp[j] = (dp[j] + dp[j - a[i]]) % mod;
		for (int j = 1; j <= 5000; j++)
			sum[j] = (sum[j - 1] + dp[j]) % mod;
	}
	for (int i = 1; i <= n; i++)
		ans = (ans + ans1[i]) % mod;
	printf("%lld\n", ans);
}
