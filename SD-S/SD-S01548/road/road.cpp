#include<iostream>
#include<queue>
#include<string.h>
#include<vector>
#include<algorithm>

using namespace std;
const int N=1e4+10;
typedef long long ll;
ll read()
{
	ll x=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9')
	{
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9')
	{
		x=x*10+ch-'0';
		ch=getchar();
	}

	return x*f;
}
ll n,m,k;
struct edge{
	ll to,w;
};
bool b[N];
vector<edge>g[N];
queue<ll>q;
struct Edge{
	int u,v,w;
}e[1050005],e2[1000005];
bool cmp(Edge x,Edge y)
{
	return x.w<y.w;
}
ll fa[N];
ll find(ll x)
{
	if(fa[x]==x)return x;
	return fa[x]=find(fa[x]);
}

ll mn=1e9;
ll kruskal(ll tot)
{
	sort(e+1,e+1+tot,cmp);
	for(ll i=1;i<=n+k;i++)
	{
		fa[i]=i;
	}
	ll ans=0;
	for(ll i=1;i<=tot;i++)
	{
		ll x=e[i].u,y=e[i].v;
		ll u=find(x),v=find(y);
		if(u!=v)
		{
			
			fa[u]=v;
			ans+=1ll*e[i].w;
			//cout<<x<<' '<<y<<' '<<e[i].w<<'\n';
		}
	}
	return ans;
}
ll a[10][N];
ll c[N];
void dfs(ll cc)
{
	if(cc==k+1)
	{
		ll cnt=0,sum=0;
		for(ll i=1;i<=n;i++)
		{
			if(b[i]==1)
			{
				sum+=c[i];
				for(ll j=1;j<=n;j++)
				{
					cnt++;
					//cout<<m+cnt<<'\n';
					e[m+cnt]={n+i,j,a[i][j]};
					
				}
			}
		}
		//cout<<'%';
		for(ll i=1;i<=m;i++)
		{
			e[i]=e2[i];
		}
//		for(ll i=1;i<=m+cnt;i++)
//		{
//			cout<<e[i].u<<' '<<e[i].v<<' '<<e[i].w<<'\n';
//		}
		//cout<<'&';
		//cout<<kruskal(m+cnt)+sum<<'\n';
		mn=min(mn,kruskal(m+cnt)+sum);
		//cout<<'\n';
		return ;
	}


	b[cc]=0;
	dfs(cc+1);
	b[cc]=1;
	dfs(cc+1);
}


int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n=read(),m=read(),k=read();
	for(ll i=1;i<=m;i++)
	{
		ll u,v,w;
		u=read(),v=read(),w=read();
		e[i]={u,v,w};
		e2[i]={u,v,w};
	}
	for(ll i=1;i<=k;i++)
	{
		c[i]=read();
		for(ll j=1;j<=n;j++)
		{
			a[i][j]=read(); 
		}
	}
	if(k==0)
	{
		cout<<kruskal(m)<<'\n'; 
		return 0;
	}
	else if(k<=5)
	{
		dfs(1);
		cout<<mn<<'\n';
	}
	return 0;
}


