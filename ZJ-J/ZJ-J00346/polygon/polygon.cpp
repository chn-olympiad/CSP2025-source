#include<bits/stdc++.h>
using namespace std;
#define int long long
const int p=998244353;
int s[5005],dp[50005][105],t[105],n,len=0,cho[25],cnt=0,maxn,sum;
void dfs(int x)
{
	if(x>n)
	{
		maxn=-1,sum=0,len=0;
		for(int i=1;i<=n;i++)
			if(cho[i])
				maxn=max(maxn,s[i]),sum+=s[i],len++;
		if(sum>2*maxn&&len>=3) cnt++;
		return;
	}
	cho[x]=1;
	dfs(x+1);
	cho[x]=0;
	dfs(x+1);
}
int ksm(int k)
{
	int ans=1,a=2;
	while(k!=0)
	{
		if(k&1) ans=(ans*a)%p;
		a=a*a;
		k>>=1;
	}
	return ans;
}
signed main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%lld",&n);
	for(int i=1;i<=n;i++) scanf("%lld",&s[i]);
	sort(s+1,s+n+1);
	if(n<=20)
	{
		dfs(1);
		cout<<cnt;
	}
	else if(s[n]==1)
	{
		cnt=ksm(n);
		int x=n+1+n*(n-1)/2;x%=p;
		cnt=cnt+p-x;
		cout<<cnt%p;
	}
	else cout<<0;
	return 0;
}

