#include<bits/stdc++.h>
#define int long long
#define f(i,x,y) for(register int i=x;i<=y;++i)
#define d(i,x,y) for(register int i=x;i>=y;--i)
using namespace std;
const int MAXN=5e5+1;
int n,k,dp[MAXN],sum[MAXN];
map<int,vector<int> >sa;
signed main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>k;
	sa[0].push_back(0);
	f(i,1,n)
	{
		int x;
		cin>>x;
		sum[i]=(sum[i-1]^x);
		sa[sum[i]].push_back(i);
	}
	f(i,1,n)
	{
		dp[i]=dp[i-1];
		for(int j:sa[(sum[i]^k)])
			if(j>=i)break;
			else dp[i]=max(dp[i],dp[j]+1);
	}
	cout<<dp[n];
	return 0;
}
