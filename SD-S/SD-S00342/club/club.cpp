#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5+5;
ll T,n;
struct stu
{
	ll maxx,maxx2,minn;
}p[N];
struct st
{
	ll a1,b1;	
}k1[N],k2[N];
ll x[N][10],y[N];
ll ans;
bool cmp(const ll &a,const ll &b)
{
	return a>b;
}
bool cmp2(const st &a,const st &b)
{
	if(a.a1==b.a1)
		return a.b1>b.b1;
	return a.a1>b.b1;
}
bool cmp3(const st &a,const st &b)
{
	if(a.b1==b.b1)
		return a.a1>b.a1;
	return a.b1>b.b1;
}
ll ans2=0;
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%lld",&T);
	while(T--)
	{
		ans=0;
		scanf("%lld",&n);
		memset(p,0,sizeof p);
		memset(x,0,sizeof x);
		for(int i=1;i<=n;i++)
		{
			scanf("%lld%lld%lld",&x[i][1],&x[i][2],&x[i][3]);
			for(int j=1;j<=3;j++)
				if(x[i][j]==0)
					x[i][j+3]++;
			for(int j=1;j<=3;j++)
			{
				if(x[i][j]>x[i][p[i].maxx])
				{
					p[i].minn=p[i].maxx2;
					p[i].maxx2=p[i].maxx;
					p[i].maxx=j;
				}
				else
				{
					if(x[i][j]>x[i][p[i].maxx2])
					{
						p[i].minn=p[i].maxx2;
						p[i].maxx2=j;
					}
					else p[i].minn=j;
				}
			}
		}
		if(n==2)
		{
			if(p[1].maxx!=p[2].maxx) ans=x[1][p[1].maxx]+x[2][p[2].maxx];
			else 
			{
				ll cnt1=x[1][p[1].maxx]+x[2][p[2].maxx2];
				ll cnt2=x[1][p[1].maxx2]+x[2][p[2].maxx];
				ans=max(cnt1,cnt2);
			}
			printf("%lld\n",ans);
			continue;
		}
		bool f1=0,f2=0;
		for(int i=1;i<=n;i++)
		{
			if(!x[i][5]) f1=1;
			if(!x[i][6]) f2=1;
			if(f1&&f2) break;
		}
		if(f1==0&&f2==0)
		{
			for(int i=1;i<=n;i++) y[i]=x[i][1];
			sort(y+1,y+n+1,cmp);
			for(int i=1;i<=n/2;i++) ans+=y[i];
			printf("%lld\n",ans);
		}
		else 
		{
			for(int i=1;i<=n;i++)
			{
				k1[i].a1=x[i][1];
				k1[i].b1=x[i][2];
				k2[i].a1=x[i][1];
				k2[i].b1=x[i][2];
			}
			sort(k1+1,k1+n+1,cmp2);
			sort(k2+1,k2+n+1,cmp3);
			ll cnt1=0,cnt2=0;
			for(int i=1;i<=n;i++)
			{
				if(i<=n/2)
				{
					cnt1+=k1[i].a1;
					cnt2+=k2[i].b1; 
				}
				else 
				{
					cnt1+=k1[i].b1;
					cnt2+=k2[i].a1;
				}
			}
			ans=max(cnt1,cnt2);
			printf("%lld\n",ans);
		}
	}
	return 0;
}

 
