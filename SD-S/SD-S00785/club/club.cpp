//O(n^3) dp 55 + 5 / 15 spj(a)
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n" 
int t;
int n;
int a[100005][5];
int spja[100005];
int dp[105][105][105];
int ans;
int flag1,flag2;
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin >> t;
	while(t --){
		flag1 = flag2 = 1;
		ans = 0;
		memset(dp,0,sizeof(dp));
		cin >> n;
		for(int i=1;i<=n;i++){
			cin >> a[i][1] >> a[i][2] >> a[i][3];
			if(a[i][2] || a[i][3]) flag1 = 0;
			if(a[i][3]) flag2 = 0;
		}
		if(flag1){
			for(int i=1;i<=n;i++){
				spja[i] = a[i][1];
			}
			sort(spja + 1,spja + n + 1);
			reverse(spja + 1,spja + n + 1);
			for(int i=1;i<=n/2;i++){
				ans += spja[i];
			}
			cout << ans << endl; 
		}else{
			for(int i=1;i<=n;i++){
				for(int j=n/2;j>=0;j--){
					for(int k=n/2;k>=0;k--){
						int r = i - j - k;
						if(r > n / 2 || r < 0) continue;
						if(j) dp[j][k][r] = max(dp[j][k][r],dp[j - 1][k][r] + a[i][1]);
						if(k) dp[j][k][r] = max(dp[j][k][r],dp[j][k - 1][r] + a[i][2]);
						if(r) dp[j][k][r] = max(dp[j][k][r],dp[j][k][r - 1] + a[i][3]);
						if(i == n) ans = max(ans,dp[j][k][r]);
					}
				} 
			}
			cout << ans << endl;	
		}
	}
	return 0;
} 
