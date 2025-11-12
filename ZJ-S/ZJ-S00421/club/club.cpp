#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll read()
{
	ll k=0,f=1;
	char c=getchar();
	while(!isdigit(c))
	{
		if(c=='-')f=-1;
		c=getchar();
	}
	while(isdigit(c))
	{
		k=(k<<1)+(k<<3)+(c^48);
		c=getchar();
	}
	return k*f;
}
const int N=1e5+10,M=220;
ll t,n,ans,num[5],p[5];
struct node
{
	ll a,b,c,mx,mmx,df;
}d[N];
bool cmp(node x,node y)
{
	return x.df>y.df;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	t=read();
	while(t--)
	{
		n=read();
		for(int i=1; i<=n; ++i)
		{
			d[i]={read(),read(),read(),0,0,0};
			d[i].mx=max(d[i].a,max(d[i].b,d[i].c));
		}
		for(int i=1; i<=3; ++i)num[i]=0;
		ans=0;
		for(int i=1; i<=n; ++i)
		{
			p[1]=d[i].a;p[2]=d[i].b;p[3]=d[i].c;
			sort(p+1,p+3+1);
			d[i].mmx=p[2];
			d[i].df=p[3]-p[2];
		}
		sort(d+1,d+n+1,cmp);
		for(int i=1; i<=n; ++i)
		{
			if(i<=n/2)
			{
				ans+=d[i].mx;
				if(d[i].a==d[i].mx)num[1]++;
				else if(d[i].b==d[i].mx)num[2]++;
				else if(d[i].c==d[i].mx)num[3]++;
			}
			else
			{
				if(d[i].a==d[i].mx&&num[1]<n/2)
				{
					ans+=d[i].mx;
					num[1]++;
				}
				else if(d[i].b==d[i].mx&&num[2]<n/2)
				{
					ans+=d[i].mx;
					num[2]++;
				}
				else if(d[i].c==d[i].mx&&num[3]<n/2)
				{
					ans+=d[i].mx;
					num[3]++;
				}
				else ans+=d[i].mmx;
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}