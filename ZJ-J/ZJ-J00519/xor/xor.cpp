/*
把long long换成long long
开freopen
去#define 
*/
#include <bits/stdc++.h>
using namespace std;
long long n,m;
long long a[500005];
long long s[500005];
long long l;
struct NODE
{
	long long l,r;
//	bool operator <(const NODE t) const
//	{
//		if(l^t.l) return l<t.l;
//		return r<t.r;
//	}
} ans[500005];
long long dp[500005];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for(long long i=1;i<=n;i++) 
	{
		cin>>a[i];
		s[i] = s[i-1]^a[i];
	}
	if(n<=1000)
	{
		for(long long i=1;i<=n;i++)
		{
			for(long long j=i;j<=n;j++)
			{
				if((s[j]^s[i-1])==m)
				{
					ans[++l] = {i,j};
					break;
				}
			}
		}
//		for(long long i=1;i<=l;i++) cout<<ans[i].l<<" "<<ans[i].r<<"\n";
		for(long long i=1;i<=l;i++)
		{
			for(long long j=n+1;j>ans[i].r;j--)
			{
				dp[j] = max(dp[j],dp[ans[i].l]+1);
			}
		}
//		for(long long i=1;i<=n+1;i++) cout<<dp[i]<<" ";
		cout<<dp[n+1];
	}
	else 
	{
		long long ans = 0;
		for(long long i=1;i<=n;i++) 
		{
			if(a[i]==m) ans++;
		}
		cout<<ans;
	}
    return 0;
}
//2^20 = 2e6

