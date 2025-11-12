#include<bits/stdc++.h>
#define ll long long
using namespace std;

const int MAXN = 10005;
const int MAXM = 1000005;
const int INF = 1145141919; // 并没有用到 

struct Edge {
	int u, v, w, nxt;
};
// 原有的 m 条加上 n * n * 10 条可选的 
// 太大了， 但是去掉一个数量级刚好
// 或许可以用vecter<Edge> 但是这样时间可能会炸
// 暂时不管 

// 哦， 调试的时候多加了一个参数直接炸了
// 还是用 vector 吧
vector<Edge> e; 

// 这tm是什么写法 

int n, m, k, sum = 0;
// sum 为 已经联通的道路的数量
// 给kruskal减常数用 
ll ans = 0;
int c[15];
int kr[15][MAXN]; // 村城路 
int head[MAXN], ecnt = 0;
int fa[MAXN]; // Er...?

void add(int u, int v, int w){
	e.push_back({u, v, w, head[u]});
	head[u] = ecnt, ecnt++;
	return ;
}

int find(int x) {
	return fa[x] == x ? x : fa[x] = find(fa[x]);
} 

bool cmp(Edge x, Edge y) {
	return x.w < y.w;
}

void kruskal() {
	sort(e.begin(), e.end(), cmp);
	for(Edge i : e) {  
		int u = i.u, v = i.v;
		int fu = find(u), fv = find(v);
		if (fu == fv) continue; // 忽略已联通
		fa[fv] = fa[fu]; // 不记得是fa[fv] = fa[fu] 还是fa[fu] = fa[fv] 了
		// 有什么区别吗？ 
		ans += i.w, sum++;
		if (sum == n - 1) break; // 已经建成了树 
	}
	return ;
}

signed main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m >> k;
	for(int i = 1; i <= n; i++) fa[i] = i;
	for(int i = 1; i <= m; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		add(u, v, w);
		// add(v, u, w);
	}
	for(int v = 1; v <= k; v++) {
		cin >> c[v];
		for(int j = 1; j <= n; j++) {
			int x;
			cin >> x;
			kr[v][j] = x;
		}
	}
	
	// 将村城路加入e
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= n; j++) {
			for(int v = 1; v <= k; v++) {
				add(i, j, kr[v][i] + kr[v][j] + c[v]);
				// add(j, i, kr[i][v] + kr[j][v] + c[v]);
			}
		}
	} 
	
	kruskal();
	
	cout << ans << endl;
	
	return 0;
}

/*
16:00 start
我是不是太逊了

记 kr 为题中的 a
 - 16：20 为什么我会起这样的变量？ 

若k != 0 
从 u 到 v 有最多m条路，最少一条路可以走
一定有一条直达，为u -> k -> v，需要花费kr[k][u] + c[k] + kr[k][v]
可能存在最多 m 条路 为 u -> v 需要花费 w[i]
可能存在最多 m / 2 条路， 经过其他城市，费用略 
 
这是最小生成树?
可以考虑的路除了原有的 m 条
还有可选的 k * n * n 条
每两座城之间都多 k 条路 

将这可选的全部加入，然后直接跑kruskal
好像秒了

可选的道路费用为 kr[i][k] + kr[j][k] + c[k] 

整理思路
输入
加入村城路
跑kruskal
输出 

16:15
kruskal可以单向边吗？
试试 

16:30 写完了，开始调

17:00 
在输入村庄的时候邻接矩阵不知道哪里写错了 
读出来的数据不对
日
调了我半个小时

还剩一个小时
我好逊 

*/
