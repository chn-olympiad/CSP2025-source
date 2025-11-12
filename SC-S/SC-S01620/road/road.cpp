#include<bits/stdc++.h>
#define fopen(FNAME) freopen(FNAME".in","r",stdin);freopen(FNAME".out","w",stdout);
using namespace std;
using ll=long long;
using PII=pair<int,int>;
using PLL=pair<ll,ll>;
using PLI=pair<ll,int>;
mt19937_64 UL(time(0));
const int N=1e4+9,mod=1e9+7;
int n,m,p,k,T=1;
int fa[N],sze[N];
int find(int x)
{
	if(fa[x]==x)return x;
	return find(fa[x]);
}
bool merge(int x,int y)
{
	int fx=find(x),fy=find(y);
	if(fx==fy)return 0;
	if(sze[fx]>sze[fy])swap(fx,fy);
	fa[fx]=fy;
	sze[fy]+=sze[fx];
	return 1;
}
struct EDGE{
	int u,v,w,ulock;
};
int ulock_w[N];
vector<EDGE > r;
bool cmp(EDGE x,EDGE y)
{
	return x.w<y.w;
}
ll ans=0;
void solve_k0()
{
	sort(r.begin(),r.end(),cmp);
	int cnt=1;
	for(auto x:r)
	{
		int u=x.u,v=x.v,w=x.w;
		if(merge(u,v))
		{
//			cout<<u<<' '<<v<<' '<<w<<'\n';
			ans+=w;
			cnt++;
		}
		if(cnt==n)break;
	}
	cout<<ans<<"\n";
}
void solve_l0()
{
	sort(r.begin(),r.end(),cmp);
	int cnt=1;
	for(auto x:r)
	{
		int u=x.u,v=x.v,w=x.w;
		if(merge(u,v))
		{
//			cout<<u<<' '<<v<<' '<<w<<'\n';
			ans+=w;
//			if(u<=n&&v<=n)cnt++;
		}
		if(cnt==n)break;
	}
	cout<<ans<<"\n";
}
void solve(int tcase)
{
	//要 ll
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++)
	{
		fa[i]=i;
		sze[i]=1;
	}
	for(int i=1;i<=m;i++)
	{
		int u,v,w;
		cin>>u>>v>>w;
		r.push_back({u,v,w,-1});
	}
	if(k==0)
	{
		solve_k0();
		return;
	}	
	for(int i=0;i<m;i++)
	{
		cin>>ulock_w[i];
		for(int v=1;v<=n;v++)
		{
			int u=n+i+1,w;
			cin>>w;
//			r.push_back({u,v,w,i});
		}
	}
	solve_k0();
}
int main(	)
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	fopen("road");
//	cin>>T;
	for(int i=1;i<=T;i++)
	{
		solve(i);
	}
	return 0;
}