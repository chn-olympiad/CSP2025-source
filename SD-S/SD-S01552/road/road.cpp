#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define pii pair<int, int>
#define fi first
#define se second
#define ls (root << 1)
#define rs (root << 1 | 1)
#define fastio ios :: sync_with_stdio(false);\
			   cin.tie(nullptr);\
			   cout.tie(nullptr);
			   
using namespace std;

const int maxn = 2e4 + 10;
const int maxm = 2.2e6 + 10;

struct node{
	int u, v, w;
	bool tag;
}e[maxm];

int n, m, num, tot; // num 即题面中 k  
ll cnt, ans, idx; // cnt 当前生成树中的边数  ans 最小边权 
// idx: 加入的虚拟点的数量 
int fa[maxn], c[maxn];
bool vis[20];

int findfa(int x){
	return (fa[x] == x ? x : fa[x] = findfa(fa[x]));
}

bool cmp(node a, node b){
	return a.w < b.w;
}

void kruskal(){
	for(int i = 1; i <= tot; i++){
		int u = e[i].u, v = e[i].v;
		int fu = findfa(u), fv = findfa(v);
		if(fu == fv) continue;
		else{
//			cerr << u << ' ' << v << ' ' << e[i].w << endl;
			if(e[i].tag == 1 && !vis[u - n]){
				idx++; // 加入当前的虚拟节点  
				ans += c[u - n]; // 要建设这个点 
				vis[u - n] = 1; // 这个点已经被建成了 
			} 
			cnt++; // 加一条边  
			fa[fu] = fv; // 合并当前两点到同一连通块内
			ans += 1ll * e[i].w;
			if(e[i].tag == 1) ans -= 1ll * c[u - n];
			if(cnt == n - 1 + idx) return;  
		}
	}
}

signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	fastio
	cin >> n >> m >> num;
	for(int i = 1; i <= n + 100; i++)
		fa[i] = i; // 并查集初始化 
	for(int i = 1; i <= m; i++){
		cin >> e[i].u >> e[i].v >> e[i].w;
		e[i].tag = 0;
	}
	tot = m;
	if(num == 0){
//		cerr << num << endl;
		sort(e + 1, e + 1 + m, cmp);
		kruskal();
		cout << ans << endl;
		return 0;
	}
	tot = m; 
	for(int i = 1; i <= num; i++){
		cin >> c[i];
		for(int j = 1; j <= n; j++){
			cin >> e[++tot].w;
			e[tot].w += c[i];
			e[tot].u = i + n, e[tot].v = j;
			e[tot].tag = 1;
		}
	}
	sort(e + 1, e + 1 + tot, cmp);
	kruskal(); 
	cout << ans << endl;
	return 0;
}
/*
4 4 2
1 4 6 
2 3 7 
4 2 5 
4 3 4
1 1 8 2 4
100 1 3 2 4
*/
