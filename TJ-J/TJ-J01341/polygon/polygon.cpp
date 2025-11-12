#include <bits/stdc++.h>
using namespace std;
const int p=998244353;
int n;
int a[5005];
int dp[5005];
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+n+1);
	int ans=0;
	dp[0]=1;
	for(int i=1;i<=n;i++)
	{
		for(int j=a[i]+1;j<=5001;j++)
			ans=(ans+dp[j])%p;
		for(int j=5001;j>=0;j--)
		{
			int k=j+a[i];
			if(k>5001)
				k=5001;
			dp[k]=(dp[k]+dp[j])%p;
		}
	}
	cout<<ans;
	return 0;
}
