#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int mod=998244353; 
int n;
ll dp[5010][5010];//5001 means more than 5000
ll ans;
int a[5010];
signed main(){//finish at around 10:00
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	dp[0][0]=1ll;
	for(int i=1;i<=n;i++){
		int p=i-1;
		for(int j=a[i]+1;j<=5001;j++){
			ans+=dp[p][j];
			ans%=mod;
		}
		for(int j=0;j<=5001;j++) dp[i][j]=dp[p][j]%mod;
		for(int j=0;j<=5001;j++){
			dp[i][min(j+a[i],5001)]+=dp[p][j];
			dp[i][min(j+a[i],5001)]%=mod;
		}
	}
	cout<<ans%mod;
	return 0;
}
