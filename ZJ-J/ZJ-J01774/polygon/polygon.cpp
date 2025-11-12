#include<bits/stdc++.h>
using namespace std;
#define int long long
int mod = 998244353;
int ans = 0;
int dp[5050][5050];
int dp1[5050];
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(false);	
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;
	vector<int> a(n + 1);
	for (int i = 1; i <= n; i++){
		cin >> a[i];
	}
	dp1[0] = 1;
	sort(a.begin() + 1,a.end());
	for (int i = 1; i <= n; i++){
		int cnt = 0;
		for (int j = 5010; j >= a[i]; j--){
			dp1[j] += dp1[j - a[i]];
			dp1[j] %= mod;
		}
//		dp1[a[i]]++;
		for (int j = 5010; j >= 0; j--){
			dp[i][j] += cnt;
			cnt += dp1[j];
			cnt %= mod;
			dp[i][j] %= mod;
		}
		if (i >= 2){
			for (int j = 1; j < i; j++){
				ans += dp[j - 1][a[i] - a[j]];
				ans %= mod;
			}
		}
		
	}
	cout << ans;
	return 0;
}
