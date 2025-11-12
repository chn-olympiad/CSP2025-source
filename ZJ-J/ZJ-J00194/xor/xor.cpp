#include <bits/stdc++.h>
#define int long long
using namespace std;
int n,k,b[500010],sum,a[500010],i,j,ans,t,w,val,dp[500010][3];
signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>k;
	for(i=1;i<=n;i++)
		cin>>a[i],ans+=a[i];
	if(n<=2&&k==0&&ans==n){
		if(n==1) cout<<0,exit(0);
		else cout<<1,exit(0);
	}
	if(ans==n&&k==0&&n<=100){
		cout<<n/2;return 0;
	}
	if(n<=200000&&k<=1&&ans<=n){
		if(k==0){
			a[0]=20;a[n+1]=20;
			for(i=1;i<=n;i++){
				if(a[i-1]==1&&a[i]==1) sum++,i++;
				if(a[i]==0) sum++;
			}
			cout<<sum;return 0;
		}
		else{
			for(i=1;i<=n;i++)
				if(a[i]==1) sum++;
			cout<<sum;return 0;
		}
	}
	dp[0][1]=dp[0][0]=0;
	for(i=1;i<=n;i++){
		dp[i][0]=max(dp[i-1][1],dp[i-1][0]);
		if(dp[i-1][0]>=1||dp[i-1][1]>=1){
			if((a[i]^k)==k) dp[i][1]=max(dp[i-1][0],dp[i-1][1])+1;
			else dp[i][1]=dp[i][0];
		}
		else{
			if(a[i]==k) dp[i][1]=dp[i][0]+1;
			else if(val^a[i]==k) dp[i][1]=dp[i][0]+1;
			else val^=a[i];
		}
	}
	cout<<max(dp[n][0],dp[n][1]);
	return 0;
}

