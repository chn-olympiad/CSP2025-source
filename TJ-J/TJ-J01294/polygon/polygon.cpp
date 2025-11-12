#include <iostream>
#include <cstdio>
using namespace std;
int cnt = 0;
int a[5010];
int n;
bool vis[5010];
void dfs(int step,int g,int maxn,long long sum)
{
	if(step>n)
	{
		if(g>=3)
		{
			cnt+=(sum>1ll*maxn*2);
		}
		return ;
	}
	if(step>n) return ;
	vis[step] = 0;
	dfs(step+1,g,maxn,sum);
	vis[step] = 1;
	dfs(step+1,g+1,max(maxn,a[step]),sum+a[step]);
	vis[step] = 0;
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		cin >> a[i];
	}
	dfs(1,0,-1e9,0);
	printf("%d",cnt);
	return 0;
}
