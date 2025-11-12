#include <bits/stdc++.h>
using namespace std;
using LL=long long;
#define cst const
#define sttc static
#define  FOR(i, s, e) for (int i=int(s);i<=int(e);i++)
#define _FOR(i, s, e) for (int i=int(s);i>=int(e);i--)

int n, m, k;
struct node{
	int u, v;LL w;
	inline bool friend operator<(cst node &a, cst node &b){
		return a.w<b.w;
	}
};
vector<int> fa;
vector<node> edge;
inline int get_r(cst int &u){
	if (fa[u]!=u)return fa[u]=get_r(fa[u]);
	return u;
}
int main(){
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	cin.tie(0)->sync_with_stdio(false);

	cin>>n>>m>>k, fa.resize(n+1), iota(fa.begin(), fa.end(), 0);
	int u, v;LL w;
	FOR (i, 1, m)cin>>u>>v>>w, edge.push_back({u, v, w});
	sort(edge.begin(), edge.end());
	LL ans=0;
	for (cst auto &e:edge){
		int ur=get_r(e.u), vr=get_r(e.v);
		if (ur==vr)continue;
		ans+=e.w, fa[ur]=vr;
	}
	printf("%lld", ans);
	return 0;
}
//忘了Prim但记得Dijikstra我也是尽力了(AFO) 
//#include <bits/stdc++.h>
//using namespace std;
//using LL=long long;
//#define cst const
//#define sttc static
//#define  FOR(i, s, e) for (int i=int(s);i<=int(e);i++)
//#define _FOR(i, s, e) for (int i=int(s);i>=int(e);i--)
//
//#define INF 0x3f3f3f3f3f3fLL
//struct EDGE{int v;LL w;};
//struct RECORD{//记录上一条边是从哪来的 
//	bool is_special;int e_id;pair<int, int> sp;
//	//是更上一层转化过来的吗
//	//如果不是, 边的编号, 如果是, 那么使用哪一个来的. 
//};cst pair<int, int> mpt={-1, -1};
//struct node{
//	int u;LL w;int lv;//节点, 累计权值, 层数 
//	inline friend bool operator>(cst node &a, cst node &b){
//		return a.w>b.w;
//	}
//}t;
//vector<vector<RECORD>> rec;//记录从什么边来的 
//vector<EDGE> edge;
//vector<vector<int>> adj;
//vector<vector<LL>> extra, dis;
//int n, m, maxlv;
//inline void add_edge(cst int &u, cst int &v, cst LL &w){
//	adj[u].push_back(edge.size()), edge.push_back({v, w});
//	adj[v].push_back(edge.size()), edge.push_back({u, w});
//}
//struct tmp{int lv, u;};
////vector<vector<vector<tmp>>> ree;
////LL DFS(cst int &lv, cst int &u){
////	if (!vis[lv][u]){
////		
////	}
////}
//int main(){
//	freopen("road1.in", "r", stdin);
////	freopen("road.out", "w", stdout);
//	cin.tie(0)->sync_with_stdio(false);
//
//	cin>>n>>m>>maxlv, adj.resize(n+1), extra.resize(maxlv+1, vector<LL>(n+1));
//	int u, v;LL w;
//	FOR (i, 1, m)cin>>u>>v>>w, add_edge(u, v, w);
//	FOR (i, 1, maxlv)FOR (j, 0, n)cin>>extra[i][j];
//	dis.resize(n+1, vector<LL>(maxlv+1, INF)), rec.resize(n+1, vector<RECORD>(maxlv+1, {false, -1, mpt}));
//	//dis[u][k]表示到达u, 需要用k次机会已经到达 
//	priority_queue<node, vector<node>, greater<node>> q;
//	q.push({1, 0, 0}), dis[1][0]=0;
//	while (q.size()){
//		t=q.top();q.pop();
//		if (dis[t.u][t.lv]<t.w)continue;
//		for (cst auto &e_id:adj[t.u]){//同层转化 
//			if (dis[edge[e_id].v][t.lv]>dis[t.u][t.lv]+edge[e_id].w)
//				dis[edge[e_id].v][t.lv]=dis[t.u][t.lv]+edge[e_id].w, 
//				q.push({edge[e_id].v, dis[edge[e_id].v][t.lv], t.lv}), 
//				rec[edge[e_id].v][t.lv]={false, e_id, mpt};
//		}
//		if (t.lv<maxlv){//容许我升变 
//			FOR (v, 1, n){//升变 
//				if (dis[v][t.lv+1]>dis[t.u][t.lv]+extra[t.lv+1][0]+extra[t.lv+1][t.u]+extra[t.lv+1][v])
//					dis[v][t.lv+1]=dis[t.u][t.lv]+extra[t.lv+1][0]+extra[t.lv+1][t.u]+extra[t.lv+1][v], 
//					q.push({v, dis[v][t.lv+1], t.lv+1}),
//					rec[v][t.lv+1]={true, -1, {t.lv, t.u}};
//			}
//		}
//	}
//	printf("dis:\n");
//	FOR (j, 0, maxlv){FOR (i, 1, n)printf("%lld ", dis[i][j]);putchar('\n');}
//	printf("rec:\n");
//	FOR (j, 0, maxlv){
//		FOR (i, 1, n){
//			if (rec[i][j].is_special)printf("lv%d_up:%d->%d ", rec[i][j].sp.first, rec[i][j].sp.second, i);
//			else printf("%d->%d ", rec[i][j].e_id, i);
//		}	
//		puts("");
//	}
////	vector<vector<bool>> vis(maxlv+1, vector<bool>(n+1));vis[0][1]=true;
////	LL ans=0;
////	FOR (j, 0, maxlv){//将所有的边反向 
////		FOR (i, 1, n){
////			if (!vis[i][j])DFS(i, j);
////		}
////	}
////	printf("%lld", ans);
//	return 0;
//}
