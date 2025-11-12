#include <bits/stdc++.h>
using namespace std;

const long long N = 5e4+10, Mod = 998244353;
long long dp[N], a[N], ans;

int main() {
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n, sum = 0;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		sum += a[i];
	}
	sort(a+1,a+n+1);
	memset(dp,0,sizeof dp);
	dp[0] = 1;
	for (int i = 1; i <= n; i++) {
		for (int j = sum; j >= a[i]; j--)
			dp[j] = (dp[j]+dp[j-a[i]]) % Mod;
		for (int j = 2*a[i]+1; j <= sum; j++)
			ans = (ans+dp[j])%Mod;
	}
	cout << ans << "\n";
	return 0;
}
