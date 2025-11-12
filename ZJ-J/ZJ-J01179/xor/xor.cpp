#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m,a[500005],pr[500005] = {0};
ll cnt[500005],dp[500005];
bool need[22],flag;
int main()
{
	freopen("xor.in","r",stdin); 
	freopen("xor.out","w",stdout); 
	cin>>n>>m;
	for(int i = 1;i <= n;i++)
	{
		cin>>a[i];
		pr[i] = pr[i-1] ^ a[i];
	}
	for(int i = 1;i <= n;i++)
	{
		if(a[i]==m)
			dp[i] = dp[i-1]+1;
		else
		{
			for(int j = i-1;j > 0 && dp[j] == dp[i-1];j--)
			{
				if((pr[i]^pr[j-1])==m)
				{
					dp[i] = max(dp[i],dp[j-1]+1);
					break;
				}
			}
			dp[i] = max(dp[i],dp[i-1]);
		}
	}
	cout<<dp[n];
	return 0;
}
