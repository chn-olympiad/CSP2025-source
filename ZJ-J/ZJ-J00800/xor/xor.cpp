#include<bits/stdc++.h>
using namespace std;
long long int n,a[500010],k,cnt=0,dp[500010][2],ans;
struct qj
{
	int l,r;
}b[500010];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		long long num=a[i];
		for(int j=i;j<=n;j++)
		{
			if(j!=i)
			{
				num=num^a[j];
			}
			if(num==k)
			{
				cnt++;
				b[cnt].l=i;
				b[cnt].r=j;
			}
		}
	}
	dp[1][1]=1;
	for(int i=2;i<=cnt;i++)
	{
		for(int j=i-1;j>=1;j--)
		{
			if(b[j].r<b[i].l)
			{
				dp[i][1]=max(dp[i][1],dp[j][1]+1);
			}
		}
	}
	for(int i=1;i<=cnt;i++)
	{
		for(int j=0;j<=1;j++)
		{
			ans=max(ans,dp[i][j]);
		}
	}
	cout<<ans;
	return 0;
 } 
