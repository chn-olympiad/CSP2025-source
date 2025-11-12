#include<stdio.h>
using ll = long long;
template<typename TYPE>
inline void read(TYPE &x){
	x = 0;
	char c;
	bool f = 0;
	do{
		c = getchar();
		if(c=='-') f = 1;
	}while(c<'0'||'9'<c);
	while('0'<=c && c<='9'){
		x *= 10;
		x += c - '0';
		c = getchar();
	}
	if(f) x = -x;
}

template<typename TYPE>
inline void domin(TYPE &a, TYPE b){
	if(a > b) a = b;
}

#include<algorithm>
using std::sort;

#include<vector>
using std::vector;

#include<functional>
using std::greater;

#include<bitset>
using std::bitset;

struct edge{
	int v,w;
	edge(int V,int W){v = V, w = W;}
	// sort it according the edge weight.
	auto operator > (const edge &rhs) const{
		return w > rhs.w;
	}
};

#include<queue>
using std::priority_queue;
using pq = priority_queue<edge,vector<edge>,greater<edge> >;

/*--------------------------------------------------*/

constexpr int MAXK = 10+5;
constexpr int MAXN = 1e4+MAXK, MAXM = 1e6+5;

vector<edge> G[MAXN];

// it is dijkstra sorted with weight of edges:)
bitset<MAXN> vis;

ll ans;

bool tranopen[MAXN];

int n, m, k;

inline ll prim(int u = 1){
	vis = 0;		// clear for multy tests
	pq q;
	ll cur = 0; 	// current sum
	vis[u] = 1;
	for(auto ed : G[u]){
		int v = ed.v, w = ed.w;
		if(v<=n || tranopen[v]) q.push(edge(v,w));
	}
	
	while(!q.empty()){
		int v = q.top().v, vw = q.top().w;	q.pop();
		if(vis[v]) continue;
		
// else: we accept it as the minimal edge in The Graph
		cur += vw;
		vis[v] = 1;
		
		for(auto ed : G[v]){
			int to = ed.v, tow = ed.w;
			if(vis[to]) continue;
			if(to <= n || tranopen[to]) q.push(edge(to,tow));
		}
	}
	return cur;
}

// There is K villages, I indexed them as: (n+j)
int fee[MAXK];
//int vil[MAXK][MAXN];	// repairable

void dfs(int stt = 1, ll nowf = 0){		// start, nowfee
	// Self Work
	if(stt != 1){		// stt = 1: no village built
		ll res = prim();
		domin(ans, res + nowf);
	}
	
	// Call more to work
	for(int j = stt; j <= k; j++){
		
		tranopen[j+n] = true;
		nowf += fee[j];
		
		dfs(j + 1, nowf);	// the FIRST next round min is 2.
		
		nowf -= fee[j];
		tranopen[j+n] = false;
	}
}

// kruskal
struct uvw{
	uvw(int U,int V,int W){u = U, v = V, w = W;}
	int u,v,w;
	bool operator < (const uvw &rhs) const{
		return w < rhs.w;
	}
};

namespace UFS{
	int f[MAXN];
	void init(){
		for(int i=1;i<=n;i++) f[i] = i;
	}
	int find(int x){
		if(f[x] == x) return x;
		return f[x] = find(f[x]);
	}
	void merge(int fx, int fy){
//		int fx = find(x), fy = find(y);
		f[fx] = fy;
//		return;
	}
}

vector <uvw> g;
bool marky[MAXM];
void kru(){
	UFS::init();
	sort(g.begin(),g.end());
	
	int merged = 0;
	int edg = g.size();
	for(int i = 0; i<edg; i++){
		int fu = UFS::find(g[i].u), fv = UFS::find(g[i].v);
//		printf("%d %d\n",fu,fv);
		if(fu == fv) continue;
		UFS::merge(fu, fv);
		
		ans += g[i].w;
		merged++;
		
		marky[i] = true;
		if(merged == n-1) break;
	}
//	int node_cnt = 0;
	for(int i = 0; i<edg; i++){
		if(marky[i]){
			G[g[i].u].push_back(edge(g[i].v, g[i].w));
			G[g[i].v].push_back(edge(g[i].u, g[i].w));
//			node_cnt++;
		}
	}
//	printf("CNT:%d\n",node_cnt);
}

int main(){
#ifdef IO
	freopen("road3.in","r",stdin);
#else
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
#endif
	read(n),read(m),read(k);
	for(int i = 0; i < m; i++){
		int u, v, w;
		read(u); read(v); read(w);
		g.push_back(uvw(u,v,w));
	}
	kru();
	for(int j = 1; j <= k; j++){
		read(fee[j]);
		G[n+j].reserve(n);
		for(int i = 1;i <= n; i++){
			int w;
			read(w);
			G[i].emplace_back(edge(n+j,w));
			G[n+j].emplace_back(edge(i,w));
		}
	}
	dfs();
	printf("%lld\n",ans);
	return 0;
} 