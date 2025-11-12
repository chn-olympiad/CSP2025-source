#include<bits/stdc++.h>
#define inf 0x3f3f3f3f3f3f3f3f//T3£¬T4Ëã·¶Î§
#define int long long//T3£¬T4Ëã·¶Î§
#define endl '\n'
using namespace std;
const int maxn=1e4+5,maxm=1e6;
struct node
{
	int u,v,w,op;
	bool operator <(const node &a) const
	{
		return w<a.w;
	}
};
int fa[maxn+10],vis[maxn+10],c[maxn],a[15][maxn];
int get(int x)
{
	return fa[x]==x?x:fa[x]=get(fa[x]);
}
signed main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int n,m,k,ans=0;cin>>n>>m>>k;
	if(k==0)
	{
		set<node> s;
		for(int i=1;i<=m;i++)
		{
			int u,v,w;cin>>u>>v>>w;
			s.insert({u,v,w,0});
		}
		for(int j=1;j<=k;j++)
		{
			cin>>c[j];
			for(int i=1;i<=n;i++)
			{
				int x;cin>>x;
				a[j][i]=x;
				s.insert({j,i,x+c[j],1});
			}
		}
		for(int i=1;i<=n;i++) fa[i]=i;
		while(!s.empty())
		{
			int u=(*s.begin()).u,v=(*s.begin()).v,w=(*s.begin()).w,op=(*s.begin()).op;
			s.erase(s.begin());
			int fu=get(u),fv=get(v);
			if(fu!=fv)
			{
				fa[fu]=fv;
				ans+=w;
			}
		}
		cout<<ans;
	}
	else cout<<0;
	return 0;
}