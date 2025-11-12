#include <bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int n,k;
int a[N],dp[N],num[N];
int ans,sum;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	bool flaga=1,flagb=1;
	for (int i=1;i<=n;i++)
	{
		cin>>a[i];
		if (a[i]!=1)flaga=0;
		if (a[i]!=1 && a[i]!=0)flagb=0;
	}
	if (flaga)
	{
		cout<<n/2;
		return 0;
	}
	if (flagb)
	{
		for (int i=1;i<=n;i++)
		{
			sum^=a[i];
			if (sum==k)
			{
				ans++;
				sum=0;
			}
			else if (a[i]==k)
			{
				sum=0;
				ans++;
			}
		}
		cout<<ans;
		return 0;
	}	
	for (int l=1;l<=n;l++)
	{
		sum=a[l];
		int r=l;
		while(sum!=k && r<n)
		{
			r++;
			sum^=a[r];
		}
		if (sum!=k)r=0;
		num[r]=max(l,num[r]);
	}
	for (int i=1;i<=n;i++)
	{
		for (int j=0;j<num[i];j++)dp[i]=max(dp[i],dp[j]+1);
		ans=max(ans,dp[i]);
	}
	cout<<ans;
	return 0;
}
