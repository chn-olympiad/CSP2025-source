#include <bits/stdc++.h>
using namespace std;
struct e{
	long long sum, ans;
}; 
long long mod (long long x){
	return x - x / 998244353 * 998244353;
}
e dp[5010];
int n, a[5010];
int main(){
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; i ++){
		cin >> a[i];
	}
	sort(a + 1, a + n + 1);
	for (int i = 3; i <= n; i ++){
		cout << a[i];
	}
	dp[2].sum = a[1] + a[2];
	for (int i = 3; i <= n; i ++){
		dp[i].ans = i - 2;
		dp[i].sum = dp[i - 1].sum + a[i - 1];
	}
	for (int i = 3; i <= n; i ++){
		for (int j = 3; j < i; j ++){
			if (a[i] < dp[j].sum){
				dp[i].ans += dp[j].ans;
				dp[i].ans = mod(dp[i].ans);
			}
		}
	}
	long long ans1 = 0;
	for (int i = 3; i <= n; i ++){
		ans1 += dp[i].ans;
		ans1 = mod(ans1);
	}
	cout << ans1;
	return 0;
}
