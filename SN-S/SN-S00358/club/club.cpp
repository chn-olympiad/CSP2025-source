#include<bits/stdc++.h>
using namespace std;
int t,n,a1[100010],a2[100010],a3[100010];
long long ans;
bool f2=1,f3=1;
inline void dfs(int f1,int f2,int f3,int x,long long sum)
{
	if(x==n+1)
	{
		ans=max(ans,sum);
		return;
	}
	if(f1<n/2) dfs(f1+1,f2,f3,x+1,sum+a1[x]);
	if(f2<n/2) dfs(f1,f2+1,f3,x+1,sum+a2[x]);
	if(f3<n/2) dfs(f1,f2,f3+1,x+1,sum+a3[x]);
	return;
}
inline void dfs1(int f1,int f2,int x,long long sum)
{
	if(x==n+1)
	{
		ans=max(ans,sum);
		return;
	}
	if(f1<n/2) dfs1(f1+1,f2,x+1,sum+a1[x]);
	if(f2<n/2) dfs1(f1,f2+1,x+1,sum+a2[x]);
	return;
}
inline bool cmp(int x,int y)
{
	return x>y;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		ans=0;
		for(int i=1;i<=n;i++)
		{
			scanf("%d%d%d",&a1[i],&a2[i],&a3[i]);
			if(a2[i]&&f2) f2=0;
			if(a3[i]&&f3) f3=0;
		}
		if(f2&&f3)
		{
			sort(a1+1,a1+1+n,cmp);
			for(int i=1;i<=n/2;i++) ans+=a1[i];
		}
		else if(f3) dfs1(0,0,0,0);
		else dfs(0,0,0,0,0);
		printf("%d\n",ans);
	}
	return 0;
}
