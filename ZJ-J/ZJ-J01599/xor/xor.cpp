#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+1;
int n,k;
int a,sum[N];
int dp[N];
signed main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>k;
	for(int i=1;i<=n;++i) cin>>a,sum[i]=a^sum[i-1];
	for(int i=1;i<=n;++i)
	{
		dp[i]=dp[i-1];
		for(int j=i;j>=0;--j)			
			if((sum[i]^sum[j-1])==k){dp[i]=max(dp[i],dp[j-1]+1);break;}
	}
//	for(int i=1;i<=n;++i) cout<<sum[i]<<" ";
//	cout<<"\n";
//	for(int i=1;i<=n;++i) cout<<dp[i]<<" ";
//	cout<<"\n";
	cout<<dp[n];
}
