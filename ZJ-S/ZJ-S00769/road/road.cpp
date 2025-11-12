#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e4 + 20, M = 2e6 + 20;

int n, m, k, c[20], a[20][N];
//原有城市数量、道路数量和准备进行城市化改造的乡镇数量
struct node{
	int u, v, w;
	bool friend operator < (node x, node y){
		return x.w < y.w;
	}
}edge[M];
int num, pos[20];

int fa[N];
int find(int x){
	if(x != fa[x])  fa[x] = find(fa[x]);
	return fa[x];
}

int kruskal1(){
	int cnt = 0, tot = 0;
	sort(edge + 1, edge + m + 1);
	for(int i = 1; i <= m; i++){
		int u = find(edge[i].u), v = find(edge[i].v);
		if(u == v)  continue;
		fa[u] = v;
		cnt++;
		tot += edge[i].w;
		if(cnt == n - 1)  break;
	}
	return tot;
}
int state;
int kruskal2(){
	int cnt = 0, tot = 0;
	sort(edge + 1, edge + num + 1);
	for(int i = 1; i <= num; i++){
		int u = find(edge[i].u), v = find(edge[i].v);
		if(u == v)  continue;
		fa[u] = v;
		cnt++;
		tot += edge[i].w;
		if(cnt == n - 1)  break;
	}
	return tot;
}

int read(){
	int x = 0;
	char ch = getchar();
	while(ch < '0' || ch > '9'){
		ch = getchar();
	}
	while(ch >= '0' && ch <= '9'){
		x = x * 10 + (ch - '0');
		ch = getchar();
	}
	return x;
}

signed main(){
//	cin.tie(0) -> sync_with_stdio(0);

	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);

	cin >> n >> m >> k;
	for(int i = 1; i <= m; i++){
		edge[i].u = read();
		edge[i].v = read();
		edge[i].w = read();
	}
	
	if(k == 0){
		for(int i = 1; i <= n; i++)  fa[i] = i;
		cout << kruskal1();
		return 0;
	}
	
	for(int i = 1; i <= k; i++){
		cin >> c[i];
		int mn = INT_MAX;
		for(int j = 1; j <= n; j++){
			a[i][j] = read();
			if(a[i][j] < mn){
				mn = a[i][j];
				pos[i] = j;
			}
		}
	}
	num = m;
	for(int i = 1; i <= k; i++){
		int p = pos[i];
		for(int j = 1; j <= n; j++){
			if(j == p)  continue;
			edge[++num].u = j;
			edge[num].v = p;
			edge[num].w = c[i] + a[i][p] + a[i][j];
		}
	}
	for(int i = 1; i <= n; i++)  fa[i] = i;
	cout << kruskal2();
	return 0;
}
/*
第一眼感觉像最小生成树，并查集应该是可以的 
发现 n方是被允许的，那是不是可以对于两城市之间再建 k 条经过乡镇的边再跑最小生成树，期间记录经过的乡镇编号   后来发现错了 
时间 O(knn) 1e9  空间 1e8 的 long long 有点悬 考虑能不能优化
k 很小，是不是可以状压优化  不会

由特殊性质 A 可以想到 city1 - town - city2 的路径我们可以全部变为 citymin - town - cityx 的路径
应该是对的吧  时间减少为 O(nk)建图  还是不对
如何处理 c[town] 的重复贡献 
*/
