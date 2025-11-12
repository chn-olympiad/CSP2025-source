#include <bits/stdc++.h>
using namespace std;
#define int long long
int read(){
	int x = 0;
	char ch = getchar();
	while(!isdigit(ch))
		ch = getchar();
	while(isdigit(ch)){
		x = x * 10 + (ch - '0');
		ch = getchar();
	}
	return x;
}
const int N = 2e4 + 9, M = 1e6 + 9;
struct Edge{
	int u, v, w;
} e[M], e2[N], e3[N * 2];
bool cmp(Edge x, Edge y){
	return x.w < y.w;
}
int fa[N], a[19][N], c[N], n, m, k, tot, ans, sum, num;
int find(int x){
	return fa[x] == x ? x : fa[x] = find(fa[x]);
}
signed main(){
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	n = read();
	m = read();
	k = read();
	for(int i = 1; i <= m; i++){
		e[i].u = read();
		e[i].v = read();
		e[i].w = read();
	}
	sort(e + 1, e + m + 1, cmp);
	for(int i = 1; i <= n; i++)
		fa[i] = i;
	for(int i = 1; i <= m; i++){
		int u = e[i].u, v = e[i].v;
		if(find(u) != find(v)){
			fa[find(u)] = find(v);
			sum += e[i].w;
			e2[++tot] = e[i];
		}
		if(tot == n - 1)
			break;
	}
	for(int i = 1; i <= k; i++){
		c[i] = read();
		for(int j = 1; j <= n; j++)
			a[i][j] = read();
	}
	ans = sum;
	for(int s = 1; s < (1 << k); s++){
		sum = num = 0;
		for(int i = 1; i < n; i++)
			e3[i] = e2[i];
		for(int i = 1; i <= n + k; i++)
			fa[i] = i;
		tot = n - 1;
		for(int i = 1; i <= k; i++){
			if(s >> (i - 1) & 1){
				for(int j = 1; j <= n; j++)
					e3[++tot] = Edge{i + n, j, a[i][j]};
				sum += c[i];
				num++;
			}
		}
		sort(e3 + 1, e3 + tot + 1, cmp);
		int cnt = 0;
		for(int i = 1; i <= tot; i++){
			int u = e3[i].u, v = e3[i].v;
			if(find(u) != find(v)){
				fa[find(u)] = find(v);
				sum += e3[i].w;
				cnt++;
			}
			if(cnt == n + num - 1)
				break;
		}
		ans = min(ans, sum);
	}
	printf("%lld", ans);
	return 0;
}