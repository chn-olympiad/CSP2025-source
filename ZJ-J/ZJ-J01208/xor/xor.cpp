#include <iostream>
#include <algorithm>

#define int long long

int a[500005], ps[500005];
int dp[500005][5];

signed main(){
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	
	int n, k, sp = 1;
	scanf("%lld%lld", &n, &k);
	for(int i = 1;i <= n;i++){
		scanf("%lld", &a[i]);
		if(a[i] > 1)
			sp = 0;
		ps[i] = ps[i - 1] ^ a[i];
	}
	
	if(n > 1000 and sp == 1){
		int ans = 0;
		if(k == 1){
			for(int i = 1;i <= n;i++)
				if(a[i] == 1)
					ans++;			
		}
		if(k == 0){
			for(int i = 1;i <= n;i++)
				if(a[i] == 0)
					ans++;
				else{
					if(a[i + 1] == 1){
						ans++;
						i++;
					}
				}
		}
		printf("%lld", ans);
	}
	else{
		dp[1][0] = 0;
		dp[1][1] = (a[1] == k);
		for(int i = 2;i <= n;i++){
			dp[i][0] = std::max(dp[i - 1][0], dp[i - 1][1]);
			for(int j = 1;j < i;j++){
				dp[i][1] = std::max({dp[j][0] + ((ps[i] ^ ps[j - 1]) == k), dp[j][1] + ((ps[i] ^ ps[j]) == k), dp[i][1]});
			}
		}
		printf("%lld", std::max(dp[n][1], dp[n][0]));		
	}
	return 0;
}