#include <bits/stdc++.h>
using namespace std;
const int M = 1e6 +  1e4 + 10;
const int N = 1e4 + 10;
int n, m, k, f[N], cnt, toxu;
long long ans;

int find(int x){
	if(x == f[x]) return x;
	else{
		f[x] = find(f[x]);
		return f[x];
	}
}

void merge(int x, int y){
	int tx = find(x);
	int ty = find(y);
	if(tx != ty){
		f[tx] = ty;
	}
}

struct edge{
	int u, v, w;
}a[M];
struct cun{
	int c;
	int q[N];
}b[20];

bool cmp(edge x, edge y){
	return x.w < y.w;
}

int main(){
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	scanf("%d %d %d", &n, &m, &k);
	for(int i = 1; i <= m; i ++){
		scanf("%d %d %d", &a[i].u, &a[i].v, &a[i].w);
	}
	int idx = m;
	for(int i = 1; i <= k; i ++){
		scanf("%d", &b[i].c);
		for(int j = 1; j <= n; j ++){
			scanf("%d", a[++ idx].w);
			a[idx].u = n + i;
			a[idx].v = j;
		}
	}
	for(int i = 1; i <= n; i ++){
		f[i] = i;
	}
	sort(a + 1, a + 1 + m + k, cmp);
	if(k == 0){
		cnt ++;
		int i = 1;
		ans += a[i].w;
		merge(a[i].u, a[i].v);
		i ++;
		while(cnt < n - 1){
			
			if(find(a[i].u) == find(a[i].v)){
				i ++;
				continue;
			}
			else{
				cnt ++;
				merge(a[i].u, a[i].v);
				ans += a[i].w;
				i ++;
			}
		}
		printf("%lld", ans);
	}
	else{
		int i = 1;
		ans += a[i].w;
		merge(a[i].u, a[i].v);
		if(a[i].u > n) toxu ++;
		cnt ++;
		i ++;
		while(cnt < n - 1 + toxu){
			
			if(find(a[i].u) == find(a[i].v)){
				i ++;
				continue;
			}
			else{
				cnt ++;
				merge(a[i].u, a[i].v);
				if(a[i].u > n) toxu ++;
				ans += a[i].w;
				i ++;
			}
		}
		printf("%lld", ans);
	}
	return 0;
}
