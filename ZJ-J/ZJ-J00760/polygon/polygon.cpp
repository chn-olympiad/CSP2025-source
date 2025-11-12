#include<bits/stdc++.h>
using namespace std;
int n, a[5010], sum, ans;
int main(){
	freopen("polygon.in", "w", stdin);
	freopen("polygon.out", "r", stdout);
	cin >> n;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
		sum += a[i];
	}
	sort(a + 1, a + n + 1);
	if(n == 3){
		if(a[n] < sum * 1.0 / 2){
			cout << 1;
		}
		else cout << 0;
		return 0;
	}
	for(int i = 3; i <= n; i++){
		int dp[50010];
		memset(dp, 0, sizeof(dp));
		dp[0] = 1;
		for(int j = 1; j < i; j++){
			for(int k = 50000; k >= 0; k--){
				if(dp[k] > 0) dp[k + a[j]] += dp[k];
 			}
		}
		for(int j = a[i] + 1; j <= 50000; j++){
			ans += dp[j];
			ans %= 998244353;
	 	}
	}
	cout << ans % 998244353;
	return 0;
}
