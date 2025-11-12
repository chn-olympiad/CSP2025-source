#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,k;
struct edge
{
	int u,v,w;
	bool operator < (const edge a) const
	{
		return w<a.w;
	}
}c[1000005],a[11][10015];
pair<int,int> w[10][10005];
int val[10],len[11];
struct union_find
{
	int fa[10025],sz[10025];
	void init(int n){for(int i=1;i<=n;i++)fa[i]=i,sz[i]=1;}
	int root(int x){return fa[x]==x?x:fa[x]=root(fa[x]);}
	void merge(int u,int v){u=root(u),v=root(v);if(u==v)return;if(sz[u]>sz[v])swap(u,v);fa[u]=v,sz[v]+=sz[u];}
}uf;
const int inf=0x3f3f3f3f3f3f3f3f;
int ans=inf;
void dfs(int pos,int sum)
{
	if(pos==k)
	{
		int tot=sum;
		for(int i=1;i<=len[k];i++)
			tot+=a[k][i].w;
		ans=min(ans,tot);
		return;
	}
	len[pos+1]=len[pos];
	for(int i=1;i<=len[pos];i++)
		a[pos+1][i]=a[pos][i];
	dfs(pos+1,sum);
	int p=1,q=1;
	uf.init(n+k);
	len[pos+1]=0;
	for(int i=1;i<=len[pos]+n;i++)
	{
		edge cur;
		if(p<=len[pos]&&(q>n||a[pos][p].w<w[pos][q].first))
			cur=a[pos][p],p++;
		else
			cur={n+pos+1,w[pos][q].second,w[pos][q].first},q++;
		if(uf.root(cur.u)!=uf.root(cur.v))
		{
			a[pos+1][++len[pos+1]]=cur;
			uf.merge(cur.u,cur.v);
		}
	}
	dfs(pos+1,sum+val[pos]);
}
signed main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
	{
		int u,v,w;
		cin>>u>>v>>w;
		c[i]={u,v,w};
	}
	sort(c+1,c+m+1);
	uf.init(n);
	int t=0;
	for(int i=1;i<=m;i++)
		if(uf.root(c[i].u)!=uf.root(c[i].v))
		{
			a[0][++t]=c[i];
			uf.merge(c[i].u,c[i].v);
		}
	len[0]=t;
	for(int i=0;i<k;i++)
	{
		cin>>val[i];
		for(int j=1;j<=n;j++)
			cin>>w[i][j].first,w[i][j].second=j;
		sort(w[i]+1,w[i]+n+1);
	}
	dfs(0,0);
	cout<<ans<<"\n";
}
//end at 15:18