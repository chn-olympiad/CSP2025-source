#include<bits/stdc++.h>
using namespace std;
int t;
int n;
int a[10005][3];
long long maxpleasure,good;
int b[4] = {0,0,0,0};
void dfs(int diyi,int dier)
{
	if(diyi>n)
	{
		return;
	}
	for(int s = 1;s<=3;s++)
	{
		if(b[s]>n/2)
		{
			return;
		}
	}
	++b[dier];
	good = good + a[diyi][dier];
	if(good>maxpleasure)
	{
		maxpleasure = good;
	}	
	if(dier == 1)
	{
		dfs(diyi+1,dier);
		--b[dier];
		good-=a[diyi][dier];
		return;
		dfs(diyi+1,dier+1);
		--b[dier];
		good-=a[diyi][dier];
		return;
		dfs(diyi+1,dier+2);
		--b[dier];
		good-=a[diyi][dier];
		return;
	}
	if(dier == 2)
	{
		dfs(diyi+1,dier-1);
		--b[dier];
		good-=a[diyi][dier];
		return;
		dfs(diyi+1,dier);
		--b[dier];
		good-=a[diyi][dier];
		return;
		dfs(diyi+1,dier+1);
		--b[dier];
		good-=a[diyi][dier];
		return;
	}
	if(dier == 3)
	{
		dfs(diyi+1,dier-2);
		--b[dier];
		good-=a[diyi][dier];
		return;
		dfs(diyi+1,dier-1);
		--b[dier];
		good-=a[diyi][dier];
		return;
		dfs(diyi+1,dier);
		--b[dier];
		good-=a[diyi][dier];
		return;
	}

	
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	
	scanf("%d",&t);
	for(int i = 1;i<=t;i++)
	{
		scanf("%d",&n);
		for(int i = 1;i<=n;i++)
		{
			int q,w,e;
			scanf("%d %d %d",&q,&w,&e);
			for(int j = 1;j<=3;j++)
			{
				if(i == 1) a[i][j] = q;
				if(i == 2) a[i][j] = w;
				if(i == 3) a[i][j] = e;
			}
		}
		dfs(1,1);
		dfs(1,2);
		dfs(1,3);
		printf("%lld\n",maxpleasure);
		maxpleasure = 0;
		b[1] = 0;
		b[2] = 0;
		b[3] = 0;
	}
	return 0;
}
