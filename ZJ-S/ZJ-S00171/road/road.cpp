#include<bits/stdc++.h>
using namespace std;
#define il inline
#define fi first
#define se second
#define mk make_pair
#define eb emplace_back
#define rep(i,l,r) for(int i=(l); i<=(r); ++i)
#define rep_(i,l,r) for(int i=(l); i>=(r); --i)
typedef long long lr;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef vector<int> vi;
template<typename T>il T Max(T x,T y) { return x>y? x:y; }
template<typename T>il T Min(T x,T y) { return x<y? x:y; }
constexpr int N=10100,M=1000100;
struct edge { int x,y,z,id; };
edge e0[M],e[N*11];
il bool operator <(const edge &X,const edge &Y) { return X.z<Y.z; }
int n,m,k,c[11],a[11][N],fa[N],sz[N];
il int Find(int u) { return fa[u]==u? u:fa[u]=Find(fa[u]); }
il void Merge(int x,int y) { sz[x]<sz[y]? (fa[x]=y,sz[y]+=sz[x]):(fa[y]=x,sz[x]+=sz[y]); }
il void Solve()
{
	cin>>n>>m>>k;
	rep(i,1,m)
		cin>>e0[i].x>>e0[i].y>>e0[i].z,e0[i].id=0;
	sort(e0+1,e0+1+m);
	rep(i,1,n)
		fa[i]=i,sz[i]=1;
	lr ans=0; int cnt=0;
	rep(i,1,m)
		if(Find(e0[i].x)!=Find(e0[i].y))
			e[++cnt]=e0[i],ans+=e0[i].z,Merge(Find(e0[i].x),Find(e0[i].y));
	rep(j,1,k)
	{
		cin>>c[j];
		rep(i,1,n)
		{
			int z; cin>>z;
			e[++cnt]=(edge){n+j,i,z,j};
		}
	}
	sort(e+1,e+1+cnt);
	rep(j,1,(1<<k)-1)
	{
		rep(i,1,n+k)
			fa[i]=i,sz[i]=1;
		lr s=0;
		rep(i,1,k)
			if(j&1<<i-1)
				s+=c[i];
		rep(i,1,cnt)
			if(!e[i].id||j&1<<e[i].id-1)
				if(Find(e[i].x)!=Find(e[i].y))
					s+=e[i].z,Merge(Find(e[i].x),Find(e[i].y));
		ans=Min(ans,s);
	}
	cout<<ans<<'\n';
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int T=1;
	while(T--)
		Solve();
	return 0;
}