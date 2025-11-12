#include<bits/stdc++.h>//368346,ciallo
using namespace std;
#define ll long long
#define fre(a) freopen(#a".in","r",stdin),freopen(#a".out","w",stdout)
const ll maxn=10009;
const ll maxm=1000009;
ll n,m,k;
struct edge{
	ll u,v,w;
}s[maxm],a[maxm<<1],h[maxm];
ll p[19][maxn],c[19],ans=9e18,cnt,fa[maxn],siz[maxn],sum,cntpoint,num;
bool cmp(edge s1,edge s2)
{
	return s1.w<s2.w;
}
void init()
{
	sum=0,cnt=0,cntpoint=n,num=0;
	for(ll i=1;i<=n;i++)
	{
		fa[i]=i;
		siz[i]=1;
	}
}
ll find(ll x)
{
	if(fa[x]==x)
	{
		return x;
	}
	return fa[x]=find(fa[x]);
}
void solve()
{
	ll i1=1,i2=1,a1,a2;
	for(ll i=1;i<=m+cnt;i++)
	{
		if(i1!=m+1)
		{
			a1=s[i1].w; 
		}
		else
		{
			a1=9e18;
		}
		if(i2!=cnt+1)
		{
			a2=h[i2].w;
		}
		else
		{
			a2=9e18;
		}
		if(a1<a2)
		{
			a[i]=s[i1];
			i1++;
		}
		else
		{
			a[i]=h[i2];
			i2++;
		}
	}
}
int main()
{
	fre(road);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m>>k;
	for(ll i=1;i<=m;i++)
	{
		cin>>s[i].u>>s[i].v>>s[i].w;
	}
	sort(s+1,s+m+1,cmp);
	for(ll i=1;i<=k;i++)
	{
		cin>>c[i];
		for(ll j=1;j<=n;j++)
		{
			cin>>p[i][j];
		}
	}
	for(ll mask=0;mask<(1<<k);mask++)
	{
		init();
		for(ll i=1;i<=k;i++)
		{
			if((1<<(i-1))&mask)
			{
				cntpoint++;
				sum+=c[i];
				fa[i+n]=i+n;
				siz[i+n]=1;
				for(ll j=1;j<=n;j++)
				{
					cnt++;
					h[cnt].u=i+n;
					h[cnt].v=j;
					h[cnt].w=p[i][j];
				}
			}
		}
		sort(h+1,h+cnt+1,cmp);
		solve();
		for(ll i=1,x,y,z,fx,fy;i<=cnt+m;i++)
		{
			if(num==cntpoint-1||sum>ans)
			{
				break;
			}
			x=a[i].u;
			y=a[i].v;
			z=a[i].w;
			fx=find(x);
			fy=find(y);
			if(fx==fy)
			{
				continue;
			}
			if(siz[fx]<siz[fy])
			{
				swap(fx,fy);
			}
			siz[fx]+=siz[fy];
			fa[fy]=fx;
			sum+=z;
			num++;
		}
		ans=min(ans,sum);
	}
	cout<<ans;
	return 0;
}
