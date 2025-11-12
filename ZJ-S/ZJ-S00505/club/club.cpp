#include<bits/stdc++.h>
using namespace std;
int t,n,s[3];
long long ans;
struct node{
	int b,c,d;
	bool e,f,g;
	int delta;
}a[100010];
bool cmp(node x,node y)
{
	return x.delta>y.delta;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	while(t--)
	{
		memset(s,0,sizeof(s));
		ans=0;
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
		{
			scanf("%d%d%d",&a[i].b,&a[i].c,&a[i].d);
			int p[3];
			p[0]=a[i].b,p[1]=a[i].c,p[2]=a[i].d;
			sort(p,p+3);
			a[i].delta=p[2]-p[1];
			a[i].e=a[i].f=a[i].g=0;
			if(a[i].b==p[2])a[i].e=1;
			if(a[i].c==p[2])a[i].f=1;
			if(a[i].d==p[2])a[i].g=1;
		}
		sort(a+1,a+n+1,cmp);
		for(int i=1;i<=n;i++)
		{
			if(a[i].e&&s[0]<(n/2))
			{
				ans+=a[i].b;
				s[0]++;
				continue;
			}
			if(a[i].f&&s[1]<(n/2))
			{
				ans+=a[i].c;
				s[1]++;
				continue;
			}
			if(a[i].g&&s[2]<(n/2))
			{
				ans+=a[i].d;
				s[2]++;
				continue;
			}
			if(a[i].e)
			{
				if(a[i].c>=a[i].d)
				{
					ans+=a[i].c;
					s[1]++;
				}
				else
				{
					ans+=a[i].d;
					s[2]++;
				}
			}
			else if(a[i].f)
			{
				if(a[i].b>=a[i].d)
				{
					ans+=a[i].b;
					s[0]++;
				}
				else
				{
					ans+=a[i].d;
					s[2]++;
				}
			}
			else
			{
				if(a[i].b>=a[i].c)
				{
					ans+=a[i].b;
					s[0]++;
				}
				else
				{
					ans+=a[i].c;
					s[1]++;
				}
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}
