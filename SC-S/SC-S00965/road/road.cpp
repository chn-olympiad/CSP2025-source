#include<bits/stdc++.h>
#define ll long long
#define endl '\n'
using namespace std;
const int maxn = 2e5 + 55, mod = 998244353, inf = 2147483647;
const double pi = acos(-1);
int T;
int n, m, k, ans;
bool used[maxn];
//struct edge{
//	int to, w, a;
//	bool operator < (const edge &other) const{
//		return w > other.w;
//	}
//};
//vector<edge> e[maxn];
//void dijk(int u){
//	priority_queue<edge> q;
//	q.push({u, 0});
//	used[u] = 1;
//	while(!q.empty()){
//		auto now = q.top();
//		if(used[now]) continue;
//		used[now] = 1;
//		q.pop();
//		for(auto v : e[now]){
//			int y = v.to;
//		}
//	}
//}
int main(){
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	cin >> n >> m >> k;
	for(int i = 1, u, v, w;i <= m;i ++){
		cin >> u >> v >> w;
		ans += w;
	}
	for(int j = 1, u;j <= k;j ++){
		cin >> u;
	} 
	cout << ans;
	return 0;
}