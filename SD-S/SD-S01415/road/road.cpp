# include <iostream>
# include <cstring>
# include <cstdio>
# include <algorithm>
# include <queue>
# include <vector>
# include <functional>
using namespace std;
const int N = 1e4 + 5;
struct node{
	int to , w;	
	bool operator < (const node y) const{
		return w > y.w;
	}
};
int n , m , k , mk[N + 20] , dis[N + 20] , ans , c[20] , pre[N];
vector<node> e[N + 20];
priority_queue<node> q;
void add(int u , int v , int w){
	e[u].push_back({v , w});
	e[v].push_back({u , w});
}
int main(){
	freopen("road.in" , "r" , stdin);
	freopen("road.out" , "w" , stdout);
	memset(dis , 0x7f , sizeof(dis));
	cin >> n >> m >> k;
	for(int i = 1 ; i <= m ; i++){
		int x , y , z;
		cin >> x >> y >> z;
		add(x , y , z);
	}
	for(int i = 1 ; i <= k ; i++){
		cin >> c[i];
		for(int j = 1 ; j <= n ; j++){
			int w;
			cin >> w;
			add(n + i , j , w);
		}
	}
	dis[1] = 0;
	q.push({1 , 0});
	while(q.size()){
		node u = q.top();q.pop();
		if(dis[u.to] < u.w) continue;
		for(int i = 0 ; i < e[u.to].size() ; i++){
			node v = e[u.to][i];
			int cost = u.w + v.w;
			if(v.to > n){
				cost += c[v.to - n];
			}
			if(cost < dis[v.to]){
				dis[v.to] = cost;
				pre[v.to] = u.to;
				mk[v.to] = v.w;
				q.push({v.to , dis[v.to]});
			}
		}
	}
	for(int i = 1 ; i <= n ; i++){
		ans += mk[i];
		cout << i << " " << mk[i] << " " << pre[i] << " ";
		if(pre[i] > n){
			ans += c[pre[i] - n];
			c[pre[i] - n] = 0;
			cout << c[pre[i] - n];
		} 
		cout << endl;
	}
	cout << ans;
	
	return 0;
}
