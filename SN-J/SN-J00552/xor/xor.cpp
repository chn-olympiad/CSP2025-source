#include<bits/stdc++.h>
using namespace std;
int n,k,a[500010],ans;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++) cin>>a[i];
	if(k==1)
	{
		for(int i=1;i<=n;i++)
		{
			if(a[i]) ans++;
		}
		cout<<ans<<'\n';
		return 0;
	}
	else if(!k)
	{
		for(int i=1;i<=n;i++)
		{
			if(!a[i]) ans++;
			else if(a[i]==1&&a[i+1]==1) ans++,i++;
		}
		cout<<ans<<'\n';
		return 0;
	}
//	int b[500010],c[500010],dp[500010];
//	for(int i=1;i<=n;i++)
//	{
//		int x=0;
//		for(int j=i;j<=n;j++)
//		{
//			x^=a[j];
//			if(x==k)
//			{
//				b[i]=j;
//				break;
//			}
//		}
//	}
//	for(int i=1;i<=n;i++)
//	{
//		dp[i]=dp[i-1];
//		for(int j=1;j<=i;j++)
//		{
//			if(b[j]<=i&&b[j])
//			{
//				dp[i]=max(dp[i],dp[j]+1);
//			}
//		}
//	}
//	cout<<dp[n]<<'\n';
	return 0;
}
