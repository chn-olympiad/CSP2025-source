#include <bits/stdc++.h>
using namespace std;

int t, n, a[100010][4], dp[110][110][110];

int main (){
	freopen ("club.in", "r", stdin);
	freopen ("club.out", "w", stdout);
	scanf ("%d", &t);
	for (; t; t--){
		scanf ("%d", &n);
		int v = 1, v1 = 1;
		for (int i = 1; i <= n; i++){
			scanf ("%d%d%d", &a[i][1], &a[i][2], &a[i][3]);
			if (a[i][2] != 0 || a[i][3] != 0)
				v = 0;
			
		}
		if (n <= 200){
			for (int i = 0; i <= n / 2; i++)
				for (int j = 0; j <= n / 2; j++)
					for (int k = 0; k <= n / 2; k++)
						dp[i][j][k] = 0;
			for (int i = 0; i <= n / 2; i++){
				for (int j = 0; j <= n / 2; j++){
					for (int k = 0; k <= n / 2; k++){
						dp[i + 1][j][k] = max (dp[i + 1][j][k], dp[i][j][k] + a[i + j + k + 1][1]);
						dp[i][j + 1][k] = max (dp[i][j + 1][k], dp[i][j][k] + a[i + j + k + 1][2]);
						dp[i][j][k + 1] = max (dp[i][j][k + 1], dp[i][j][k] + a[i + j + k + 1][3]);
					}
				}
			}
			int ans = 0;
			for (int i = 0; i <= n / 2; i++)
				for (int j = 0; j <= n / 2; j++)
					for (int k = 0; k <= n / 2; k++)
						if (i + j + k == n)
							ans = max (ans, dp[i][j][k]);
			printf ("%d\n", ans);
			continue;
		}
		if (v == 1){
			int c[100010];
			for (int i = 1; i <= n; i++)
				c[i] = a[i][1];
			sort (c + 1, c + n + 1);
			int ans = 0;
			for (int i = n; i >= n / 2 + 1; i--){
				ans += c[i];
			}
			printf ("%d", ans);
			continue;
		}
	}
	return 0;
}