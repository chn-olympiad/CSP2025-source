#include<bits/stdc++.h>
using namespace std;
int a[5010];
long long dp[5010][5010];
int n;
int cnt=0;
long long ans=0;
long long TT=998244353;
void dfs(int l,int ma,long long z){
	if(l>n){
		if(z>(ma*2)){
			ans++;
		}
		return;
	}
	dfs(l+1,ma,z);
	dfs(l+1,max(ma,a[l]),z+a[l]);
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin >> n;
	for(int i=1;i<=n;i++) cin >> a[i];
	if(n>21){
		dp[0][0]=1;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=i;j++){
				dp[i][j]=(dp[i][j]+dp[i-1][j])%TT;
				if(j>1) dp[i][j]=(dp[i][j]+dp[i][j-1])%TT;
			}
		}
		long long sd=0;
		for(int i=1;i<=n;i++){
			sd=(sd+dp[n][i])%TT;
		}
		cout << sd;
		return 0;
	}
	dfs(1,0,0);
	cout << ans%TT;
	return 0;
}
