#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

const int N=1e4+50;
struct edge{int x,y,z;bool operator <(edge t)const{return z<t.z;}};
int n,m,c[N],fa[N],k,siz[N];ll ans,res;
vector < edge > f[N],g,dp[N];

inline int lowbit(int x){return x&(-x);}
int root(int x){return x==fa[x]?x:fa[x]=root(fa[x]);}
inline void merge(int x,int y){
	x=root(x);y=root(y);if(siz[x]>siz[y]) swap(x,y);
//	if(!x||!y) exit(-1);
	fa[x]=y;siz[y]+=siz[x];
}
inline void init(){for(int i=1;i<=n+k;++i) fa[i]=i,siz[i]=1;}

vector<edge> Tree(const vector<edge> &A,const vector<edge> &B){
	init();res=0;vector<edge> t,now;t.resize(A.size()+B.size());
	merge(A.begin(),A.end(),B.begin(),B.end(),t.begin());
	for(edge e:t){
		int x=root(e.x),y=root(e.y);
		if(x==y) continue;
		res+=e.z;merge(e.x,e.y);now.emplace_back(e);
	}
	return now;
}

int main(){
	freopen("road.in","r",stdin);freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0); 
	cin>>n>>m>>k;g.resize(m);for(int i=1;i<=k;++i) f[i].resize(n);
	for(int i=0;i<m;++i) cin>>g[i].x>>g[i].y>>g[i].z;
	for(int i=1;i<=k;++i){cin>>c[i];for(int j=0;j<n;++j) cin>>f[i][j].z,f[i][j].x=i+n,f[i][j].y=j+1;}
	sort(g.begin(),g.end());for(int i=1;i<=k;++i) sort(f[i].begin(),f[i].end());
	for(int i=1;i<(1<<k);++i){
		if(lowbit(i)==i) dp[i]=f[__lg(i)+1];
		else dp[i]=Tree(dp[i-lowbit(i)],f[__lg(lowbit(i))+1]);
	}
//	Tree(g,f[1]);cout<<res+c[1]<<'\n';
	vector<edge> tmp;tmp.clear();g=Tree(g,tmp);ans=res;
//	cerr<<res<<'\n';
	for(int i=1;i<(1<<k);++i){
		Tree(g,dp[i]);
//		cerr<<i<<' '<<res<<'\n';
		for(int j=1;j<=k;++j) if((i>>(j-1))&1) res+=c[j];
//		cerr<<i<<' '<<res<<'\n';
		ans=min(ans,res);
	}
	cout<<ans<<'\n';
	return 0;
}