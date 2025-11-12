#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
struct s
{
	int ans,maxx,all;
};
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n;
	cin>>n;
	vector<int> a(n);
	for (int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	vector<s> dp(n,{0,0,0});
	dp[n-1]={0,a[n-1],a[n-1]};
	for (int i=n-2;i>=0;i--)
	{
		if (i==n-2)
		{
			dp[i]={0,max(a[i],dp[i+1].maxx),a[i]+dp[i+1].all};
		}
		else
		{
			dp[i]={0,max(a[i],dp[i+1].maxx),a[i]+dp[i+1].all};
			for (int j=i+1;j<n-1;j++)
			{
				if (a[i]+dp[j].all>max(a[i],dp[j].maxx)*2)
				{
					dp[i].ans+=dp[j].ans+1;
				}
			}
		}
	}
	cout<<dp[0].ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}