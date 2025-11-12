#include <bits/stdc++.h>
using namespace std;
int t,n,a[100005],b[100005],c[100005];
long long dp[205][205][205];
int main(){
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	scanf("%d", &t);
	while (t--){
		scanf("%d", &n);
		for (int i = 1;i <= n;i++)
			scanf("%d%d%d", &a[i], &b[i], &c[i]);
		int mb = *max_element(b + 1,b + n + 1),mc = *max_element(c + 1,c + n + 1);
		long long ans = 0;
		if (mb == 0 && mc == 0){
			sort(a + 1,a + n + 1);
			for (int i = n / 2 + 1;i <= n;i++)
				ans += a[i];
		}
		else if (n <= 200){
			for (int i = 0;i <= n / 2;i++)
				for (int j = 0;j <= n / 2;j++)
					for (int k = 0;k <= n - i - j && k <= n / 2;k++){
						int p = i + j + k;
						if (i) dp[i][j][k] = max(dp[i][j][k],dp[i - 1][j][k] + a[p]);
						if (j) dp[i][j][k] = max(dp[i][j][k],dp[i][j - 1][k] + b[p]);
						if (k) dp[i][j][k] = max(dp[i][j][k],dp[i][j][k - 1] + c[p]);
						if (p == n) ans = max(ans,dp[i][j][k]);
					}
		}
		printf("%lld\n", ans);
		memset(dp,0,sizeof(dp));
	}
	return 0;
}
