#include<bits/stdc++.h>
using namespace std;
long long n,a[500010],k;
int dp[500010];
int f(int x,int y)
{
	long long l;
	if(x==y)
	return k==a[x];
	else
	{
		l=a[x]^a[x+1];
		for(int i=x+1;i<y;i++)
		{
			l^=a[i+1];
		}
		if(l==k)
		return 1;
		else
		return 0;
	}
}
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	dp[1]=(k==a[1]);
	for(int i=2;i<=n;i++)
	{
		for(int j=0;j<i;j++)
		{
			dp[i]=max(dp[i],dp[j]+f(j+1,i));
		}
	}
	cout<<dp[n];
	return 0;
}
