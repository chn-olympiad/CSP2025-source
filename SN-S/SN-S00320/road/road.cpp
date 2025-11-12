#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#define int long long
using namespace std;
const int maxn = 2e6 + 1;
int n, m, k, cnt, ans = 2e15 + 1;
int a[11][maxn], c[11];
int fa[maxn];
bool ifused[12];
struct node{
	int u, v, w;
}r[maxn], r1[maxn];
bool cmp(node d1, node d2){
	return d1.w < d2.w;
}
int f(int x){
	if (fa[x] == x) return x;
	return fa[x] = f(fa[x]);
}
void merge(int x, int y){
	fa[f(x)] = f(y);
}
void init_lyh(){
	for (int i = 0; i <= n; i++){
		fa[i] = i;
	}
}
void kruscal(int N, int sum){
	int dwy = 0, Cnt = 0;
	sort(r1 + 1, r1 + 1 + N, cmp);
	init_lyh();
	for (int i = 1; i <= N; i++){
		if (f(r1[i].u) == f(r1[i].v)) continue;
		sum += r1[i].w;
		merge(r1[i].u, r1[i].v);
		if (r1[i].u == 0 || r1[i].v == 0){
			Cnt++;
			dwy = r1[i].w;
		}
	}
	if (Cnt == 1) sum -= dwy;
	ans = min(ans, sum);
} 
void road(){
	int N = m, sum = 0; 
	for (int i = 1; i <= m; i++){
		r1[i].u = r[i].u;
		r1[i].v = r[i].v;
		r1[i].w = r[i].w;
	}
	for (int i = 1; i <= k; i++){
		if (!ifused[i]) continue;
		sum += c[i];
		for (int j = 1; j <= n; j++){
			N++;
			r1[N].u = 0;
			r1[N].v = j;
			r1[N].w = a[i][j];
		}
	}
	kruscal(N, sum);
}
void sub(){
	memset(ifused, true, sizeof(ifused));
	road();
}
signed main(){
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	cin >> n >> m >> k;
	for (int i = 1; i <= m; i++){
		scanf("%lld%lld%lld", &r[i].u, &r[i].v, &r[i].w);
	}
	int p = 0;
	for (int i = 1; i <= k; i++){
		scanf("%lld", &c[i]);
		p += c[i];
		for (int j = 1; j <= n; j++){
			scanf("%lld", &a[i][j]);
//			p += a[i][j];
		}
	}
	if (p == 0){
		sub();
		printf("%lld", ans);
		return 0;
	}
	for (int i = 0; i <= (1 << k); i++){
		memset(ifused, false, sizeof(ifused));
		for (int j = 0; j < k; j++){
			if ((i & (1 << j))) ifused[j + 1] = true;
		}
		road();
	}
	printf("%lld", ans);
	return 0;
}
