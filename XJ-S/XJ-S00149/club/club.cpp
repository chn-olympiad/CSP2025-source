#include <bits/stdc++.h>

using namespace std;

const int N = 143 + 10;
int n, t;
int a[N][5], dp[N][5], vis[N][5], ans;//dp[i][j][k]表示第i个人在第i - j个人的基础上选k 

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin >> t;
	while(t --) {	
		memset(a, 0, sizeof(a));
		memset(dp, 0, sizeof(dp));
		memset(vis, 0, sizeof(vis));
		ans = 0;
		cin >> n;
		for(int i = 1; i <= n; i ++) 
			cin >> a[i][1] >> a[i][2] >> a[i][3];
		for(int i = 1; i <= n; i ++)
			for(int j = 1; j <= i; j ++) {
				for(int k1 = 1; k1 <= 3; k1 ++) {
					for(int k2 = 1; k2 <= 3; k2 ++){
						if(vis[i - j][k1] <= n / 2 - 1){
//							cout << i << " " << j << " " << k1 << " " << k2  << vis[i - j][k2] << dp[i][k2] << endl;
							dp[i][k2] = max(dp[i - j][k1] + a[i][k2], dp[i][k2]);
							if(j == i)
								if(vis[i - j][k1] == 0){
									if(k1 == k2){
//										cout << k1 << k2 << endl;
										vis[i][k2] == 2;
										if(2 > n / 2) dp[i][k2] = 0;
									} else{
										vis[i][k2] == 1;
									}
								}
							else
								vis[i][k2] = vis[i - j][k2] + 1;
						}
					}
				}
			}
		for(int i = 1; i <= n; i ++){
			for(int j = 1; j <= 3; j ++) {
//				cout << dp[i][j] << " ";
				ans = max(ans, dp[i][j]);
			}
//			cout << endl;
		}
		cout << ans << endl;
	}
	return 0;
} 



