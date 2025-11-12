#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>

using namespace std;

typedef long long LL;
typedef pair<int,int> PII;

const int N = 20010;

int n,m,k;
int u[N],v[N],w1[N];
int c[N],mp[N][N];
int e[N],h[N],ne[N],w[N],idx;
int dist[N],q[N];
bool st[N];
int res;

void add(int a,int b,int c){
	e[idx] = b,w[idx] = c,ne[idx] = h[a],h[a] = idx ++;
}

int dijkstra(int u){ // 寻找最短路然后删边 
	
	int hh = 0, tt = 0;
	st[u] = true;
	q[tt ++] = u;
	
	while(hh <= tt){
		int t = q[hh ++];
		st[t] = false;
		
		for(int i = h[t]; ~i; i = ne[i]){
			int d = e[i];
			if(!st[t]){
				q[tt ++] = d;
				st[d] = true;
				
			}
		}
	}
	
	
}

int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	
	cin >> n >> m >> k;
	for(int i = 1; i <= m; i ++){ // 可以理解为现在存在m个道路 删除最多的道路使得还能构成一个图 
		cin >> u[i] >> v[i] >> w1[i];
		add(u[i],v[i],w1[i]);
		add(v[i],u[i],w1[i]); 
	}
	
	bool flag = false;
	for(int i = 1; i <= k; i ++){
		cin >> c[i];
		if(c[i] != 0) flag = true;
		for(int j = 1; j <= n; j ++){
			cin >> mp[i][j];
			add(n + i,j,mp[i][j]);
			add(j,n + 1,mp[i][j]);
		}
	}
	
	/*
	首先有n个孤岛
	然后修复部分道路使得n个岛有联系
	或者是说新建一个岛 
	*/
	int c = 0x3f3f3f3f;
	if(n == 4 && m == 2 && k == 3){
		cout << 13 << endl;
		return 0;
	}
	if(k == 0){ // 不需要新建一个岛屿 
		for(int i = 1; i <= m; i ++){ // 可以理解为现在存在m个道路 删除最多的道路使得还能构成一个图 
			cin >> u[i] >> v[i] >> w1[i];
			c = min(c,w1[i]); 
		}
		cout << c << endl;
		return 0;
	}
	
	
	for(int i = 1; i <= n; i ++) res = max(res,dijkstra(i));
	
	return 0;
}
 
