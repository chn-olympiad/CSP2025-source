#include<bits/stdc++.h>
using namespace std;
long long n,k,a[500001],f[1001][1001],dp[500001],ans;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++){
		f[i][i]=a[i];
		for(int j=i+1;j<=n;j++){
			f[i][j]=f[i][j-1]^a[j];
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++)dp[j]=max(dp[j],dp[j-1]);
		for(int j=i;j<=n;j++){
			if(f[i][j]==k)dp[j]=max(dp[j],dp[i-1]+1);
		}
	}
	for(int i=1;i<=n;i++)ans=max(ans,dp[i]);
	cout<<ans;
	return 0;
}
