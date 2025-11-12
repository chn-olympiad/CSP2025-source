#include<bits/stdc++.h>
using namespace std;
long long t, n, dp[200001][4], a[200001][4], tot = 0, ji[100001][4];
int c[20001];
inline void dfs (int i) {
	if (i == n + 1) {
		long long x = 0, y = 0, z = 0, ans = 0;
		for (int j = 1; j <= n; j++) {
			ans += a[j][c[j]];
			if (c[j] == 1) x++;
			else if (c[j] == 2) y++;
			else z++;
		}
		if (x > n / 2 || y > n / 2 || z > n / 2) return;
		tot = max(tot, ans);
		return;
	}
	c[i] = 1;
	dfs(i + 1);
	c[i] = 2;
	dfs(i + 1);
	c[i] = 3;
	dfs(i + 1);
}
int main () {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	scanf("%lld", &t);
	while(t--) {
		tot = 0;
		scanf("%lld", &n);
		for (int i = 1; i <= n; ++i) {
			scanf("%lld%lld%lld", &a[i][1], &a[i][2], &a[i][3]);
		}
		if (n <= 25) {
			dfs(1);
			printf("%lld\n", tot);
			continue;
		}
		for (int i = 1; i <= n; i++) {
				if (ji[i - 1][1] < n / 2 && dp[i - 1][1] + a[i][1] >= dp[i - 1][2] + a[i][1] && dp[i - 1][1] + a[i][1] >= dp[i - 1][3] + a[i][1]) {
					dp[i][1] = max(dp[i][1], dp[i - 1][1] + a[i][1]);
					ji[i][1] = ji[i - 1][1] + 1;
					ji[i][2] = ji[i - 1][2];
					ji[i][3] = ji[i - 1][3];
				}else  
					if (ji[i - 1][2] < n / 2 && dp[i - 1][2] + a[i][1] >= dp[i - 1][1] + a[i][1] && dp[i - 1][2] + a[i][1] >= dp[i - 1][3] + a[i][1]) {
						dp[i][1] = max(dp[i][1], dp[i - 1][2] + a[i][1]);
						ji[i][1] = ji[i - 1][1];
						ji[i][3] = ji[i - 1][3];
						ji[i][2] = ji[i - 1][2] + 1;
					}else  {
							dp[i][1] = max(dp[i][1], dp[i - 1][3] + a[i][1]);
							ji[i][1] = ji[i - 1][1];
							ji[i][3] = ji[i - 1][3] + 1;
							ji[i][2] = ji[i - 1][2];					
						}
				if (ji[i - 1][1] < n / 2 && dp[i - 1][1] + a[i][2] >= dp[i - 1][2] + a[i][2] && dp[i - 1][1] + a[i][2] >= dp[i - 1][3] + a[i][2]) {
					dp[i][2] = max(dp[i][2], dp[i - 1][1] + a[i][2]);
					ji[i][1] = ji[i - 1][1] + 1;
					ji[i][2] = ji[i - 1][2];
					ji[i][3] = ji[i - 1][3];
				}else 
					if (ji[i - 1][2] < n / 2 && dp[i - 1][2] + a[i][2] >= dp[i - 1][1] + a[i][2] && dp[i - 1][2] + a[i][2] >= dp[i - 1][3] + a[i][2]) {
						dp[i][2] = max(dp[i][2], dp[i - 1][2] + a[i][2]);
						ji[i][2] = ji[i - 1][2] + 1;
						ji[i][1] = ji[i - 1][1];
						ji[i][3] = ji[i - 1][3];
					}else {
							dp[i][2] = max(dp[i][2], dp[i - 1][3] + a[i][2]);
							ji[i][3] = ji[i - 1][3] + 1;
							ji[i][1] = ji[i - 1][1];
							ji[i][2] = ji[i - 1][2];					
						}
				if (ji[i - 1][1] < n / 2 && dp[i - 1][1] + a[i][3] >= dp[i - 1][2] + a[i][3] && dp[i - 1][1] + a[i][3] >= dp[i - 1][3] + a[i][3]) {
					dp[i][3] = max(dp[i][3], dp[i - 1][1] + a[i][3]);
					ji[i][1]= ji[i - 1][1] + 1;
					ji[i][3] = ji[i - 1][3];
					ji[i][2] = ji[i - 1][2];
				}else 
					if (ji[i - 1][2] < n / 2 && dp[i - 1][2] + a[i][3] >= dp[i - 1][1] + a[i][3] && dp[i - 1][2] + a[i][3] >= dp[i - 1][3] + a[i][3]) {
						dp[i][3] = max(dp[i][3], dp[i - 1][2] + a[i][3]);
						ji[i][2] = ji[i - 1][2] + 1;
						ji[i][1] = ji[i - 1][1];
						ji[i][3] = ji[i - 1][3];
					}else {
							dp[i][3] = max(dp[i][3], dp[i - 1][3] + a[i][3]);
							ji[i][3] = ji[i - 1][3] + 1;
							ji[i][1] = ji[i - 1][1];
							ji[i][2] = ji[i - 1][2];					
						}
				
		}
		for (int i = 1; i <= n; i++) {
			tot = max(tot, max(dp[i][1], max(dp[i][2], dp[i][3])));
		}
		printf("%lld\n", tot);
		memset(dp, 0, sizeof(dp));
		for (register int i = 1; i <= n; ++i) {
			for (register int j = 1; j <= 3; ++j) {
				ji[i][j] = 0;
					
				}
			}
			
	}
		
	
	return 0;
}

