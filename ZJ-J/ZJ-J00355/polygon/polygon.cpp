#include <bits/stdc++.h>
using namespace std;
const int N=998244353;
int n,a[5010],ans,m,dp[5010][5010];
void dfs(int x,int ma,int num,int s){
	if(x==n){
		if(num>=3 and s>2*ma){
			ans=(ans+1)%N;
		}
		return;
	}
	dfs(x+1,ma,num,s);
	dfs(x+1,a[x],num+1,s+a[x]);
}
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
		m=max(a[i],m);
	}
	if(m==1){
		for(int i=0;i<=n;i++){
			dp[i][0]=1;
			dp[i][i]=1;
		}
		for(int i=2;i<=n;i++){
			for(int j=1;j<i;j++){
				dp[i][j]=(dp[i-1][j]+dp[i-1][j-1])%N;
			}
		}
		for(int i=0;i<n-2;i++){
			ans=(dp[n][i]+ans)%N;
		}
		cout<<ans;
		return 0;
	}
	sort(a,a+n);
	dfs(0,0,0,0);
	cout<<ans;
	return 0;
}

