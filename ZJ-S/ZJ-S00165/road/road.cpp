#include<bits/stdc++.h>
using namespace std;
#define MAXN 10050
// #define MAXM 1000005
#define int long long
inline void read(int &x){scanf("%lld",&x);}
inline void write(int x){printf("%lld",x);}
int n,m,k,ans,cost[12],bd,ks;
bool f[12];
struct Edge{
	int u,v,w;
}edge;
inline bool operator< (Edge x,Edge y){return x.w<y.w;}
vector<Edge>v,nv,sv,ssv;
namespace MinTree{
	int anc[MAXN],sum;
	inline void reset(){
		for(int i=1;i<=n+k;i++) anc[i]=i;
		sum=0;
		return;
	}
	inline int find(int x){return x==anc[x]?x:anc[x]=find(anc[x]);}
	inline void solve1(){
		reset();
		sort(v.begin(),v.end());
		for(Edge e:v){
			if(find(e.u)!=find(e.v)){
				sv.push_back(e);
				sum+=e.w;
				anc[anc[e.u]]=anc[e.v];
			}
			if((int)sv.size()==n-1) break;
		}
		ans=sum;
		ssv=sv;
		return;
	}
	inline void solve2(int x){
		reset();
		nv=sv;
		read(cost[x]);
		sum=cost[x];
		for(int i=1;i<=n;i++){
			int w;
			read(w);
			nv.push_back((Edge){n+x,i,w});
		}
		sort(nv.begin(),nv.end());
		for(Edge e:nv){
			if(find(e.u)!=find(e.v)){
				if(e.u>n) ssv.push_back(e);
				sum+=e.w;
				anc[find(e.u)]=find(e.v);
			}
		}
		ans=min(ans,sum);
		return;
	}
	inline void solve3(){
		reset();
		sum=ks;
		for(Edge e:nv){
			if(e.u>n&&!f[e.u-n]) continue;
			if(find(e.u)!=find(e.v)){
				if(e.u>n) ssv.push_back(e);
				sum+=e.w;
				anc[find(e.u)]=find(e.v);
			}
		}
		ans=min(ans,sum);
		// cout<<ks<<" "<<sum<<endl;
		return;
	}
	inline void dfs(int x){
		if(x==k+1){
			solve3();
			return;
		}
		f[x]=0;
		dfs(x+1);
		f[x]=1;
		ks+=cost[x];
		dfs(x+1);
		ks-=cost[x];
		f[x]=0;
	}
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	read(n),read(m),read(k);
	for(int i=0;i<m;i++){
		read(edge.u),read(edge.v),read(edge.w);
		v.push_back(edge);
	}
	MinTree::solve1();
	// for(int i=1;i<=k;i++){
	// 	MinTree::solve2(i);
	// }
	nv=sv;
	for(int i=1;i<=k;i++){
		read(cost[i]);
		for(int j=1;j<=n;j++){
			read(edge.w);
			edge.u=n+i;
			edge.v=j;
			nv.push_back(edge);
		}
	}
	sort(nv.begin(),nv.end());
	MinTree::dfs(1);
	write(ans);
	return 0;
}
/*
solve1 O(mlogm+mlogn)
solve2 O(2^k*(knlog(kn)+knlogn))
*/