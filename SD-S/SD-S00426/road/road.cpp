#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;
const int maxn = 1e4 + 5;
vector < int > G[maxn] , val[maxn];
int vis[maxn];
int a[15][maxn]; int n , m , k ; int c[15];
struct Node {
	int x , val;
	friend bool operator < (Node x , Node y){
		return x.val > y.val;
	}
}; long long min_1 = 9e18 ;
void prim(vector < int > chose){
	memset(vis , 0 , sizeof vis);
	priority_queue < Node > Q;
	for(int i = 0 ; i < chose.size() ; i ++) Q.push({-chose[i] - n , 0});
	if(chose.empty()) Q.push({1 , 0});
	long long ans = 0;
	for(int i = 1 ; i <= n + chose.size() ; i ++){
		Node u = Q.top() ; Q.pop();
		if(vis[u.x] == 1) {
			i -- ; continue;
		}
		if(u.x < 0) {
			u.x = -u.x;
			for(int j = 1 ; j <= n ; j ++) Q.push({j , a[u.x - n][j]});
			continue;
		}
		ans += u.val; vis[u.x] = 1;
		for(int j = 0 ; j < G[u.x].size() ; j ++) {
			int v = G[u.x][j] , w = val[u.x][j];
			if(vis[v] == 1) continue;
			Q.push({v , w});
		}
	} for(int i = 0 ; i < chose.size() ; i ++) ans += c[chose[i]];
	min_1 = min(min_1 , ans);
}int maxc = 0; 
void dfs(int x , vector < int > chose){
	if(x > k) {
		if(maxc == 0 && chose.size() >= k) prim(chose);
		else if(maxc != 0) prim(chose);
		return;
	}
	dfs(x + 1 , chose);
	chose.push_back(x);
	dfs(x + 1 , chose);
}
signed main(){
	ios :: sync_with_stdio(0) ; cin.tie(0) ; cout.tie(0); 
	freopen("road.in" , "r" , stdin);
	freopen("road.out" , "w" , stdout);
	cin >> n >> m >> k;
	for(int i = 1 ; i <= m ; i ++) {
		int u , v , w ; cin >> u >> v >> w;
		G[u].push_back(v) ; val[u].push_back(w);
		G[v].push_back(u) ; val[v].push_back(w); 
	} 
	for(int i = 1 ; i <= k ; i ++) {
		cin >> c[i];
		maxc = max(maxc , c[i]); 
		for(int j = 1 ; j <= n ; j ++) cin >> a[i][j];
	} vector < int > ept; 
	dfs(1 , ept); cout << min_1 << endl; 
	return 0;
} 
