#include<bits/stdc++.h>
using namespace std;
namespace lkwbian{
	using ll=long long;
	using pii=pair<int,int>;
	#define fi first
	#define se second
	#define mp make_pair
	#define pb emplace_back
	const int N=10005;
	int n,m,k;
	struct edge{
		int u,v,w;
		edge(int _u,int _v,int _w):u(_u),v(_v),w(_w){}
		edge(){}
		inline bool operator < (const edge B)const{
			return w<B.w;
		}
	};
	vector<edge>egs;
	vector<edge>A[20];
	int fa[N];
	inline init(){
		for(int i=1;i<=n+k;i++)fa[i]=i;
	}
	int find(int x){
		return fa[x]==x?x:fa[x]=find(fa[x]);
	}
	int c[15];
	int Q[20];
	ll solve(int S){
		int tot=__builtin_popcount(S)+n-1;
		init();
		int ql=1,qr=0,now=k;
		Q[++qr]=0;
		ll ans=0;
		for(int i=0;i<k;i++){
			if(S>>i&1){
				Q[++qr]=i+1;
				ans+=c[i+1];
			}
		}
		while(ql<qr){
			int x=Q[ql],y=Q[ql+1];
			ql+=2;
			Q[++qr]=++now;
			A[now].clear();
			A[now].resize(A[x].size()+A[y].size());
			merge(A[x].begin(),A[x].end(),A[y].begin(),A[y].end(),A[now].begin());
		}
		assert(A[Q[ql]].size()==n-1+__builtin_popcount(S)*n);
//		if(S==1){
//			for(auto e:A[Q[ql]])
//				cout<<e.u<<' '<<e.v<<' '<<e.w<<'\n';
//			exit(0);
//		}
		for(auto e:A[Q[ql]]){
			int x=find(e.u),y=find(e.v);
			if(x^y){
				fa[x]=y;
				ans+=e.w;
				if(!--tot)return ans;
			}
		}
		exit(-1);
	}
	void Main(){
		cin.tie(nullptr)->sync_with_stdio(0);
		cin>>n>>m>>k;
		for(int i=1,u,v,w;i<=m;i++){
			cin>>u>>v>>w;
			egs.pb(u,v,w);
		}
		sort(egs.begin(),egs.end());
		init();
		for(auto e:egs){
			int u=e.u,v=e.v,w=e.w;
			u=find(u),v=find(v);
			if(u^v){
				fa[u]=v;
				A[0].pb(e);
			}
		}
//		for(auto e:A[0])
//			cout<<e.u<<' '<<e.v<<' '<<e.w<<'\n';
//		return;
		for(int i=1;i<=k;i++){
			cin>>c[i];
			for(int j=1,x;j<=n;j++){
				cin>>x;
				A[i].pb(n+i,j,x);
			}
			sort(A[i].begin(),A[i].end());
		}
//		for(int i=0;i<=k;i++)
//			cout<<A[i].size()<<' ';
//		return;
		ll ans=0x3f3f3f3f3f3f3f3f;
		for(int S=0;S<(1<<k);S++)
			ans=min(ans,solve(S));
		cout<<ans;
	}
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	lkwbian::Main();
	return 0;
}
//Ren5Jie4Di4Ling5% 
// A: 17min 
// B: 1h11min, 15:58
