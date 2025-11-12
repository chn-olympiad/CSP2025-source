#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=5000+5,inf=998244353;
int l[N],sum[N],dp[N];
signed main() {
	ios::sync_with_stdio(0);
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
		dp[i]=(dp[i-1]+i)%inf;
	for(int i=1;i<=n;i++){
		cin>>l[i];
		sum[i]=sum[i-1]+l[i];
	}
	if(l[n]<=1){
		cout<<dp[n];
		return 0;
	}
	int ans=0;
	for(int i=4;i<=n;i++)
		for(int j=1;j<=i-2;j++)
			if(sum[i]-sum[j-1]>l[i]*2) ans=(ans%inf+dp[n-i+1])%inf;
	cout<<ans;
	return 0;
}
