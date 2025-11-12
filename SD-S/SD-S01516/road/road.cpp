#include<bits/stdc++.h>
using namespace std;
#define int long long
bool startmb;
constexpr int N=1e4+55,M=1e6+5,K=15;
	double starttime=clock();
int n,m,k,a[K],to[K][N],mplace[N];

struct Node{int u,v,w;}edge[M<<1],b[M<<1],c[M<<1];

bool vis[N],cyc[K][N];

int fa[N],sze[N];
int ask(int a){return fa[a]==a?a:fa[a]=ask(fa[a]);}
void merge(int u,int v)
{
	u=ask(u),v=ask(v);
	if(u==v) return ;
	if(sze[u]>sze[v]) swap(u,v);
	fa[u]=v,sze[v]+=sze[u];
}

namespace solve1
{
	bool check(){return k<=5;}
	int cnt[(1<<15)+5],ans=LLONG_MAX;
	void msort(int n)
	{
		for(int i=0;i<1<<15;i++) cnt[i]=0;
		for(int i=1;i<=n;i++) cnt[c[i].w&32767]++;
		for(int i=1;i<1<<15;i++) cnt[i]+=cnt[i-1];
		for(int i=n;i>=1;i--) b[cnt[c[i].w&32767]--]=c[i];

		for(int i=0;i<1<<15;i++) cnt[i]=0;
		for(int i=1;i<=n;i++) cnt[(b[i].w>>15)&32767]++;
		for(int i=1;i<1<<15;i++) cnt[i]+=cnt[i-1];
		for(int i=n;i>=1;i--) c[cnt[(b[i].w>>15)&32767]--]=b[i];
	}
	void solve()
	{
		for(int s=0;s<1<<k;s++)
		{
			int num=0,tot=m;
			for(int i=1;i<=m;i++) c[i]=edge[i];
			for(int i=0;i<k;i++) if((s>>i)&1)
			{
				num+=a[i+1];
				for(int j=1;j<=n;j++) c[++tot]=Node{n+i+1,j,to[i+1][j]};
			}
			msort(tot);
			for(int i=1;i<=n+k;i++) fa[i]=i,sze[i]=1;
//			for(int i=1;i<=tot;i++) cout<<c[i].w<<' ';cout<<'\n';
			for(int i=1;i<=tot;i++) if(ask(c[i].u)!=ask(c[i].v)) merge(c[i].u,c[i].v),num+=c[i].w;
			ans=min(ans,num);
		}
		cout<<ans;
	}
}
namespace solve2
{
	bool check()
	{
		for(int i=1;i<=k;i++)
		{
			if(a[i]!=0) return 0;
			bool flag=0;
			for(int j=1;j<=n;j++) if(to[i][j]==0) flag=1;
			if(!flag) return 0;
		}
		return 1;
	}
	void solve()
	{
		int tot=m;
		for(int i=1;i<=k;i++)
		{
			for(int j=1;j<=n;j++)
			{
				if(to[i][j]==0)
				{
					for(int k=1;k<=n;k++) edge[++tot]=Node{j,k,to[i][k]};
					break;
				}
			}
		}
		for(int i=1;i<=n;i++) fa[i]=i;
		sort(edge+1,edge+tot+1,[](Node a,Node b){return a.w<b.w;});
		int ans=0;
		for(int i=1;i<=tot;i++) if(ask(edge[i].u)!=ask(edge[i].v)) merge(edge[i].u,edge[i].v),ans+=edge[i].w;
		cout<<ans;
	}
}
namespace solve
{
	bool vis[(1<<10)+5];
	int cnt[(1<<15)+5],ans=LLONG_MAX;
	void msort(int n)
	{
		for(int i=0;i<1<<15;i++) cnt[i]=0;
		for(int i=1;i<=n;i++) cnt[c[i].w&32767]++;
		for(int i=1;i<1<<15;i++) cnt[i]+=cnt[i-1];
		for(int i=n;i>=1;i--) b[cnt[c[i].w&32767]--]=c[i];

		for(int i=0;i<1<<15;i++) cnt[i]=0;
		for(int i=1;i<=n;i++) cnt[(b[i].w>>15)&32767]++;
		for(int i=1;i<1<<15;i++) cnt[i]+=cnt[i-1];
		for(int i=n;i>=1;i--) c[cnt[(b[i].w>>15)&32767]--]=b[i];
	}
	void solve()
	{
		do
		{
			int s=rand()%(1<<k);
			while(vis[s]) s=rand()%(1<<k);
			int num=0,tot=m;
			for(int i=1;i<=m;i++) c[i]=edge[i];
			for(int i=0;i<k;i++) if((s>>i)&1)
			{
				num+=a[i+1];
				for(int j=1;j<=n;j++) c[++tot]=Node{n+i+1,j,to[i+1][j]};
			}
			msort(tot);
			for(int i=1;i<=n+k;i++) fa[i]=i,sze[i]=1;
//			for(int i=1;i<=tot;i++) cout<<c[i].w<<' ';cout<<'\n';
			for(int i=1;i<=tot;i++) if(ask(c[i].u)!=ask(c[i].v)) merge(c[i].u,c[i].v),num+=c[i].w;
			ans=min(ans,num);
		}
		while((clock()-starttime)/CLOCKS_PER_SEC<0.95);
		cout<<ans;
	}
}

bool endmb;
main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cerr<<((&endmb-&startmb)/1024.0/1024)<<'\n';
	cin.tie(0)->sync_with_stdio(false);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++) cin>>edge[i].u>>edge[i].v>>edge[i].w;
	for(int i=1;i<=k;i++)
	{
		cin>>a[i];
		for(int j=1;j<=n;j++) cin>>to[i][j];
	}
	if(solve1::check()) solve1::solve();
	else if(solve2::check()) solve2::solve();
	else solve::solve();
	cerr<<((clock()-starttime)/CLOCKS_PER_SEC)<<'\n';
	return 0;
}
//多测要清空
//测极端数据
//注意数组大小
//注意保留小数位数

