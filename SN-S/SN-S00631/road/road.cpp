//SN-S00631 ΩØ”ÍÍÿ 
#include<bits/stdc++.h>
#define ll long long 
#define maxn 10005 
using namespace std;
struct node {ll x,y,v;};
ll n,m,k,f[maxn],ans,c[maxn],a[20][maxn];
vector<node> edge,q;
ll find(ll now) {if(f[now]==now) return now; return f[now]=find(f[now]);}
bool cmp(node x,node y) {return x.v<y.v;}
int main()
{
	ios::sync_with_stdio(false); cin.tie(0);
	freopen("road.in","r",stdin); freopen("road.out","w",stdout);
	cin>>n>>m>>k; for(int i=1;i<=n;i++) f[i]=i;
	for(int i=1;i<=m;i++)
	{
		ll u,v,w; cin>>u>>v>>w;
		node t; t.x=u; t.y=v; t.v=w;
		edge.push_back(t);
	}
	for(int i=1;i<=k;i++)
	{
		cin>>c[i]; for(int j=1;j<=n;j++) cin>>a[i][j];
	}
	sort(edge.begin(),edge.end(),cmp);
	for(auto i:edge)
	{
		if(find(i.x)==find(i.y)) continue;
		f[find(i.x)]=find(i.y);
		ans+=i.v; q.push_back(i);
	}
	vector<node> p=q;
	for(int i=1;i<(1<<k);i++)
	{
		ll sum=0;
		for(int j=0;j<k;j++) if((1<<j)&i) sum+=c[j+1];
		for(int j=0;j<k;j++) if((1<<j)&i)
		{
			for(int t=1;t<=n;t++)
			{
				node tt; tt.x=n+j+1; tt.y=t; tt.v=a[j+1][t];
				q.push_back(tt);
			}
		}
		sort(q.begin(),q.end(),cmp);
		for(int j=1;j<=n+k;j++) f[j]=j;
		for(auto j:q)
		{
			if(find(j.x)==find(j.y)) continue;
			f[find(j.x)]=find(j.y);
			sum+=j.v; if(sum>=ans) break;
		}
		ans=min(ans,sum); q=p;
	}
	cout<<ans;
	return 0;
}
