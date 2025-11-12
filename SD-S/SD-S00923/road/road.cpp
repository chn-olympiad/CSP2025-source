#include <bits/stdc++.h>
using namespace std;
#define ll long long
typedef pair<int,int> pii;
#define fi first
#define se second
#define mp make_pair
#define pb push_back
const int N=1e4+20,K=12,M=1e6+10,INF=0x3f3f3f3f,mod=1e9+7;
char st;
int n,m,k;
struct edge{
	int u,v,w;
};
bool operator<(edge &x,edge &y){
	return x.w<y.w;
}
ll ans=0;
int cnt;
edge oe[M];
vector<edge> ue,es[K];
int c[K];
struct DSU{
	int fa[N];
	void init(){
		for(int i=0;i<N;i++)fa[i]=i;
	}
	int find(int x){
		return x==fa[x]?x:fa[x]=find(fa[x]);
	}
	bool merge(int x,int y){
		x=find(x),y=find(y);
		if(x==y)return 0;
		fa[x]=y;
		return 1;
	}
}dsu;
vector<edge> inp;
int cc=0;
void mergein(vector<edge> &f,vector<edge> &g){ 
	vector<edge> tmp=f;
	f.clear();
	int pf=0,pg=0;
	while(pf<tmp.size()&&pg<g.size()){
		if(tmp[pf]<g[pg]){
			f.pb(tmp[pf]);
			pf++;
		}else{
			f.pb(g[pg]);
			pg++;
		}
	}
	while(pf<tmp.size()){
		f.pb(tmp[pf]);
		pf++;
	}
	while(pg<g.size()){
		f.pb(g[pg]);
		pg++;
	}
	cc+=f.size();
}
ll Kruskal(int n){
	int cnt=0;
	dsu.init();
	ll ans=0;
	for(edge e:inp){
		if(dsu.merge(e.u,e.v))ans+=e.w,cnt++;
		if(cnt==n-1)break;
	}
	return ans;
}
inline int read(){
	int x=0;
	char ch=getchar();
	while(!isdigit(ch))ch=getchar();
	while(isdigit(ch))x=(x<<1)+(x<<3)+ch-'0',ch=getchar();
	return x;
}
char ed;
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
//	cerr<<(&st-&ed)/1024.0/1024.0<<endl;
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
//	cin>>n>>m>>k;
	n=read(),m=read(),k=read();
	for(int i=1;i<=m;i++){
		oe[i].u=read();
		oe[i].v=read();
		oe[i].w=read();
//		cin>>oe[i].u>>oe[i].v>>oe[i].w;
	}
	for(int i=1;i<=k;i++){
		es[i].reserve(n);
//		cin>>c[i];
		c[i]=read();
		edge ce;
		for(int j=1;j<=n;j++){
			ce.u=n+i;
			ce.v=j;
//			cin>>ce.w;
			ce.w=read();
			es[i].pb(ce);
		}
		sort(es[i].begin(),es[i].end());
	}
	dsu.init();
	sort(oe+1,oe+1+m);
	for(int i=1;i<=m;i++){
		if(dsu.merge(oe[i].u,oe[i].v)){
			ans+=oe[i].w;
			ue.pb(oe[i]);
		}
	}
	for(int S=1;S<(1<<k);S++){
		ll cans=0;
		int nc=0;
		inp.clear();
		mergein(inp,ue);
		for(int i=1;i<=k;i++){
			if((S>>(i-1))&1){
				nc++;
				cans+=c[i];
				mergein(inp,es[i]);
			}
		}
//		cerr<<cc<<' '<<(nc+1)*n<<endl;
		ans=min(ans,cans+Kruskal(n+nc));
	}
	cout<<ans<<'\n';
//	cerr<<cc<<endl;
	return 0;
}
/*
pretest passed 15:33
*/
