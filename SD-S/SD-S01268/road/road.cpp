#include<bits/stdc++.h>
using namespace std;
#define ll long long
typedef pair<ll,ll> pii;
const int N=1e4+10;
const int M=2e7+10;
const int NN=1e3+10;
ll a[20][N],c[N],e[NN][NN];
int f[N],ct;
ll cnt;
bool flagc;
int find(int x)
{
	if(f[x]!=x)f[x]=find(f[x]);
	return f[x];
}
struct node
{
	int a,b;
	ll c;
}p[M];
bool cmp(node x,node y)
{
	return x.c<y.c;
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	cin>>n>>m>>k;
	if(n<=1000)memset(e,0x3f,sizeof e);
	for(int i=1;i<=m;i++)
	{
		int a,b;
		ll c;
		scanf("%d%d%lld",&a,&b,&c);
		if(n<=1000)e[a][b]=e[b][a]=min(e[a][b],c);
		p[i]={a,b,c};
	}
	for(int i=1;i<=k;i++)
	{
		scanf("%lld",&c[i]);
		if(c[i])flagc=1;
		for(int j=1;j<=n;j++)
		{
			scanf("%lld",&a[i][j]);
		}
	}
	if(!k)
	{
		ll ans=0;
		for(int i=1;i<=n;i++)f[i]=i;
		sort(p+1,p+1+m,cmp);
		for(int i=1;i<=m;i++)
		{
			int dx=find(p[i].a),dy=find(p[i].b);
			if(dx!=dy)
			{
				ct++;
				f[dx]=dy;
				ans+=p[i].c;
				if(ct==n-1)break;
			}
		}
		printf("%lld",ans);
		return 0;
	}
	if(!flagc)
	{
		cnt=m;
		for(int i=1;i<=k;i++)
		{
			for(int j=1;j<=n;j++)
			{
				for(int k=j+1;k<=n;k++)
				{
					if(a[i][j]+a[i][k]>=e[i][j])continue;
					p[++cnt]={j,k,a[i][j]+a[i][k]};
				}
			}
		}
		ll ans=0;
		for(int i=1;i<=n;i++)f[i]=i;
		sort(p+1,p+1+cnt,cmp);
		for(int i=1;i<=cnt;i++)
		{
			int dx=find(p[i].a),dy=find(p[i].b);
			if(dx!=dy)
			{
				ct++;
				f[dx]=dy;
				ans+=p[i].c;
				if(ct==n-1)break;
			}
		}
		printf("%lld",ans);
		return 0;
	}
	return 0;
}
