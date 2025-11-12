#include<bits/stdc++.h>
using namespace std;
long long a[5010];
long long dp[5010][5010];
long long mod=998244353;
long long ans;
long long b[5010];
int n;
long long mx=0;
void dfs(int x,long long sum,long long maxx){
	if (x==n+1){
		if (sum>maxx*2){
			ans++;
		}
		return;
	}
	dfs(x+1,sum+a[x],max(maxx,a[x]));
	dfs(x+1,sum,maxx);
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	bool fg=0;
	for (int i=1;i<=n;i++){
		cin >> a[i];
		mx=max(mx,a[i]);
		if (a[i]>1){
			fg=1;
		}
		b[i]=b[i-1]+a[i]; 
	}
	if (n<=20){
		dfs(1,0,0);
		cout << ans%mod;
		return 0;
	}
	if (fg==0){
		dp[1][1]=1;
		for (int i=1;i<=n+3;i++){
			for (int j=1;j<=i;j++){
				if (j!=i){
					dp[i][j]=dp[i-1][j-1]+dp[i-1][j];
					dp[i][j]%=mod;
				}
				else{
					dp[i][j]=1;
				}
			}
		}
		for (int j=1;j<n;j++){
			ans=ans+dp[n+1][j];
			ans%=mod;
		}
		ans-=dp[n+1][3];
		cout << ans;
		return 0;
	}
	else{
		cout << 0; 
	}
	return 0;
}

