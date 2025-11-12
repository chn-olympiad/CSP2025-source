#include <bits/stdc++.h>
#define endl '\n'
//#define int ll
#define inline
#define sh short
#define fi first
#define se second
#define db double
#define ldb long db
#define ll long long
#define ull unsigned ll
#define PII pair<int,int>
#define fopen(x) frein(x),freout(x)
#define fix(x) fixed<<setprecision(x)
#define frein(x) freopen(#x".in","r",stdin)
#define daout(x) freopen(#x".in","w",stdout)
#define freout(x) freopen(#x".out","w",stdout)
#define freans(x) freopen(#x".ans","w",stdout)
#define adde(u,v,w) e[++edge_cnt]={u,v,w,head[u]},head[u]=edge_cnt
#define fre(i,u,to) for(int i=head[u],to=e[i].v;i;i=e[i].nex,to=e[i].v)
#define gc() (p1==p2&&(p2=(p1=buf)+fread(buf,1,fread_cnt,stdin),p1==p2)?EOF:*p1++)

using namespace std;

mt19937 rnd(chrono::system_clock::now().time_since_epoch().count());
const int fread_cnt=1<<20;
const int mod=1e9+7;
const int MN=1e4+20;
const int MM=2e6+10;
//const ll inf=1e18;
const int inf=2e9;

char buf[fread_cnt],*p1=buf,*p2=buf;

template<typename T=int>
inline T read()
{
	T x=0;bool f=0;char ch=gc();
	while(ch<'0'||ch>'9')f^=ch=='-',ch=gc();
	while(ch>='0'&&ch<='9')x=(x<<1)+(x<<3)+(ch^48),ch=gc();
	return f?-x:x;
}

ll ans;
int n,m,k,cnt,
dis[MN],
c[MN],a[20][MN],
in[MN],out[MN],
head[MN],edge_cnt;
struct edge{int u,v,w,nex;}e[MM<<1];

struct node{ll w;int ide,las;friend bool operator<(node n1,node n2){return n1.w>n2.w;}};
priority_queue<node>q;bitset<MN>vis;

inline void prim(int st)
{
	for(int i=1;i<=n;++i)dis[i]=inf;
	dis[st]=0,q.push({0,st,0});
	while(!q.empty())
	{
		node now=q.top();q.pop();if(vis[now.ide])continue;
		int u=now.ide;vis[u]=1,ans+=now.w,cnt-=u<=n-k;
		if(now.las!=0)in[u]=e[now.las].w,out[e[now.las].u]=e[now.las].w;
		if(cnt<=0)break;
		fre(i,u,v)if(!vis[v]&&dis[v]>=e[i].w)dis[v]=e[i].w,q.push({dis[v],v,i});
	}
}

inline bool solve()
{
	cin>>n>>m>>k;for(int i=1,u,v,w;i<=m;++i)cin>>u>>v>>w,adde(u,v,w),adde(v,u,w);
	for(int i=1;i<=k;++i)
	{
		cin>>c[i];
		for(int j=1;j<=n;++j)cin>>a[i][j],adde(j,n+i,a[i][j]+c[i]),adde(n+i,j,a[i][j]);
	}
	cnt=n,n+=k,prim(1),vis.reset();for(int i=1;i<=k;++i)if(!out[n-k+i])ans-=in[n-k+i];
	cout<<ans<<endl;
	return 0;
}

signed main()
{
	frein(road);freout(road);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
//	system("fc road.out road4.ans");
//	int t=1;cin>>t;while(t--)solve();
//	while(!solve());
	solve();
	return 0;
}
/*
#include <bits/stdc++.h>
#define endl '\n'
//#define int ll
#define inline
#define sh short
#define fi first
#define se second
#define db double
#define ldb long db
#define ll long long
#define ull unsigned ll
#define PII pair<int,int>
#define fopen(x) frein(x),freout(x)
#define fix(x) fixed<<setprecision(x)
#define frein(x) freopen(#x".in","r",stdin)
#define daout(x) freopen(#x".in","w",stdout)
#define freout(x) freopen(#x".out","w",stdout)
#define freans(x) freopen(#x".ans","w",stdout)
#define adde(u,v,w) e[++edge_cnt]={u,v,w,head[u]},head[u]=edge_cnt
#define adde2(u,v,w) e2[++edge_cnt2]={u,v,w,head2[u]},head2[u]=edge_cnt
#define fre(i,u,to) for(int i=head[u],to=e[i].v;i;i=e[i].nex,to=e[i].v)
#define fre2(i,u,to) for(int i=head2[u],to=e2[i].v;i;i=e2[i].nex,to=e2[i].v)
#define gc() (p1==p2&&(p2=(p1=buf)+fread(buf,1,fread_cnt,stdin),p1==p2)?EOF:*p1++)

using namespace std;

mt19937 rnd(chrono::system_clock::now().time_since_epoch().count());
const int fread_cnt=1<<20;
const int mod=1e9+7;
const int MN=1e4+20;
const int MM=2e6+10;
//const ll inf=1e18;
const int inf=1e9;

char buf[fread_cnt],*p1=buf,*p2=buf;

template<typename T=int>
inline T read()
{
	T x=0;bool f=0;char ch=gc();
	while(ch<'0'||ch>'9')f^=ch=='-',ch=gc();
	while(ch>='0'&&ch<='9')x=(x<<1)+(x<<3)+(ch^48),ch=gc();
	return f?-x:x;
}

ll ans;
int n,m,k,
dis[MN],
c[MN],a[20][MN],
head[MN],edge_cnt,
head2[MN],edge_cnt2;
struct edge{int u,v,w,nex;}e[MM<<1],e2[MM<<1];

struct node{ll w;int ide,las;friend bool operator<(node n1,node n2){return n1.w>n2.w;}};
priority_queue<node>q;bitset<MN>vis;

inline void prim(int st)
{
	for(int i=1;i<=n;++i)dis[i]=inf;
	dis[st]=0,q.push({0,st,0});
	while(!q.empty())
	{
		node now=q.top();q.pop();if(vis[now.ide])continue;
		int u=now.ide;vis[u]=1,ans+=now.w;
		if(now.las!=0)adde2(e[now.las].u,u,e[now.las].w),adde2(u,e[now.las].u,e[now.las].w);
		fre(i,u,v)if(!vis[v]&&dis[v]>=e[i].w)dis[v]=e[i].w,q.push({dis[v],v,i});
	}
}

int jl[MN],to1[MN];

inline void dfs(int u,int f){fre2(i,u,v)if(v!=f)jl[v]=e2[i].w,to1[v]=u!=1?to1[u]:e[i].w,dfs(v,u);}

inline bool solve()
{
	cin>>n>>m>>k;for(int i=1,u,v,w;i<=m;++i)cin>>u>>v>>w,adde(u,v,w),adde(v,u,w);
	for(int i=1;i<=k;++i)
	{
		cin>>c[i];
		for(int j=1;j<=n;++j)cin>>a[i][j];
	}
	prim(1);
	vis.reset(),dfs(1,0);
	for(int i=2;i<=n;++i)
		for(int j=2;j<=n;++j)
			for(int kk=1;kk<=k;++kk)
				if(a[k][i]+a[k][j]<min(jl[i],jl[j]))
					ans-=min(jl[i],jl[j])-a[k][i]-a[k][j];
	for(int i=2;i<=n;++i)
		for(int kk=1;kk<=k;++kk)
			if(a[k][i]+a[k][1]<min(jl[i],to1[i]))
				ans-=min(jl[i],to1[i])-a[k][i]-a[k][1];
	cout<<ans<<endl;
	return 0;
}

signed main()
{
	frein(road4);//freout(road);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
//	system("fc road.out road4.ans");
//	int t=1;cin>>t;while(t--)solve();
//	while(!solve());
	solve();
	return 0;
}
*/