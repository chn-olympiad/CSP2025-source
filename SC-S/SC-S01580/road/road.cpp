#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e6 + 7;
const int maxm = 13;

int fa[maxn];
int find(int x) {
	return (x == fa[x]) ? x : fa[x] = find(fa[x]);
}

int n, m, k;
struct node{
	int u, v;
	int e;
}b[maxn];
int c[maxm];
int a[maxm][maxn];
bool cmp(node x, node y) {
	return x.e < y.e;
}
int tot;
void work1() {
	for(int i = 1, x; i <= k; i ++) {
		for(int j = 1; j <= n; j ++)
			if(a[i][j] == 0) {
				x = j;
				break;
			}
		for(int j = 1; j <= n; j ++) {
			if(j == x) continue;
			++ tot;
			b[tot].u = j, b[tot].v = x, b[tot].e = a[i][j];
		}
	}
	sort(b + 1, b + tot + 1, cmp);
	int cnt = 0, sum = 0;
	for(int i = 1; i <= tot; i ++) {
		int x = b[i].u, y = b[i].v, z = b[i].e;
		int fx = find(fa[x]), fy = find(fa[y]);
		if(fx != fy) {
			cnt ++;
			sum += z;
			fa[fy] = fx;
			if(cnt == tot - 1) break;
		}
	} 
	cout << sum;
}
int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	cin >> n >> m >> k;
	for(int i = 1; i <= n; i ++) fa[i] = i;
	tot = m;
	for(int i = 1, x, y, z; i <= m; i ++) {
		cin >> x >> y >> z;
		b[i].u = x, b[i].v = y, b[i].e = z;
	}
	bool flag = 0;
	for(int i = 1; i <= k; i ++) {
		cin >> c[i]; 
		for(int j = 1; j <= n; j ++) cin >> a[i][j];
		if(c[i] != 0) flag = 1;
	}
	if(flag == 0) {
		work1();
		return 0;
	}
	sort(b + 1, b + m + 1, cmp);
	
	int cnt = 0, sum = 0;
	for(int i = 1; i <= m; i ++) {
		int x = b[i].u, y = b[i].v, z = b[i].e;
		int fx = find(fa[x]), fy = find(fa[y]);
		if(fx != fy) {
			cnt ++;
			sum += z;
			fa[fy] = fx;
			if(cnt == m - 1) break;
		}
	} 
	cout << sum;
	return 0;
}
/*
4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
0 1 0 2 4
0 1 3 2 0


*/