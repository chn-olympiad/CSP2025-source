#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define gc getchar()
#define pll pair<ll,ll>
#define pb push_back
#define id second
#define val first
const ll maxm=2e6+1010,maxn=2e5+1010,mod=998244353,INF=1e18+1010;
inline void read(ll &x)
{
	x=0;char ch=gc;
	while(ch<'0'||ch>'9')ch=gc;
	while(ch>='0'&&ch<='9')x=(x<<1)+(x<<3)+(ch^48),ch=gc;
}
ll n,m,k,to,ans;
ll fa[maxn];
struct Edge
{
	ll x,y,v;
}e[maxm];
vector<ll> v[maxn];
vector<pll> mt[maxn];
vector<ll> ne;
ll c[15],a[15][maxn];
priority_queue<pll,vector<pll>,greater<pll> > q;
bitset<15> ado; 
ll find(ll p)
{
	if(fa[p]==p)return p;
	return fa[p]=find(fa[p]);
}
void dfs1(ll x,ll pre,ll co)//problem
{
	fa[x]=co;
	for(int i=0;i<mt[x].size();i++)
	{
		if(mt[x][i].id==pre)continue;
		dfs1(mt[x][i].id,x,co);
	}
}
void dfs2(ll x,ll pre)
{
	//printf("%lld\n",x);
	for(int i=0;i<mt[x].size();i++)
	{
		if(mt[x][i].id==pre||(mt[x][i].id>100000&&ado[mt[x][i].id-100000]==0))continue;
		dfs2(mt[x][i].id,x);
	}
	for(int i=0;i<v[x].size();i++)
	{
		to=e[v[x][i]].x;
		if(to==x)to=e[v[x][i]].y;
		if(fa[to]!=fa[x])
		{
			q.push({e[v[x][i]].v,v[x][i]});
		}
	}
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	read(n);read(m);read(k);
	for(int i=1;i<=n;i++)fa[i]=i;
	for(int i=100001;i<=100000+k;i++)fa[i]=i;
	//printf("%lld\n",fa[100001]);
	for(int i=1;i<=m;i++)
	{
		read(e[i].x);read(e[i].y);read(e[i].v);
		v[e[i].x].pb(i);v[e[i].y].pb(i);
		q.push({e[i].v,i});
	}
	for(int i=1;i<=k;i++)
	{
		read(c[i]);
		for(int j=1;j<=n;j++)
		{
			read(a[i][j]);
			m++;
			e[m].x=j;e[m].y=100000+i;e[m].v=a[i][j];
			v[j].pb(100000+i);
			v[100000+i].pb(j);
			q.push({e[m].v,m});
		}
	}
	while(!q.empty())
	{
		pll tmp=q.top();
		q.pop();
		//printf("%lld %lld %lld\n",tmp.id,find(e[tmp.id].x),find(e[tmp.id].y));
		if(find(e[tmp.id].x)==find(e[tmp.id].y))continue;
		else
		{
		    //printf("%lld %lld\n",e[tmp.id].x,e[tmp.id].y);
			//siz++;
			fa[find(e[tmp.id].x)]=find(e[tmp.id].y);
			mt[e[tmp.id].x].pb({e[tmp.id].v,e[tmp.id].y});
			mt[e[tmp.id].y].pb({e[tmp.id].v,e[tmp.id].x});
			ans+=e[tmp.id].v;
		}
	}
	//printf("%lld\n",ans);
	for(int i=1;i<=k;i++)ado[i]=1,ans+=c[i];
	//printf("%lld\n",ans);
	for(int i=100001;i<=100000+k;i++)
	{
		ne.clear();
		//printf("%lld\n",i);
		if(mt[i].size()==1)
		{
			ans-=mt[i][0].val;
			ans-=c[i-100000];
			ado[i]=0;
			//printf("2\n");
		}
		else
		{
			//printf("3\n");
			ll neans=ans-c[i-100000];
			//printf("%lld\n",mt[i].size());
			for(int j=0;j<mt[i].size();j++)neans-=mt[i][j].val;
			
			for(int j=0;j<mt[i].size();j++)dfs1(mt[i][j].id,i,mt[i][j].id);//printf("%lld\n",ans);
			//for(int j=1;j<=n;j++)printf("%lld\n",fa[j]);
			for(int j=0;j<mt[i].size();j++)dfs2(mt[i][j].id,i);
			while(!q.empty())
			{
				pll tmp=q.top();
				q.pop();
				//printf("%lld\n",tmp.id);
				if(find(e[tmp.id].x)==find(e[tmp.id].y))continue;
				else
				{
					//siz++;
					fa[find(e[tmp.id].x)]=find(e[tmp.id].y);
					ne.pb(tmp.id);
					neans+=e[tmp.id].v;
				}
				//printf("%lld\n",q.size());
			}	
			//printf("%lld\n",neans);
			if(neans<ans)
			{
				ans=neans;
				for(int j=0;j<ne.size();j++)
				{
					mt[e[ne[j]].x].pb({e[ne[j]].v,e[ne[j]].y});
					mt[e[ne[j]].y].pb({e[ne[j]].v,e[ne[j]].x});
				}
			}
			else ado[i]=0;
			
		}
	}
	printf("%lld\n",ans);
	return 0;
}
