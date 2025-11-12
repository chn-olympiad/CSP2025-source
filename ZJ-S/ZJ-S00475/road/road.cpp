/*
woc
i forget how to write kruskal 
555555
*/
#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N = 1e6+5;

int n, m, k, xn;

struct Edge{
	int to, next, w;
	bool operator < (const Edge& oth) const{
		return w > oth.w;
	}
}edge[N << 2];

int head[N], cnt;

void addedge(int u, int v, int w){
	edge[++cnt] = {v, head[u], w};
	head[u] = cnt;
}

struct Node{
	int dis, v;
	bool operator < (const Node& oth) const{
		return dis > oth.dis;
	}
};

int dis[N];

void dijkstra(){
	memset(dis, 0x3f, sizeof dis);
	sort(edge+1, edge+m+1);
	
	priority_queue<Node> q;
	q.push({0, 1});
	dis[1] = 0;
	
	while(!q.empty()){
		Node now = q.top();q.pop();
		int u = now.v, d = now.dis;
		
		for(int i = head[u]; i != 0; i = edge[i].next){
			int v = edge[i].to, w = edge[i].w;
			if(dis[v] > d + w){
				dis[v] = d + w;
				q.push({dis[v], v});
			}
		}
	}
}

int fa[N];

int find(int x){
	return x == fa[x] ? x : fa[x] = find(x);
}

signed main(){
//	freopen("road.in", "r", stdin);
//	freopen("road.out", "w", stdout);你被骗了 
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	cin>>n>>m>>k;
	for(int i = 1; i <= m; i++){
		int u, v, w;cin>>u>>v>>w;addedge(u, v, w), addedge(v, u, w);
	}
	for(int i = 1; i <= k; i++){
		int t;cin>>t;
		for(int j = 1; j <= n; j++){
			int l;cin>>l;
			addedge(i+n, j, l);
			addedge(j, i+n, l);m++;
		}
	}n += k;
	dijkstra();
		
	int ans = 0;
	sort(dis+1, dis+n+1, greater<int>());
	for(int i = 1; i <= n/2; i++)ans += dis[i], cout<<(ans < 0 ? "s" : "");
	cout<<ans;
	
	return 0;
}
/*
我是sb
我写不出来T2
md昨天刚背的板子
一到考场上脑子里全是空白的 
准备迎接我的 AFO time 了 
——luogu 869164
*/

