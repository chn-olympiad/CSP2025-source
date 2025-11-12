#include<bits/stdc++.h>
using namespace std;

const int N = 1010, M = 1100000, K = 15;
int n, m, cnt, k;
int c[K];
int village[K][N];
int fa[N];
int mapp[N][N];

struct Edge{
	int a, b, w;
	bool operator < (const Edge &x) const
	{
		return w < x.w;
	}
}edge[N];

int find(int x){
	return fa[x] == x ? x : fa[x] = find(fa[x]);
}

int kruskal(){
	int res = 0;
	sort(edge + 1, edge + cnt + 1);
	for(int i = 1; i <= n; i ++)
		fa[i] = i;
	for(int i = 1; i <= cnt; i ++){
		int x = find(edge[i].a), y = find(edge[i].b);
		if(x != y)
			res += edge[i].w, fa[x] = fa[y];
	}
	return res;
}

int main(){
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);

	scanf("%d%d%d", &n, &m, &k);
	
	cnt = m;
	memset(mapp, 0x3f, sizeof mapp);
	for(int i = 1; i <= m; i ++){
		int u, v, w;
		scanf("%d%d%d", &u, &v, &w);
		mapp[u][v] = mapp[v][u] = w;
	}
		
	if(k == 0){
		printf("%d\n", kruskal());
		return 0;
	}
		
	for(int i = 1; i <= k; i ++){
		cin >> c[i];
		for(int j = 1; j <= n; j ++){
			int x;
			cin >> x;
			village[i][j] = x;
		}
	}

	
	for(int i = 1; i <= n; i ++)
		for(int j = 1; j < i; j ++){
			int minn = mapp[i][j];
			for(int t = 1; t <= k; t ++)
				if(village[t][i] + village[t][j] < minn)
					minn = village[t][i] + village[t][j];
			edge[++ cnt] = {i, j, minn};
		}
	
	
	
	printf("%d\n", kruskal());
	
	return 0;
}