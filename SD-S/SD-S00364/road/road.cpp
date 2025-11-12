#include<bits/stdc++.h>
#define i64 long long
#define u64 unsigned long long
#define prs " \n"
#define iinf 0x3f3f3f3f
using namespace std;
const int N=1e4+20,M=1e6+10;
int n,m,k,cnt,c[N],cu[N],cf[M],a[11][N],f[N],mas;
vector<pair<int,int>> e[N];
bitset<N> b;
//1:最小生成树
struct edge
{
	int u,v,w;
};
vector<edge> es;
bool cmp(edge oa,edge ob)
{
	return oa.w<ob.w;
}
int finds(int o)
{
	return f[o]==o?o:f[o]=finds(f[o]);
}
void kruskal()
{
	for(edge i:es)
	{
		int fu=finds(i.u);
		int fv=finds(i.v);
		if(fu==fv) continue;
		if(fu>fv) swap(fu,fv);
		f[fu]=fv;
		cnt+=!b[i.u];
		cnt+=!b[i.v];
		b[i.u]=b[i.v]=1;
		mas+=i.w;
		if(cnt==n) return;
	}
}
int main()
{
 	freopen("road1.in","r",stdin);
 	freopen("road1.out","w",stdout);
	cin.tie(0)->sync_with_stdio(0);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++)
		f[i]=i;
	while(m--)
	{
		int u,v,w;
		cin>>u>>v>>w;
		e[u].push_back({v,w});
		e[v].push_back({u,w});
		es.push_back({u,v,w});
	}
	for(int i=1;i<=k;i++)
	{
		cin>>c[i];
		for(int j=1;j<=n;j++)
			cin>>a[i][j];
	}
	for(int o=1;o<=k;o++)
	{
		if(c[o]) continue;
		for(int i=1;i<=n;i++)
			for(int j=1;j<=i;j++)
				if(i!=j)
					es.push_back({i,j,a[o][i]+a[o][j]});
	}
	sort(es.begin(),es.end(),cmp);
	kruskal();
	for(int i=1;i<=k;i++)
	{
		int tp=0;
		for(edge j:es)
			tp+=(a[i][j.u]+a[i][j.v]-j.w);
		if(tp+c[i]>0) continue;
		for(int q=0;q<es.size();q++)
		{
			edge j=es[q];
			if(j.w>a[i][j.u]+a[i][j.v])
			{
				if(cf[q]) cu[cf[q]]--;
				j.w=a[i][j.u]+a[i][j.v];
				cu[i]++,cf[q]=i;
			}
		}
		mas+=tp;
	}
	cout<<mas<<'\n';
	for(int i=1;i<=k;i++)
		mas-=c[i]*(cu[i]>0);
	cout<<mas;
	return 0;
}

