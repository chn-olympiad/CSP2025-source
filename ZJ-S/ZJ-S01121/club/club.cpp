#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e5+5;
struct st
{
	int a;int b;int c;int ma;int se;int f;
}d[N];
bool cmp1(st x,st y)
{
	return x.f>y.f;
}
bool cmp2(st x,st y)
{
	return abs(x.ma-x.se)>(y.ma-y.se);
}
int n,t,cnt,ans;
int cs[4];
signed main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int l=1;l<=t;l++)
	{
		cin>>n;ans=0;cnt=0;memset(cs,0,sizeof cs);
		for(int i=1;i<=n;i++)
		{
			cin>>d[i].a>>d[i].b>>d[i].c;d[i].f=0;d[i].ma=0;d[i].se=0;
			if(d[i].a>=d[i].b&&d[i].b>=d[i].c) d[i].ma=d[i].a,d[i].se=d[i].b;
			if(d[i].a>=d[i].c&&d[i].c>=d[i].b) d[i].ma=d[i].a,d[i].se=d[i].c;
			if(d[i].c>=d[i].b&&d[i].b>=d[i].a) d[i].ma=d[i].c,d[i].se=d[i].b;
			if(d[i].c>=d[i].a&&d[i].a>=d[i].b) d[i].ma=d[i].c,d[i].se=d[i].a;
			if(d[i].b>=d[i].a&&d[i].a>=d[i].c) d[i].ma=d[i].b,d[i].se=d[i].a;
			if(d[i].b>=d[i].c&&d[i].c>=d[i].a) d[i].ma=d[i].b,d[i].se=d[i].c;
		}
		for(int i=1;i<=n;i++)
		{
			if(d[i].ma==d[i].a) cs[1]++;
			if(d[i].ma==d[i].b) cs[2]++;
			if(d[i].ma==d[i].c) cs[3]++;
		}
		if(cs[1]<=n/2&&cs[2]<=n/2&&cs[3]<=n/2)
		{
			for(int i=1;i<=n;i++) ans+=d[i].ma;
		}
		else if(cs[1]>n/2)
		{
			for(int i=1;i<=n;i++)
			{
				if(d[i].ma!=d[i].a) d[i].f=0;
				else d[i].f=1,cnt++; 
			}
			sort(d+1,d+1+n,cmp1);
			sort(d+1,d+1+cnt,cmp2);
			for(int i=1;i<=n;i++)
			{
				if(d[i].f==0||i<=n/2) ans+=d[i].ma;
				else ans+=d[i].se;
			}
		}
		else if(cs[2]>n/2)
		{
			for(int i=1;i<=n;i++)
			{
				if(d[i].ma!=d[i].b) d[i].f=0;
				else d[i].f=1,cnt++;
			}
			sort(d+1,d+1+n,cmp1);
			sort(d+1,d+1+cnt,cmp2);
			for(int i=1;i<=n;i++)
			{
				if(d[i].f==0||i<=n/2) ans+=d[i].ma;
				else ans+=d[i].se;
			}
		}
		else if(cs[3]>n/2)
		{
			for(int i=1;i<=n;i++)
			{
				if(d[i].ma!=d[i].c) d[i].f=0;
				else d[i].f=1,cnt++;
			}
			sort(d+1,d+1+n,cmp1);
			sort(d+1,d+1+cnt,cmp2);
			for(int i=1;i<=n;i++)
			{
				if(d[i].f==0||i<=n/2) ans+=d[i].ma;
				else ans+=d[i].se;
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}