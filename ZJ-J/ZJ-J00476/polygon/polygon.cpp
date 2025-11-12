#include<bits/stdc++.h>
using namespace std;
int n,a[25],ans;
void dfs(int dep,int maxx,int sum)
{
	if(dep>n)
	{
		if(sum>maxx*2)ans++;
		return;
	}
	dfs(dep+1,max(maxx,a[dep]),sum+a[dep]);
	dfs(dep+1,maxx,sum);
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",a+i);
	}
	dfs(1,0,0);
	printf("%d",ans);
	return 0;
}