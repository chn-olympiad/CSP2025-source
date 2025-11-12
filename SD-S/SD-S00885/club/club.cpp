#include <iostream>
#include <cstring>
#include <cstdio>
#include <stdio.h>
using namespace std;
int st[100005][4];
int check[4];
int ans=0;
int n,h;
void dfs(int cnt,int myd)
{
	if(cnt==n+1)
	{
		ans=max(ans,myd);
		return ;
	}
	for(int i=1;i<=3;i++)
	{
		if(check[i]+1<=h)
		{
			check[i]++;
			dfs(cnt+1,myd+st[cnt][i]);
			check[i]--;
		}
	}
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	scanf("%d",&t);
	while(t--)
	{
		ans=0;
		memset(st+1,0,sizeof(st));
		scanf("%d",&n);
		h=n/2;
		for(int i=1;i<=n;i++)
		{
			scanf("%d%d%d",&st[i][1],&st[i][2],&st[i][3]);
		}
		dfs(1,0);
		printf("%d",ans);
		printf("%c",'\n');
	}
	return 0;
}
