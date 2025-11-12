#include<cstdio>
#include<algorithm>
template <typename T> bool tense(T &a,const T &b){return b<a?a=b,true:false;}
template <typename T> bool relax(T &a,const T &b){return b>a?a=b,true:false;}

int n,m,K;

namespace Basic{
	const int N = 10010,M = 1e6+10;
	struct Edge{int u,v,w;} e[M];
	int p[N];
	
	bool cmpw(const Edge &a,const Edge &b){
		return a.w<b.w;
	}
	int find(int x){
		return p[x]==x?p[x]:p[x]=find(p[x]);
	}
	void solve(){
		for(int i=1;i<=n;i++) scanf("%d%d%d",&e[i].u,&e[i].v,&e[i].w);
		std::sort(e+1,e+m+1,cmpw);
		for(int i=1;i<=n;i++) p[i] = i;
		long long res = 0;
		for(int i=1;i<=m;i++){
			int pu = find(e[i].u),pv = find(e[i].v);
			if(pu==pv) continue;
			p[pu] = pv;
			res+=e[i].w;
		}
		printf("%lld\n",res);
	}
}
//namespace Force1{
//	const int N = 1010,M = 1e6+10,MAXK = 15;
//	const long long INF = 0x3f3f3f3f3f3f3f3fll;
//	struct Edge{int u,v,w;} e0[M],e[M];
//	int dist0[N][N],dist[N][N];
//	int c[N],a[MAXK][N];
//	int p[N];
//	
//	bool cmpw(const Edge &a,const Edge &b){
//		return a.w<b.w;
//	}
//	int find(int x){
//		return p[x]==x?p[x]:p[x]=find(p[x]);
//	}
//	void solve(){
//		printf("n=%d,m=%d,k=%d\n",n,m,K);
//		for(int i=1;i<=n;i++){
//			scanf("%d%d%d",&e0[i].u,&e0[i].v,&e0[i].w);
//		}
//		for(int i=1;i<=n;i++) scanf("%d",&c[i]);
//		for(int j=1;j<=K;j++) for(int i=1;i<=n;i++) scanf("%d",&a[j][i]);
//		long long ans = INF;
//		for(int s=0;s<(1<<K);s++){
//			for(int i=1;i<=m;i++){
//				e[i] = e0[i];
//				for(int k=1;k<=K;k++){
//					if(s>>(k-1)&1) tense(e[i].w,a[k][e[i].u]+a[k][e[i].v]);
//				}
//			}
//			printf("s = %d\n",s);
////			for(int i=1;i<=n;i++) for(int j=i+1;j<=n;j++) printf("dist[%d][%d] = %d\n",i,j,dist[i][j]);
//			for(int i=1;i<=m;i++) printf("%d-%d %d\n",e[i].u,e[i].v,e[i].w);
//			std::sort(e+1,e+m+1,cmpw);
//			for(int i=1;i<=n;i++) p[i] = i;
//			long long res = 0;
//			for(int j=1;j<=K;j++) if(s>>(j-1)&1) res+=c[j];
//			for(int i=1;i<=m;i++){ 
//				int pu = find(e[i].u),pv = find(e[i].v);
//				if(pu==pv) continue;
//				p[pu] = pv;
//				res+=e[i].w;
//			}
//			tense(ans,res);
//		}
//		printf("%lld\n",ans);
//	}
//}
namespace Force2{
	const int N = 10010,M = 1e6+10,MAXK = 15;
	const long long INF = 0x3f3f3f3f3f3f3f3fll;
	struct Edge{int u,v,w;} e[M];
	int dist[N][N];
	int c[N],a[MAXK][N];
	int p[N];
	
	bool cmpw(const Edge &a,const Edge &b){
		return a.w<b.w;
	}
	int find(int x){
		return p[x]==x?p[x]:p[x]=find(p[x]);
	}
	void solve(){
		for(int i=1;i<=n;i++){
			scanf("%d%d%d",&e[i].u,&e[i].v,&e[i].w);
			if(e[i].v<e[i].u) std::swap(e[i].u,e[i].v);
			dist[e[i].u][e[i].v]= e[i].w;
		}
		for(int i=1;i<=n;i++) scanf("%d",&c[i]);
		for(int j=1;j<=K;j++) for(int i=1;i<=n;i++) scanf("%d",&a[j][i]);
		for(int i=1;i<=m;i++) for(int j=1;j<=K;j++) tense(e[i].w,a[j][e[i].u]+a[j][e[i].v]);
		std::sort(e+1,e+m+1,cmpw);
		for(int i=1;i<=n;i++) p[i] = i;
		long long res = 0;
		for(int i=1;i<=m;i++){
			int pu = find(e[i].u),pv = find(e[i].v);
			if(pu==pv) continue;
			p[pu] = pv;
			res+=e[i].w;
		}
		printf("%lld\n",res);
	}
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&K);
	if(K==0) Basic::solve();
	else Force2::solve();
	return 0;
}

