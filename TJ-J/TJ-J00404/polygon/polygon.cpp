#include <bits/stdc++.h>
using namespace std;
long long n,stick[5005],ans;
bool vis[5005];
const long long MOD = 998244353;
void dfs(long long step,long long sum,long long maxn,long long num)
{
	if(step == num)
	{
		if(sum > 2 * maxn)
		{
			ans++;
			ans %= MOD;
		}
		return;
	}
	for(int i = 1;i <= n;i++)
	{
		if(!vis[i])
		{
			vis[i] = true;
			dfs(step + 1,sum + stick[i],max(maxn,stick[i]),num);
			vis[i] = false;
//			vis[i] = true;
//			dfs(step + 1,sum + stick[i],max(maxn,stick[i]),num);
//			dfs(step,sum,maxn,num);
		}
	}
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%lld",&n);
	for(int i = 1;i <= n;i++)
	{
		scanf("%lld",&stick[i]);
	}
	for(long long num = 3;num <= n;num++)
	{
		memset(vis,false,sizeof(vis));
		dfs(0ll,0ll,0ll,num);
	}
	printf("%lld",ans % MOD);
	return 0;
}
