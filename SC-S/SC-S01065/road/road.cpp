#include<bits/stdc++.h>
using namespace std;

ifstream fin("road.in");
ofstream fout("road.out");
#define cin fin
#define cout fout

const int N=1e4+50,M=1.2e6+50,P=12;

int n,m,k,a[P][N],c[P];
using i64=long long;

struct Edge{
	int u,v,w;
	bool operator < (const Edge&e) const{
		return w<e.w;
	}
} E[M],T[M];

int fa[N],siz[N];
int find(int x){
	return fa[x]==x?x:fa[x]=find(fa[x]);
}
inline bool merge(int u,int v){
	u=find(u),v=find(v);
	if(u==v) return 0;
	if(siz[u]<siz[v]) swap(u,v);
	fa[v]=u,siz[u]+=siz[v];
	return 1;
}

i64 ans;

i64 work(Edge *E,Edge *T,int len,int nd){
	sort(E+1,E+1+len);
	iota(fa+1,fa+1+n+k,1);
	fill(siz+1,siz+1+n+k,1);
	i64 sum=0;
	int s=0;
	for(int i=1;i<=len&&nd>1;++i){
		// cerr<<i<<"\n";
		auto[u,v,w]=E[i];
		if(merge(u,v)){
			--nd;
			sum+=w;
			T[++s]=E[i];
		}
	}
//	cerr<<" is "<<sum<<"\n";
	return sum;
}

i64 pre=0;

void dfs(int i,int nd,i64 now){
//	cerr<<i<<" "<<nd<<" "<<now<<"\n";
	if(i>k){
		ans=min(ans,now+pre);
//		i64 ss=0;
//		for(int i=1;i<nd;++i) ss+=T[i].w;
//		cerr<<ss<<" "<<pre<<" "<<now<<"\n";
//		assert(ss+pre==now);
		return;
	}
	dfs(i+1,nd,now);
	int len=nd-1;
	vector<Edge> lis(len+1);
	for(int i=1;i<=len;++i) E[i]=T[i],lis[i]=T[i];
	for(int j=1;j<=n;++j) E[len+j]={n+i,j,a[i][j]};
//	cerr<<i<<" "<<nd<<" "<<now<<" is log\n";
	pre+=c[i];
	dfs(i+1,nd+1,work(E,T,len+n,nd+1));
	pre-=c[i];
//	cerr<<"back!";
//	i64 ss=0;
	for(int i=1;i<=len;++i) T[i]=lis[i];
//	assert(ss+pre==now);
	lis.clear(),lis.shrink_to_fit();
}

signed main(){
	cin>>n>>m>>k;
	for(int i=1;i<=m;++i)
		cin>>E[i].u>>E[i].v>>E[i].w;
	for(int i=1;i<=k;++i){
		cin>>c[i];
		for(int j=1;j<=n;++j)
			cin>>a[i][j];
	}
	ans=work(E,T,m,n);
	dfs(1,n,ans);
	cout<<ans<<"\n";
	return 0;
}

struct Code{
	Code(){ ios::sync_with_stdio(0),cin.tie(0),cout.tie(0); }
	~Code(){ cout.flush(); }
} wtl;