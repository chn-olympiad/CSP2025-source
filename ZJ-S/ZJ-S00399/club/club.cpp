#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 1000;
int sa[5][maxn];
int n,ans,t;
int dp[111][121][121][121];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin >> t;
	while(t--){
		cin >> n;
		memset(dp,0,sizeof(dp));
		int mx = n / 2,ans = 0;
		for(int i = 1;i <= n;i++)
			for(int j = 1;j <= 3;j++)
				cin >> sa[j][i];
		for(int i = 1;i <= n;i++){
			for(int j = 0;j <= mx;j++){
				for(int k = 0;k <= mx;k++){
					for(int l = 0;l <= mx;l++){
						if(j <= mx) dp[i][j][k][l] = max(dp[i - 1][j - 1][k][l] + sa[1][i],dp[i][j][k][l]),ans = max(ans,dp[i][j][k][l]);;
						if(k <= mx) dp[i][j][k][l] = max(dp[i - 1][j][k - 1][l] + sa[2][i],dp[i][j][k][l]),ans = max(ans,dp[i][j][k][l]);;
						if(l <= mx) dp[i][j][k][l] = max(dp[i - 1][j][k][l - 1] + sa[3][i],dp[i][j][k][l]),ans = max(ans,dp[i][j][k][l]);;
						//cout << i << " " << j << " " << k << " " << ans << endl;
						//ans = max(ans,dp[i][j][k][l]);
					}
				}
			}
		}
		//int ans = 0;
		//for(int i = 1;i <= 3;i++) ans = max(dp[n][i].ans,ans);
	//	for(int i = 1;i <= 3;i++) if(ans == dp[n][i].ans) cout << dp[n][i].num1 << "--"<< dp[n][i].num2 << "--"<< dp[n][i].num3 <<endl;
		cout << ans << "\n";
	}
	 
	return 0;
}
//3
//4
//4 2 1
//3 2 4
//5 3 4
//3 5 1
//4
//0 1 0
//0 1 0
//0 2 0
//0 2 0
//2
//10 9 8
//4 0 0
