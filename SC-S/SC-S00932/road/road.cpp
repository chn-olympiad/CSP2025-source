#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int N=1e4+5,K=11,M=1e6+5;
const ll inf=1e18;
int n,m,k;
struct eg{
	int u,v,w;
	bool operator<(const eg&B)const{return w<B.w;}
};
struct dsu{
	array<int,N+K>pa,sz;
	void init(){for(int i=1;i<=n+k;++i)pa[i]=i,sz[i]=1;}
	int fd(int x){return pa[x]==x?x:(pa[x]=fd(pa[x]));}
	bool uni(int a,int b){
		int Pa=fd(a),Pb=fd(b);
		if(Pa==Pb)return false;
		if(sz[Pa]<sz[Pb])swap(Pa,Pb);
		sz[Pa]+=sz[Pb],pa[Pb]=Pa;
		return true;
	}
}DSU;
inline ll calc(vector<eg>&E){
	ll res=0;
	DSU.init();
	int p=0;
	for(int i=0;i<E.size();++i)if(DSU.uni(E[i].u,E[i].v))res+=E[i].w,E[p++]=E[i];
	E.resize(p);
	return res;
}
vector<eg>E;
inline void add(int a,int b,int w){E.push_back({a,b,w});}
int cnt=0;
array<vector<eg>,K>tmp;
array<vector<eg>,K>a;
array<int,K>c;
inline void add2(int x,int y,int w){a[x].push_back({n+x,y,w});}
ll ans=inf;
inline void pre(){
	sort(E.begin(),E.end());
	ans=calc(E);
	for(int i=1;i<=k;++i)sort(a[i].begin(),a[i].end());
}
void dfs(int i,ll v,vector<eg>&E){
	v+=c[i];
	auto sz=E.size();
	E.insert(E.end(),a[i].begin(),a[i].end());
	inplace_merge(E.begin(),E.begin()+sz,E.end());
	ans=min(ans,v+calc(E));
	auto &t=tmp[cnt++];
	for(int j=i+1;j<=k;++j)t=E,dfs(j,v,t);
	--cnt;
}
inline void sol(){dfs(1,0,E);}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin.tie(0)->sync_with_stdio(0);
	cin>>n>>m>>k;
	E.reserve(max(m,2*n+10));
	for(int i=0;i<k;++i)tmp[i].reserve(2*n+10);
	int u,v;ll w;
	for(int i=1;i<=m;++i)cin>>u>>v>>w,add(u,v,w);
	for(int i=1;i<=k;++i){
		cin>>c[i];
		int t;
		for(int j=1;j<=n;++j)cin>>t,add2(i,j,t);
	}
	pre(),sol();
	cout<<ans;
	return 0;
}