#include<bits/stdc++.h>
using namespace std;

int n,tot;
int a[5009];
bool flag[5009]={0};
int chose[5009];
unsigned long long ans=0;

void dfs(int cnt,int last_pos)
{
	if(cnt==tot)
	{
		int sum=0,mx=0;
		for(int i=1;i<=tot;i++)
		{
			sum += chose[i];
			if(chose[i]>mx) mx=chose[i];
		}
		if(sum>2*mx) ans++;
		return;
	}
	for(int i=last_pos+1;i<=n;i++)
	{
		if(flag[i]) continue;
		chose[cnt+1] = a[i];
		flag[i] = 1;
		dfs(cnt+1,i);
		flag[i] = 0;
	}
}

int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
	}
	for(tot=3;tot<=n;tot++) dfs(0,0);
	ans %= 998244353;
	printf("%d",ans);
	return 0;
}
