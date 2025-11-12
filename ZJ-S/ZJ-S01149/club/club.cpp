#include<bits/stdc++.h>
using namespace std;
const int N = 2e2 + 10;
int n,T,dp[N][N][N];
struct pos{
	int a1,a2,a3;
}a[100010];
bool cmp(pos x,pos y){
	return x.a1 > y.a1;
}
bool cmp2(pos x,pos y){
	return x.a1 - x.a2 > y.a1 - y.a2;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);
	cin >> T;
	while(T--){
		int flag1 = 1,flag2 = 1,ans = 0;
		memset(dp,0,sizeof(dp));
		cin >> n;
		for(int i = 1;i <= n;++i){
			cin >> a[i].a1 >> a[i].a2 >> a[i].a3;
			if(a[i].a2 != 0) flag1 = 0;
			if(a[i].a3 != 0) flag2 = 0;
		}
		if(flag1 && flag2){
			sort(a + 1,a + n + 1,cmp);
			for(int i = 1;i <= n / 2;++i){
				ans += a[i].a1;
			}
			cout << ans << '\n';
			continue;
		}
		if(flag2){
			sort(a + 1,a + n + 1,cmp2);
			for(int i = 1;i <= n / 2;++i){
				ans += a[i].a1;
			}
			for(int i = n / 2 + 1;i <= n;++i){
				ans += a[i].a2;
			}
			cout << ans << '\n';
			continue;
		}
		for(int i = 1;i <= n;++i){
			for(int j = 0;j <= min(n / 2,i);++j){
				for(int k = 0;k <= min(n / 2,i - j);++k){
					if(j > 0) dp[i][j][k] = max(dp[i][j][k],dp[i - 1][j - 1][k] + a[i].a1);
					if(k > 0) dp[i][j][k] = max(dp[i][j][k],dp[i - 1][j][k - 1] + a[i].a2);
					if(j + k < i) dp[i][j][k] = max(dp[i][j][k],dp[i - 1][j][k] + a[i].a3);
				}
			}
		}
		for(int j = 0;j <= n / 2;++j){
			for(int k = 0;k <= n / 2;++k){
				if(n - j - k > n / 2) continue;
				ans = max(ans,dp[n][j][k]);
			}
		}
		cout << ans << '\n';
	}
	return 0;
}
