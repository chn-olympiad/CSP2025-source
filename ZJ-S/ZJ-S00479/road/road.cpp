#include<bits/stdc++.h>
#define F(i,l,r) for(int i=(l),i##end=(r);i<=i##end;++i)
#define G(i,l,r) for(int i=(l),i##end=(r);i>=i##end;--i)
#define ep emplace_back
#define mp make_pair
#define pii pair<int,int>
#define x first
#define y second
#define ll long long
using namespace std;
constexpr int M=1e6+9,N=1e4+19;
struct node
{
	int x,y,w;
	bool operator<(const node&A)const
	{
		return w<A.w;
	}
}a[M],ed[N*20];
namespace dsu
{
	int fa[N];
	void init()
	{
		memset(fa,-1,sizeof fa);
	}
	int find(int x){return fa[x]<0?x:fa[x]=find(fa[x]);}
	bool merge(int x,int y)
	{
		if((x=find(x))==(y=find(y)))return false;
		if(fa[x]>fa[y])swap(x,y);
		fa[x]+=fa[y];
		fa[y]=x;
		return true;
	}
}
int c[20];
int vis[20];
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin.tie(0)->sync_with_stdio(false);
	int n,m,K;
	cin>>n>>m>>K;
	F(i,1,m)cin>>a[i].x>>a[i].y>>a[i].w;
	int tot=0;
	sort(a+1,a+m+1);
	dsu::init();
	F(i,1,m)if(dsu::merge(a[i].x,a[i].y))ed[++tot]=a[i];
	F(i,1,K)
	{
		int x;
		cin>>c[i-1];
		F(j,1,n)
		{
			cin>>x;
			ed[++tot]=node{i+n,j,x};
		}
	}
	sort(ed+1,ed+tot+1);
	ll ans=1e18;
	F(msk,0,(1<<K)-1)
	{
		ll tmp=0;
		F(j,0,K-1)if(msk>>j&1)tmp+=c[j];
		F(j,0,K-1)vis[j+1]=msk>>j&1;
		dsu::init();
		F(i,1,tot)if((ed[i].x<=n||vis[ed[i].x-n])&&dsu::merge(ed[i].x,ed[i].y))tmp+=ed[i].w;
	//	cerr<<tmp<<'\n';
		ans=min(ans,tmp);
	}
	cout<<ans<<'\n';
	return 0;
}
