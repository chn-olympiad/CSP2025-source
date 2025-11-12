//SN-J00497 李中易 西安辅轮中学
#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=500010;

int n,k,a[maxn],flag[2000010],dp[maxn],now;

int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	memset(flag,-1,sizeof(flag));
	flag[0]=0;
	cin>>n>>k;
	for(int i=1;i<=n;i++)  cin>>a[i];
	for(int i=1;i<=n;i++)
	{
		now^=a[i];
		int need=now^k;
		dp[i]=dp[i-1];
		if(flag[need]==-1)
		{
			flag[now]=i;
			continue;
		}
		dp[i]=max(dp[i],dp[flag[need]]+1);
		flag[now]=i;
	}
	cout<<dp[n];
	return 0;
} 
