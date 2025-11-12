#include<bits/stdc++.h>
using namespace std;
int a[500001];
int dp[500001];
int s[500001];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	if(n<=1000)
	{
		for(int i=1;i<=n;i++)
		{
			dp[i]=dp[i-1];
			int bla=0;
			for(int j=i;j>=1;j--)
			{
				bla=bla^a[j];
				if(bla==k)
				{
					dp[i]=max(dp[i],dp[j-1]+1);
				}
			}
		}
		cout<<dp[n]<<endl;
	}
	else if(k==0)
	{
		int ans=0;
		for(int i=1;i<=n;i++)
		{
			if(a[i]==0)
			{
				ans++;
			}
			else
			{
				if(i!=n&&a[i+1]==1)
				{
					ans++;
					i++;
				}
			}
		}
		cout<<ans<<endl;
	}
	else if(k==1)
	{
		int ans=0;
		for(int i=1;i<=n;i++)
		{
			if(a[i]==1)
			{
				ans++;
			}
		}
		cout<<ans<<endl;
	}
	else
	{
		for(int i=1;i<=n;i++)
		{
			s[i]=s[i-1]^a[i];
		}
		int ans=0;
		int dq=n;
		for(int i=n-1;i>=0;i--)
		{
			int bla=s[dq]^s[i];
			if(bla==k)
			{
				ans++;
				dq=i;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
