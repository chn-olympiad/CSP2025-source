#include<bits/stdc++.h>
using namespace std;
int n;
const int N=100010;
struct node
{
	int a[5];
}ed[N],ed1[N];
bool cmp1(node a,node b)
{
	return a.a[1]>b.a[1];
}
bool operator<(node a,node b)
{
	return max(a.a[1],a.a[2])<max(b.a[1],b.a[2]);
}
int num[5],ret=0;
void dfs(int now,int cnt)
{
	if(now==n+1)ret=max(ret,cnt);
	for(int i=1;i<=3;i++)if(num[i]<n/2)
	{
		num[i]++;
		dfs(now+1,cnt+ed[now].a[i]);
		num[i]--;
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
		scanf("%d",&n);
		int f2=0,f3=0;
		for(int i=1;i<=n;i++)
		{
			scanf("%d%d%d",&ed[i].a[1],&ed[i].a[2],&ed[i].a[3]);
			if(ed[i].a[2]!=0)f2=1;
			if(ed[i].a[3]!=0)f3=1;
		}
		if(f2==0&&f3==0)
		{
			int ans=0;
			sort(ed+1,ed+n+1,cmp1);
			for(int i=1;i<=n/2;i++)
			{
				ans+=ed[i].a[1];
			}
			printf("%d\n",ans);
			break;
		}
		ret=0;
		dfs(1,0);
		printf("%d\n",ret);
	}
	return 0;
}
