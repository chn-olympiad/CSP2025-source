#include<bits/stdc++.h>
using namespace std;
int n,k,ans,a[500005],b[500005],c[500005],dp[500005];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=n;i>=1;i--)
		b[i]=(b[i+1]^a[i]);
	for(int i=n;i>=1;i--)
		for(int j=n+1;j>i;j--)
			if((b[i]^b[j])==k)
				dp[i]=max(dp[i],dp[j]+1);
	for(int i=1;i<=n;i++)
		ans=max(ans,dp[i]);
	cout<<ans;
	return 0;
}
