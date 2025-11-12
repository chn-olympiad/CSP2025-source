// road.cpp

/*
首先如果k=0，那么就是裸的最小生成树  +16pts

特殊性质A：c[j]=0意味着可以无偿把所有未建的点全部城市化
此时会多出10n条虚边。考虑对原有的边加上这些边跑最小生成树即可  +32pts




否则，考虑按照边权从大到小依次枚举最小生成树上的边，然后把k个城市化改造的都扫一遍算最小花费

具体地，考虑把当前边的两个端点都尝试用城市化改造k来更新，在a[k]中找到除了当前端点以外的最小值替换（可以用ST表维护最小、次小值，如果最小值是当前端点就算最小值） 

后来发现不用ST表，直接预处理时按照值对下标排序即可 

注意还要同时记录每个可城市化的点 在之前已经花了多少钱了，为了防止更新错乱 

时间复杂度为O(mk + n + nk) <= 1e8


目前得分：(48+?)pts 
*/

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e4 + 7, M = 1e6 + 7;

int n, m, k; 
ll a[20][N]; // a数组用来存k的信息  a[i][0]表示城市化改造的花费 
int b[20][N]; // 存按照a数组升序排序的下标 

struct Edge{
	int from, to; ll val; int nxt;
	friend bool operator < (Edge p1, Edge p2){
		return p1.val < p2.val;
	}
}E[2*M];

int head[2*N], Ecnt;

void add(int u, int v, int w){
	E[++Ecnt] = {u, v, w, head[u]};
	head[u] = Ecnt;
}

int dsu[2*N];
int find(int x){
	return dsu[x]==x? x : dsu[x]=find(dsu[x]);
}
void merge(int x, int y){
	int fx = find(x), fy = find(y);
	if(fx != fy){
		if(fx < fy) swap(fx, fy);
		dsu[fx] = fy;
	}
}

int nowl = 0; // 为了方便b数组排序 

bool cmp2(int x, int y){
	return a[nowl][x] < a[nowl][y];
}

//int vis[2*M]; // 记录边的组合是否访问过 

ll pre[20]; // 记录每个城市化改造的点之前已经花费了多少 

void solve()
{
	Ecnt = nowl = 0;
	cin >> n >> m >> k;
	for(int i = 1; i <= 2*n; i ++) dsu[i] = i, head[i] = 0;
	for(int i = 1; i <= m; i ++){
		int u, v, w; cin >> u >> v >> w;
		add(u, v, w); 
//		add(v, u, w);
	}
	
	bool flagA = true; // 特殊性质A：满足所有a[i][0]==0 
	for(int i = 1; i <= k; i ++){
		pre[i] = 0;
		for(int j = 0; j <= n; j ++){
			cin >> a[i][j]; b[i][j] = j;
		}
		if(a[i][0] != 0) flagA = false;
		nowl = i;
		sort(b[i] + 1, b[i] + n + 1, cmp2);
	}
	
	if(flagA){
//		cerr << "flagA\n";
		for(int i = 1; i <= k; i ++){
			for(int j = 1; j <= n; j ++){
				add(n+i/*虚点的编号*/, j, a[i][j]);
			}
		}
		sort(E + 1, E + Ecnt + 1);
	
		ll ans = 0; // 记录答案 
		vector<int> id;
		for(int i = 1; i <= Ecnt; i ++){
			int u = E[i].from, v = E[i].to, w = E[i].val;
//			cerr << u << ' ' << v << ' ' << (find(u)==find(v)) << '\n';
			if(find(u) == find(v)) continue;
			ans += w; merge(u, v); id.push_back(i);
		}
		
		cout << ans << '\n';
		
//		for(auto it : id){
//			cerr << E[it].from << ' ' << E[it].to << ' ' << E[it].val << '\n';
//		}
		
		return ;
	}
	
	sort(E + 1, E + Ecnt + 1);
	
	ll ans = 0; // 记录答案 
	vector<int> id; // 记录最小生成树中边的编号 
	for(int i = 1; i <= Ecnt; i ++){
		int u = E[i].from, v = E[i].to, w = E[i].val;
		if(find(u) == find(v)) continue;
		id.push_back(i); ans += w; merge(u, v);
	}
	
	if(k == 0){
		cout << ans << '\n'; return ; // k=0就是裸的MST 
	}
	
//	for(int i = 0; i <= Ecnt; i ++) vis[i] = 0;
	for(int i = id.size()-1; i >= 0; i --){ // 按照边权从大到小枚举要尝试替换的MST上的边 
		int u = E[id[i]].from, v = E[id[i]].to, w = E[id[i]].val;
		ll minn = 1e18; int pos = -1;
		for(int j = 1; j <= k; j ++){ // 枚举可以城市化改造的点
			ll c = pre[j] + a[j][0] + a[j][u] + (b[j][1]==u? a[j][b[j][2]] : a[j][b[j][1]]);
			if(minn > c) minn = c, pos = j;
		}
		// 尝试替换 
		ll newans1 = ans - w + minn; int aa, bb;
		if(newans1 < ans){
			aa = u, bb = (b[pos][1]==u? b[pos][2] : b[pos][1]);
//			a[pos][0] = a[pos][u] = a[pos][(b[j][1]==u? b[j][2] : b[j][1])] = 0; // 如果更小就替换，并把这些代价都换成0 
		}
		
		#ifdef DEBUG
		cerr << "min1:" << minn << '\n';
		#endif
		
		// 交换端点再来一次 
		swap(u, v);
		minn = 1e18; int pos2 = -1;
		for(int j = 1; j <= k; j ++){ // 枚举可以城市化改造的点
			ll c = pre[j] + a[j][0] + a[j][u] + (b[j][1]==u? a[j][b[j][2]] : a[j][b[j][1]]);
			if(minn > c) minn = c, pos2 = j;
		}
		
		#ifdef DEBUG
		cerr << "min2:" << minn << '\n';
		
		cerr << "w:" << w << " ans:" << ans << '\n';
		#endif
		
		// 尝试替换 
		ll newans2 = ans - w + minn;
		if(newans2 < ans || newans1 < ans){
			if(newans2 < newans1){
				ans = newans2;
				pre[pos2] = newans2 - ans + w;
				a[pos2][0] = a[pos2][u] = a[pos2][(b[pos2][1]==u? b[pos2][2] : b[pos2][1])] = 0; // 如果更小就替换，并把这些代价都换成0 
			}
			else{
				ans = newans1;
				pre[pos] = newans1 - ans + w;
				a[pos][0] = a[pos][aa] = a[pos][bb] = 0;
			}
			
			#ifdef DEBUG
			cerr << "done.\n";
			#endif
		}
		
		#ifdef DEBUG
		cerr << id[i] << ' ' << v << ' ' << u << ' ' << newans1 << ' ' << newans2 << '\n';
		#endif
	}
	
	cout << ans << '\n';
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(0), cout.tie(0);
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	solve();
	return 0;
}

/*
4 4 0
1 4 6
2 3 7
4 2 5
4 3 4
*/

