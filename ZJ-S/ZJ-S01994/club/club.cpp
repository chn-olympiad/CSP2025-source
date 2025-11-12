#include <bits/stdc++.h>
using namespace std;
int n,k;
long long dp[1100][1100],ans;
struct node{
	long long a,b,c;
}a[100010];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin >> k;
	while(k-- && cin >> n){
		ans = 0;
		for(int i = 0;i <= n / 2;i++){
			for(int j = 0;j <= n / 2;j++){
				dp[i][j] = 0;
			}
		}
		for(int i = 1;i <= n;i++){
			cin >> a[i].a >> a[i].b >> a[i].c;
		}
		for(int i = 1;i <= n;i++){
			for(int j = min(n / 2,i);j >= 0;j--){
				for(int k1 = min(n / 2,i);k1 >= 0;k1--){
					if(i - k1 - j > n / 2 || i - k1 - j < 0){
						continue;
					}
					if(i - k1 - j > 0){
						dp[j][k1] = dp[j][k1] + a[i].c;
					}
					if(j != 0){
						dp[j][k1] = max(dp[j][k1],dp[j - 1][k1] + a[i].a);
					}
					if(k1 != 0){
						dp[j][k1] = max(dp[j][k1],dp[j][k1 - 1] + a[i].b);
					}
					if(i == n){
						ans = max(ans,dp[j][k1]);
					}
				}
			}
		}
		cout << ans << "\n";
	}
	return 0;
}

