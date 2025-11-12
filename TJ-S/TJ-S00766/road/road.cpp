#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 2000099;
int n, m, k;
int c[15], a[15][10999];
int h[N], ne[N], e[N], w[N], tot;

void addedge(int u, int v, int cost){
	ne[++tot] = h[u];
	h[u] = tot;
	e[tot] = v;
	w[tot] = cost;
	return ;
}

bool vis[600][N];
struct node{
	int from, idx, val;
	bool operator < (node a) const{
		return val > a.val;
	}
};

ll solve(int town){
	priority_queue<node> ed;
	for(int i = h[1];i != 0;i = ne[i]){
		ed.push((node){1, i, w[i]});
	}
	int t = 1, point_ = 1;
	while(t <= town){
		if(t > town) break;
		//cout << t <<" " << point_ <<endl;
		if(t & town){
			if(!vis[town][n + point_]){
				//printf("from %d -> %d, cost %d\n", 1, point_, a[point_][1]);
				ed.push((node){n + point_, a[point_][1], a[point_][1]});
			}
		}
		t <<= 1;
		point_++;
	}
	ll cost = 0;
	vis[town][1] = true;
	while(!ed.empty()){
		node f = ed.top();
		ed.pop();
		int p;
		if(f.from <= n){
			p = e[f.idx];
			if(vis[town][p]) continue;
			vis[town][p] = true;
			cost += w[f.idx];
		} else{
			if(f.from >= n + 99){
				//从城镇来 
				//cout <<"to" << f.idx << "\n";
				f.from -= n + 99;
				p = f.from;
				if(vis[town][p]) continue;
				vis[town][p] = true;
				cost += f.idx;
			} else{ //到城镇 
				//cout <<"go\n";
				p = f.from - n;
				if(vis[town][f.from]) continue;
				vis[town][f.from] = true;
				cost += f.idx;
			}
		}
		
		//城市到城市 
		for(int i = h[p];i != 0 && f.from <= n;i = ne[i]){
			if(!vis[town][e[i]]){
				ed.push((node){p, i, f.val + w[i]});
			}
		}
		
		//村庄到城市 
		if(f.from > n){
			for(int i = 1;i <= n;i++){
				if(!vis[town][i]){
					ed.push((node){n + 99 + i, a[p][i], f.val + a[p][i]});
				}
			}
		}
		
		//去村庄  
		if(f.from <= n){
			int t = 1, point_ = 1;
			while(t <= town){
				if(t > town) break;
				//cout << t <<" " << point_ <<endl;
				if(t & town){
					if(!vis[town][n + point_]){
						//printf("from %d -> %d, cost %d\n", p, point_, f.val + a[point_][p]);
						ed.push((node){n + point_, a[point_][p], f.val + a[point_][p]});
					}
				}
				t <<= 1;
				point_++;
			}
		}
		
	}
	return cost;
}

int main(){
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	cin >> n >> m >> k;
	for(int i = 1;i <= m;i++){
		int u, v, cost;
		cin >> u >> v >> cost;
		addedge(u, v, cost);
		addedge(v, u, cost);
	}
	for(int i = 1;i <= k;i++){
		cin >> c[i];
		for(int j = 1;j <= n;j++){
			cin >> a[i][j];	
		}
	}
	int ans = 1e9;
	for(int t = 0;t <= pow(2, k) - 1;t++){
		int cost = solve(t);
		int point_ = 1, tt = 1;
		
		while(tt <= t){
			if(tt & t){
				cost += c[point_];
			}
			tt <<= 1;
			point_++;
		}
		//cout << cost << endl;
		ans = min(ans, cost);
	}
	cout << ans << endl;
	return 0;
}














