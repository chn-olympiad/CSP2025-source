#include<bits/stdc++.h>
#include<cstdio>
using namespace std;
int T,n;
long long a[100010][4],b[4],ll[100010],ans;
struct node
{
	long long l,ma;
}c[100010];
inline int read()
{
	int x=0,f=1;
	char c=getchar();
	while (c<'0'||c>'9')
	{
		if (c=='-') f=-1;
		c=getchar();
	}
	while (c>='0'&&c<='9')
	{
		x=x*10+c-'0';
		c=getchar();
	}
	return x*f;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	T=read();
	while (T--)
	{
		ans=0;
		long long j=0,cnt=0;
		n=read();
		for (int i=1;i<=3;i++) b[i]=0;
		for (int i=1;i<=n;i++)
		{
			scanf("%lld%lld%lld",&a[i][1],&a[i][2],&a[i][3]);
			int m1,m2,m3;
			m1=max(a[i][1],max(a[i][2],a[i][3]));
			m3=min(a[i][1],min(a[i][2],a[i][3]));
			m2=a[i][1]+a[i][2]+a[i][3]-m1-m3;
			c[i].l=m1-m2;
			if (a[i][1]==m1) c[i].ma=1;
			else if (a[i][2]==m1) c[i].ma=2;
			else c[i].ma=3;
			ans+=m1;
			b[c[i].ma]++;
		}
		for (int i=1;i<=3;i++)
		{
			if (b[i]*2>n)
			{
				j=i;
				break;
			}
		}
		if (j==0)
		{
			cout<<ans<<endl;
			continue;
		}
		for (int i=1;i<=n;i++)
		{
			if (c[i].ma==j) ll[++cnt]=c[i].l;
		}
		sort(ll+1,ll+cnt+1);
		for (int i=1;i<=cnt-n/2;i++) ans-=ll[i];
		cout<<ans<<endl;
	}
	return 0;
}
