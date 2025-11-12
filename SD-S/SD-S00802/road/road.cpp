#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=3e6+6;
struct node
{
	ll from,to;
	double val;
};
const int M=1e4+4;
ll jv[M][M];
node a[N];
ll cnt;
ll fa[N];
void add_(ll f,ll t,ll va)
{
	a[++cnt].from=f;
	a[cnt].to=t;
	a[cnt].val=va;
}
bool cmp(node x,node y)
{
	return x.val<y.val;
}
ll find(ll now)
{
	return fa[now]=(fa[now]==now?now:find(fa[now]));
}
void add(ll x,ll y)
{
	x=find(x);
	y=find(y);
	fa[x]=y;
}
void Init(ll k)
{
	for (ll i = 1;i <= k;i++)
	{
		fa[i]=i;
	}
	return ;
}
ll cun[N];
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ll n,m,k;
	scanf("%lld%lld%lld",&n,&m,&k);
	Init(n+1); 
	for (ll i = 1;i <= n;i++)
	{
		for (ll j = 1;j <= n;j++)
		{
			jv[i][j]=0x3f3f3f3f;
		}
	}
	if (k==0)
	{
		for (ll i = 1;i <= m;i++)
		{
			ll u,v,w;
			scanf("%lld%lld%lld",&u,&v,&w);
			add_(u,v,w);
		}
	}
	else
	{
		for (ll i = 1;i <= m;i++)
		{
			ll u,v,w;
			scanf("%lld%lld%lld",&u,&v,&w);
			jv[u][v]=min(jv[u][v],w);
			jv[v][u]=min(jv[v][u],w);
		}
		for (ll i = 1;i <= k;i++)
		{
			ll cw;
			scanf("%lld",&cw);
			for (ll j = 1;j <= n;j++)
			{
				scanf("%lld",&cun[j]);
			}
			for (ll i = 1;i <= n;i++)
			{
				for (ll j = 1;j <= n;j++)
				{
					if (i!=j)
					{
					//	cout << "." << jv[i][j] << ":" << cw+cun[i]+cun[j] << ":"; 
						jv[i][j]=min(jv[i][j],cw+cun[i]+cun[j]);
						jv[j][i]=min(jv[j][i],cw+cun[i]+cun[j]);
					//	cout << jv[i][j] << "."; 
					} 
				}
			}
		}
		for (ll i = 1;i <= n;i++)
		{
			for (ll j = 1;j < i;j++)
			{
				add_(i,j,jv[i][j]);
				
			}
			
		}
	}
	
	sort(a+1,a+cnt+1,cmp);
	ll num=0;
	ll ans=0;
	for (ll i = 1;i <= cnt;i++)
	{
		if (find(a[i].from)!=find(a[i].to))
		{
			add(a[i].from,a[i].to);
			num++;
			ans+=a[i].val;
		}
		if (num==n-1)
		{
			break;
		}
	}
	printf("%lld",ans);
//	cout << " " << num;
	return 0;
}

