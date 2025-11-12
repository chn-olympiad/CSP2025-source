#include<bits/stdc++.h>
using namespace std;
#define int long long
struct edge
{
	int u,v,w;
}in[1000005];
int n,m,k,c[1005],fa[1005],a[15][1005],ans;
bool o;
bool cmd(edge x,edge y){
	return x.w<y.w;
}
int find(int x)
{
	if(fa[x]==x)	return x;
	return fa[x]=find(fa[x]);
}
bool merge(int x,int y)
{
	int fx=find(x),fy=find(y);
	if(fx==fy)	return 0;
	fa[fy]=fx;
	return 1;
}
void kruskal()
{
	for(int i=1;i<=m;i++)
		if(merge(in[i].u,in[i].v))
			ans+=in[i].w;
	return;
}
signed main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++)	fa[i]=i;
	for(int i=1;i<=m;i++)	cin>>in[i].u>>in[i].v>>in[i].w;
	sort(in+1,in+n+1,cmd);
	for(int i=1;i<=k;i++)
	{
		bool nowo=0;
		cin>>c[i];
		nowo|=(c[i]!=0);
		for(int j=1;j<=n;j++)
		{
			cin>>a[i][j];
			nowo|=(a[i][j]!=0);
		}
		o|=(!nowo);
	}
	if(o)
	{
		cout<<"0\n";
		return 0;
	}
	kruskal();
	cout<<ans<<"\n";
	return 0;
}