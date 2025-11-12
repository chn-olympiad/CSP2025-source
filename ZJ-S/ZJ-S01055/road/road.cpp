#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>
#include<queue>
#include<ctime>
#define For(a,b,c) for(int a=b;a<=c;++a)
#define froepen freopen
using namespace std; const int M=1e6+8; typedef long long ll;
struct edge{int to,w;};//e[N];
vector<edge>g[10004];
int c[12],a[12][10004];
struct qtp{int u; ll wcst;}; int cand[10004];
bool operator>(const qtp& a,const qtp& b){return a.wcst>b.wcst;}
priority_queue<qtp,vector<qtp>,greater<qtp> >pq; bool vis[10014];
int main(){
	freopen("road.in","r",stdin);freopen("road.out","w",stdout);
	clock_t cl=clock();
	
	int n,m,k; cin>>n>>m>>k;
	For(i,1,m){int u,v,w; cin>>u>>v>>w; g[u].push_back(edge{v,w}),g[v].push_back(edge{u,w});};
	For(i,1,n) sort(g[i].begin(),g[i].end(),[](edge a,edge b){return a.w<b.w;});
	For(idx,0,k-1){cin>>c[idx]; For(i,1,n) cin>>a[idx][i];}
	ll ans=1e18;
	for(int msk=0,msked=1<<k;msk<msked;++msk){
//		cerr<<msk<<"\n";
		memset(vis+1,0,sizeof(*vis)*(n+k));
		vector<int>opt;
		ll adt=0; for(int i=0;i<k;++i) if(msk&1<<i) adt+=c[i],opt.push_back(i);
		priority_queue<qtp,vector<qtp>,greater<qtp> >pq;
		ll pans=adt; if(pans>ans) continue;
//		fprintf(stderr,"[msk=%d]\n",msk);
		for(pq.push({1,0});pq.size();){
			int u=pq.top().u,wcst=pq.top().wcst; pq.pop();
//			fprintf(stderr,"(%d,%lld)\n",u,wcst);
			if(vis[u]) continue; pans+=wcst; vis[u]=1;// fprintf(stderr,"%d marked, ans=%lld\n",u,pans);
			if(pans>ans) break;
			if(u<=n){
//				int cnt=0;
				for(edge v:g[u]){if(!vis[v.to]) pq.push({v.to,v.w});}
				for(int v:opt) if(!vis[v+n+1]) pq.push({v+n+1,a[v][u]});
			}else{
				int ed=n;
				For(i,1,ed) if(!vis[i]) pq.push({i,a[u-n-1][i]});
			}
		}
		ans=min(ans,pans);
		if(clock()-cl>=900*CLOCKS_PER_SEC/1000){cout<<min(ans,pans); return 0;}
	}
	cout<<ans;
}
/*
md xie le 2 h gei laozi jia le.
*/