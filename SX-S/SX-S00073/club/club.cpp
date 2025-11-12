#include <bits/stdc++.h>
using namespace std;
long long t,n,num[20],ans;
struct l2{
	long long s,p;
};
struct l3{
	l2 a[20];
}d[100010];
int cmp1(l2 x,l2 y)
{
	return x.s>y.s;
}
int cmp2(l3 x,l3 y)
{
	return x.a[1].s-x.a[2].s>y.a[1].s-y.a[2].s;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%lld",&t);
	while(t--)
	{
		memset(num,0,sizeof(num));
		ans=0;
		scanf("%lld",&n);
		for(int i=1;i<=n;i++)
		{
			scanf("%lld%lld%lld",&d[i].a[1].s,&d[i].a[2].s,&d[i].a[3].s);
			d[i].a[1].p=1;
			d[i].a[2].p=2;
			d[i].a[3].p=3;
			sort(d[i].a+1,d[i].a+4,cmp1);
		}
		sort(d+1,d+n+1,cmp2);
		for(int i=1;i<=n;i++)
		{
			if(num[d[i].a[1].p]<n/2)
			{
				ans+=d[i].a[1].s;
				num[d[i].a[1].p]++;
			}
			else
			{
				ans+=d[i].a[2].s;
				num[d[i].a[2].p]++;
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}