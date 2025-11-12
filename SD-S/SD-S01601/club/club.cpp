#include <bits/stdc++.h> 
using namespace std;
int n,t;
struct ff{
	int a;
	int b;
	int c;
}d[100005];
int cmpa(ff p,ff q)
{
	return p.a>q.a;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	while(t--)
	{
		int k=0,pa=0,pb=0,pc=0,ans=0,f=0;
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
		{
			scanf("%d %d %d",&d[i].a,&d[i].b,&d[i].c);
			if(d[i].b!=0&&d[i].c!=0)
			{
				f=1;
			}
		}
		sort(d+1,d+n+1,cmpa);
		if(n==2)
		{
			ans=max(d[1].a+max(d[2].b,d[2].c),d[2].a+max(d[2].b,d[2].c));
			ans=max(ans,max(d[1].b+max(d[2].a,d[2].c),d[2].b+max(d[2].a,d[2].c)));
			ans=max(ans,max(d[1].c+max(d[2].a,d[2].b),d[2].c+max(d[2].a,d[2].b)));
			printf("%d\n",ans);
		}
		else if(f==0)
		{
			for(int i=1;i<=n;i++)
			{
				if(pa<n/2)
				{
					ans+=d[i].a;
					pa++;
				}
			}
			printf("%d\n",ans);
		}
		else
		{
			for(int i=1;i<=n;i++)
			{
				ans+=max(d[i].c,max(d[i].a,d[i].b));
			}
			printf("%d\n",ans);
		}
	}
	return 0;
}
