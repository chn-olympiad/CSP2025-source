#include <bits/stdc++.h>
#define int long long
#define min(x, y) ((x) < (y) ? (x) : (y))
#define max(x, y) ((x) > (y) ? (x) : (y))
using namespace std;

int n, m, k, c[15], b[15][10050];
struct edge{
	int x;
	int y;
	int v;
}e[1000050];

int f[10050];

int find(int x){
	if(f[x] == x) return x;
	return f[x] = find(f[x]);
}

int cmp(edge a, edge b){
	return a.v < b.v;
}

int kruskal(){
	sort(e + 1, e + m + 1, cmp);
	int cnt = m - 1, ans = 0;
	for(int i = 1;i <= m;i ++){
		int x = e[i].x, y = e[i].y, v = e[i].v;
		if(!cnt) break;
		if(find(x) == find(y)) continue;
		f[f[x]] = f[y];
		ans += v;
		cnt --;
//		for(int i = 1;i <= n;i ++) cout << f[i] << " ";
	}
	return ans;
}

signed main(){
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	cin >> n >> m >> k;
	for(int i = 1;i <= m;i ++){
		cin >> e[i].x >> e[i].y >> e[i].v;
	}
	for(int i = 1;i <= k;i ++){
		cin >> c[i];
		for(int j = 1;j <= n;j ++) cin >> b[i][j];
	}
	for(int i = 1;i <= n;i ++) f[i] = i;
	cout << kruskal();
	fclose(stdin);
	fclose(stdout);
	return 0;
}
