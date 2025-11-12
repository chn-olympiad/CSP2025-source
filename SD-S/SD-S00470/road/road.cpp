#include<bits/stdc++.h>
#define int long long
#define double long double
#define sqrt sqrtl
#define fst ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define endl '\n'
#define popcount __builtin_popcountll
#define parity __builtin_parityll
#define clz __builtin_clzll
#define ctz __builtin_ctzll
//#define CONSTRUCTOR
#ifdef CONSTRUCTOR
#define push_back emplace_back
#define pop_back emplace_back
#define insert emplace
#endif
#define pii pair<int,int>
#define fi first
#define se second
using namespace std;
int qpow(int a,int n){int res=1;while(n){if(n&1){res=res*a;}a=a*a;n>>=1;}return res;}
int qpow(int a,int n,int p){int res=1;while(n){if(n&1){res=res*a%p;}a=a*a%p;n>>=1;}return res;}
int gcd(int a,int b){if(!b){return a;}return gcd(b,a%b);}
int lcm(int a,int b){return a*b/gcd(a,b);}
int lowbit(int x){return x&(-x);}
const int N=1e4+99,M=(1<<10)+99,K=1e6+99;
int n,m,k;
struct edge{
	int v,w;
};
struct Edge{
	int u,v,w;
}E[N];
vector<edge>e[N];
int c[15],a[15][N];
int fa[N];
int find(int x){
	return fa[x]==x?x:fa[x]=find(fa[x]);
}
int f[M];
map<pii,int>mp,mp1;
int val[N],fat[N],siz[N];
int dfn[N],idx;
int b[N];
void dfs(int u,int fa){
	fat[u]=fa;
	siz[u]=1;
	dfn[u]=++idx;
	int maxx=-1;
	for(auto i:e[u]){
		int v=i.v,w=i.w;
		if(v!=fa){
			val[v]=w;
			dfs(v,u);
			siz[u]+=siz[v];
		}
	}
}
int ans;
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	fst;
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		E[i]={u,v,w};
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++){
			cin>>a[i][j];
		}
	}
	sort(E+1,E+1+m,[&](Edge a,Edge b){
		return a.w<b.w;
	});
	for(int i=1;i<=n;i++){
		fa[i]=i;
	}
	int minn=0;
	for(int i=1;i<=m;i++){
		int u=find(E[i].u),v=find(E[i].v),w=E[i].w;
		if(fa[u]!=fa[v]){
			fa[u]=v;
			minn+=w;
			mp1[{min(u,v),max(u,v)}]=w;
			e[E[i].u].push_back({E[i].v,w});
			e[E[i].v].push_back({E[i].u,w});
		}
	}
	if(k==0){
		cout<<minn<<endl;
		return 0;
	}
	dfs(1,0);
	for(int i=1;i<=n;i++){
		b[i]=fat[i];
	}
	ans=minn;
	for(int i=0;i<(1<<k);i++){
		f[i]=minn;
		mp.clear();
		for(auto j:mp1){
			mp[j.fi]=j.se;
		}
		for(int j=1;j<=n;j++){
			fat[i]=b[i];
		}
		for(int j=1;j<=k;j++){
			if(i&(1<<(j-1))){
				f[i]+=c[j];
				for(int h=1;h<=n;h++){
					for(int p=1;p<=n;p++){
						if(p>=dfn[h]&&p<=dfn[h]+siz[h]-1||p==fat[h]){
							continue;
						}
						if(mp[{min(h,fat[h]),max(h,fat[h])}]>a[j][h]+a[j][p]){
							f[i]=f[i]-mp[{min(h,fat[h]),max(h,fat[h])}]+a[j][h]+a[j][p];
//							cout<<h<<' '<<p<<' '<<mp[{min(h,fat[h]),max(h,fat[h])}]<<' '<<fat[h]<<' '<<a[j][h]+a[j][p]<<endl;
							mp[{min(h,fat[h]),max(h,fat[h])}]=0;
							mp[{min(h,p),max(h,p)}]=a[j][h]+a[j][p];
						}
					}
				}
			}
		}
		ans=min(ans,f[i]);
//		cout<<f[i]<<endl;
	}
	cout<<ans<<endl;
	return 0;
}
