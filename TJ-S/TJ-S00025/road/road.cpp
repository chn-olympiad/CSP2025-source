#include<bits/stdc++.h>
//#define int long long
using namespace std;
#define fi first
#define se second
#define mkp make_pair
#define pb emplace_back
#define ep emplace
#define Endl putchar('\n')
#define Space putchar(' ')
typedef long long ll;
using pii=pair<int,int>;
const int inf=0x3f3f3f3f;
const ll Inf=0x3f3f3f3f3f3f3f3f;
template<typename T> inline void read(T &s){
	s=0;int c=getchar();bool f=0;
	while(!isdigit(c))f^=(c=='-'),c=getchar();
	while(isdigit(c))s=(s<<1)+(s<<3)+(c^48),c=getchar();
}
template<typename T> inline void write(T x){
	static int St[40],Top=0;
	if(x<0)putchar('-'),x=-x;
	do St[++Top]=x%10,x/=10; while(x);
	while(Top)putchar(St[Top--]^48);	
}
void read(char &c){do c=getchar(); while(isspace(c));}
template<typename type,typename... T> inline void read(type &x,T&...y){read(x);read(y...);}
const int N=1e4+50,M=1.1e6,K=12;
int n,m,k,vis[N],c[K],a[K][N],vis2[K];
vector<pii> eg[N];
struct node{
	int u,w,fr;
	node(int _,int _1,int _2):u(_),w(_1),fr(_2){}
	bool operator < (const node& o)const{return w>o.w;}
};
void solve1(){
	for(int i=1,x;i<=k;i++){
		eg[i+n].pb(i+n+k,c[i]);
		for(int j=1;j<=n;j++)x=a[i][j],eg[i+n+k].pb(j,x),eg[j].pb(i+n,x);
	}
//	eg[0].pb(1,0);
	priority_queue<node> q;
	q.ep(1,0,0);ll ans=0;int cnt=0;
	while(!q.empty()){
		auto tp=q.top();q.pop();
		int u=tp.u;
		if(vis[u])continue;
		if(tp.fr>n+k)vis2[tp.fr-n-k]=1;
//		cout<<tp.u<<" "<<tp.w<<" "<<tp.fr<<endl;
		vis[u]=(tp.w?tp.w:1);ans+=tp.w;//if(u>n)vis[u]=tp.w;
//		if(u<=n)cnt++;
//		if(cnt>=n)break;
		for(auto to:eg[u]){q.ep(to.fi,to.se,u);} 
	}
//	cout<<ans<<endl;
	for(int i=1;i<=k;i++){
//		cout<<vis[i+n]<<" "<<vis[i+n+k]<<" "<<vis2[i]<<endl;
		if(!vis2[i])ans-=vis[i+n]+c[i];
	}
	write(ans);
}
struct edge{
	int u,v,w;;
	edge(int _,int _1,int _2):u(_),v(_1),w(_2){}
	bool operator < (const edge& o)const{return w<o.w;}
};
vector<edge> ed,G;
int f[N];
int find(int x){return x==f[x]?x:f[x]=find(f[x]);}
void solve2(){
	for(int i=1,x;i<=k;i++){
		for(int j=1;j<=n;j++)x=a[i][j],ed.pb(i+n,j,x);
	}
	sort(ed.begin(),ed.end());
	ll ans=0;
	for(int i=1;i<=n+k;i++)f[i]=i;
	for(auto to:ed){
		int u=find(to.u),v=find(to.v);
		if(u!=v)ans+=to.w,f[u]=v;
	}
	write(ans);
}
void solve3(){
	ll res=Inf;
	for(int S=0;S<(1<<k);S++){
		G.clear();
		for(auto to:ed)G.push_back(to);
		ll ans=0;
		for(int i=1,x;i<=k;i++){
			if(!(S>>(i-1)&1))continue;
			ans+=c[i]; 
			for(int j=1;j<=n;j++)x=a[i][j],G.pb(i+n,j,x);
		}
		sort(G.begin(),G.end());
		for(int i=1;i<=n+k;i++)f[i]=i;
		ll cnt=0;
		for(auto to:G){
//			cout<<to.u<<" "<<to.v<<" "<<to.w<<endl;
			int u=find(to.u),v=find(to.v);
			if(u!=v)cnt+=to.w,f[u]=v;
		}
		ans+=cnt;
		res=min(res,ans);
	}
	write(res);
}
void solve(){
	read(n,m,k);
	for(int i=1,u,v,w;i<=m;i++)read(u,v,w),eg[u].pb(v,w),eg[v].pb(u,w),ed.pb(u,v,w);
	int flag=1;
	for(int i=1,x;i<=k;i++){
		read(c[i]);flag&=(!c[i]);
		for(int j=1;j<=n;j++)read(a[i][j]);
	}
	if(flag||k==0) solve2();
	else if((ll)m*(1ll<<k)<=1.5e7)solve3();
	else solve1();
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
//	ios::sync_with_stdio(false);
//	cin.tie(nullptr);cout.tie(nullptr);
	int T=1;//read(T);
	while(T--){
		solve();
	}
	return 0;
}
