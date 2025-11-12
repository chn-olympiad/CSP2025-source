#include <bits/stdc++.h>
using namespace std;
const int MOD=998244353;
int n,a[5010],dp[5010];
int ans,flag;
inline void dfs(int x,int s,int t){
	if (x>n) return;
	dfs(x+1,s,t);
	if (t>=2&&s>a[x]) {++ans;ans%=MOD;}
	dfs(x+1,s+a[x],t+1); 
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for (int i=1;i<=n;++i){
		cin>>a[i];
		if (a[i]!=1) flag=1;
	}
	if (flag==0){
		dp[3]=1;
		for (int i=4;i<=n;++i) dp[i]=((2*dp[i-1])%MOD+ ( (i-2)*(i-1)/2 )%MOD )%MOD;
		cout<<dp[n];
	}
	else if (n<=20){
		sort(a+1,a+n+1);
		dfs(1,0,0);
		cout<<ans%MOD;
	}
	return 0;
}
