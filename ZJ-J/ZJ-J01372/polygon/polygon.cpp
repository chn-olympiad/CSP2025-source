#include<bits/stdc++.h>
using namespace std;
const long long M=998244353;
int n,a[5010];
bool f;
long long cnt;
void dfs(int x,long long sum,int maxx)
{
	if(x==n+1)
	{
		if(sum>maxx*2) cnt++;
		cnt%=M;
		return ;
	}
	dfs(x+1,sum+a[x],a[x]);
	dfs(x+1,sum,maxx);
	return ;
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",a+i);
		if(a[i]!=1) f=1;
	}
	if(!f)
	{
		for(int i=3;i<=n;i++)
			cnt=(cnt+(n-i+1))%M;
		printf("%lld",cnt%M);
		return 0;
	}
	sort(a+1,a+n+1);
	dfs(1,0,0);
	printf("%lld",cnt%M);
	return 0;
}
