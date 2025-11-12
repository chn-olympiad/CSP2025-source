#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e4 , maxm = 1e6;

struct Node {
	int u , v , w;
	bool operator < (const Node &A) const {
		return w < A.w;
	}
} ;

int n , m , k;
int c[15] , a[15][maxn + 5];
Node edge[maxm + 5];
vector<Node> edge0;
int fa[maxn + 5] , f[maxn + 5][15];

int findset(int x) {
	if (fa[x] == x) return fa[x];
	return fa[x] = findset(fa[x]);
}

int main() {
	freopen("road.in" , "r" , stdin);
	freopen("road.out" , "w" , stdout);
	scanf ("%d%d%d" , &n , &m , &k);
	for (int i = 1; i <= m; i++)
		scanf ("%d%d%d" , &edge[i].u , &edge[i].v , &edge[i].w);
	for (int i = 1; i <= k; i++) {
		scanf ("%d" , &c[i]);
		for (int j = 1; j <= n; j++)
			scanf ("%d" , &a[i][j]);
	}
	for (int i = 1; i <= n; i++) fa[i] = i;
	sort(edge + 1 , edge + m + 1);
	long long sum = 0 , ans = 0;
	for (int i = 1; i <= m; i++) {
		int x = findset(edge[i].u) , y = findset(edge[i].v);
		if (x == y) continue;
		sum += edge[i].w;
		fa[x] = y;
		edge0.push_back(edge[i]);
	}
	ans = sum;
	for (int mak = 0; mak < (1 << k); mak++) {
		long long t = sum;
		for (int i = 0; i < k; i++)
			t += ((mak >> i) & 1) * c[i + 1];
		for (int i = 1; i <= n; i++) fa[i] = i;
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= k; j++)
				f[i][j] = a[j][i];
		for (auto i : edge0) {
			int x = findset(i.u) , y = findset(i.v);
			if (x == y) {
				t -= i.w;
				continue;
			}
			fa[y] = x;
			int mi = 2e9 + 1 , id = 0;
			for (int j = 0; j < k; j++) if ((mak >> j) & 1) 
				if (f[x][j + 1] + f[y][j + 1] < mi)
					mi = f[x][j + 1] + f[y][j + 1] , id = j + 1;
			for (int j = 0; j < k; j++) if ((mak >> j) & 1) 
				f[x][j + 1] = min(f[x][j + 1] , f[y][j + 1]);
			if (mi <= i.w) {
				t = t - i.w + mi;
				f[x][id] = 0;
			}
		}
		ans = min(ans , t);
	}
	printf ("%lld\n" , ans);
}
/*
5182974424
*/
