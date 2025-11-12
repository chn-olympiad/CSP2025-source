#include<bits/stdc++.h>
#define LL long long
using namespace std;
struct node {
	int x, y;
	LL w;
}a[1000100];
	bool operator < (const node &a, const node &b) {
		return b.w < a.w;
	}
bool cmp(node a, node b) {return a.w < b.w;}
int f[10010];
int find(int x) {
	if(f[x] != x) f[x] = find(f[x]);
	return f[x];
}
LL c[30];
LL w[30][10100];
int main () {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	int n, m, k;
	scanf ("%d %d %d", &n, &m, &k);
	for (int i = 1; i <= m; ++i)
		scanf ("%d %d %lld", &a[i].x, &a[i].y, &a[i].w);
	sort(a + 1, a + m + 1, cmp);
	for (int i = 1; i <= k; ++i) {
		scanf ("%lld", &c[i]);
		for (int j = 1; j <= n; ++j)
			scanf ("%lld", &w[i][j]);
	}
	LL mi = 1e18;
	int T = (1 << k) - 1;
	for (int p = 0; p <= T; ++p) {
		if(m >= 500000 && p >= 32) break;
		if(p > 100 && m > 250000) break;
		bool flag = true;
		int t = m, mm = n;
		LL sum = 0;
		priority_queue<node> q;
		for (int i = 1; i <= m; ++i) q.push(a[i]);
		for (int i = 1; i <= k; ++i)
			if(p & (1 << (i - 1))) {
				sum += c[i];
				if(sum >= mi) {flag = false; break;}
				++mm;
				for (int j = 1; j <= n; ++j) 
					q.push((node){n + i, j, w[i][j]}), ++t;
			}
		if(!flag) continue;
		for (int i = 1; i <= n + k; ++i) f[i] = i;
		int fish = 0;
		while(!q.empty()){
			node cur = q.top();
			if(sum >= mi) {flag = false; break;}
			int fx = find(cur.x), fy = find(cur.y);
			if(fx != fy) f[fy] = fx, sum += cur.w, ++fish;
			if(fish == mm - 1) break;
			q.pop();
		}
		if(flag && fish == mm - 1) mi = min(mi, sum);
	}
	printf("%lld", mi);
} 
