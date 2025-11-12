#include<bits/stdc++.h>

using namespace std;

const int INF = 0x3f3f3f3f;

struct node{
	int to;
	int k;
	int p;
	bool friend operator<(node a, node b){
		return a.k > b.k;
	}
};

bool cmp(node a, node b){
	return a.p < b.p;
}

int n, m, k;
vector<node> a[10010];
node arr[10010];
int f[10010];
int bj[10010];
int fa[10010];

void dij(){
	for(int i = 0; i <= 10001; i++){
		f[i] = INF;
	}
	priority_queue<node> q;
	q.push({1, 0, 0});
	f[1] = 0;
	while(!q.empty()){
		node k = q.top();
		q.pop();
		if(bj[k.to] == 1){
			continue;
		}
		bj[k.to] = 1;
		for(int i = 0; i < a[k.to].size(); i++){
			node v = a[k.to][i];
			if(f[v.to] > f[k.to] + v.k){
				f[v.to] = f[k.to] + v.k;
				q.push({v.to, f[v.to], 0});
			}
		}
	}
	int c = f[1];
	for(int i = 1; i <= n; i++){
		c = max(c, f[i]);
	}
	cout << c << endl;
	return;
}

int find(int x){
	if(fa[x] == x){
		return x;
	}
	fa[x] = find(fa[x]);
	return fa[x];
}

int main(){
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	cin >> n >> m >> k;
	for(int i = 1; i <= m; i++){
		int x, y, z;
		cin >> x >> y >> z;
		a[x].push_back({y, z, 0});
		a[y].push_back({x, z, 0});
		arr[i] = {x, y, z};
	}
	for(int i = 1; i <= k; i++){
		for(int j = 1; j <= n; j++){
			int x, y;
			cin >> x >> y;
		}
	}
	if(k >= 1){
		dij();
		return 0;
	}
	int c = 0;
	sort(arr + 1, arr + n + 1, cmp);
	for(int i = 1; i <= n; i++){
		fa[i] = i;
	}
	for(int i = 1; i <= m; i++){
		int x = find(arr[i].to);
		int y = find(arr[i].k);
		if(x != y){
			fa[x] = y;
			c += arr[i].p;
		}
	}
	cout << c << endl;




	return 0;
}
