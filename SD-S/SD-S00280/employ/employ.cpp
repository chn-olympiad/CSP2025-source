#include<bits/stdc++.h>
#define int long long
using namespace std;
const int MOD = 998244353;
int n,m,cnt,aza,a[505],dp[505][505];
int ans;
bool vis[505];
string s;
void dfs(int x,int u){
	if(n - u < m) return ;
	if(x > n){
		cnt++;
		return ;
	}
	for(int i = 1;i <= n;i++){
		if(vis[i]) continue;
		vis[i] = 1;
		if(s[x] == '0' || u >= a[i]) dfs(x + 1,u + 1);
		else dfs(x + 1,u);
		vis[i] = 0; 
	}
}
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	cin >> s;
	s = " " + s;
	for(int i = 1;i <= n;i++) scanf("%lld",&a[i]);
	sort(a + 1,a + n + 1); 
	if(n <= 10){
		dfs(1,0);
		printf("%lld",cnt);
		return 0;
	}
	dp[0][0] = 1;
	for(int i = 1;i <= n;i++){
		for(int j = 0;j <= n;j++){
			dp[i - 1][0] = 1;
			cnt = 0;
			for(int k = 1;k <= n;k++) if(s[i] != '0' && j < a[k]) cnt++;
			dp[i][j] = max(dp[i - 1][j] * (cnt - max(i - 1,1LL *0)) % MOD,1LL * 0);
			if(j) dp[i][j] = max((dp[i][j] + max(dp[i - 1][j - 1] * (n - cnt - max(i - 1,1LL * 0)) % MOD,1LL * 0)) % MOD,1LL * 0);
			if(i == n && j <= n - m) ans += dp[i][j];
		}
	}
	printf("%lld",ans); 
	return 0;
} 
