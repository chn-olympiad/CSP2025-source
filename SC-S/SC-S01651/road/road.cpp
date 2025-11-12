#include<bits/stdc++.h>
using namespace std;
#define int long long 

int n, m, k;
const int maxn = 2e6+5;
struct bbb {
	int u, v, w, next;
} bb[maxn];
int tot, head[maxn];
void read(int u, int v, int w) {
	bb[++tot].u = u;
	bb[tot].v = v;
	bb[tot].w = w;
	bb[tot].next = head[u];
	head[u] = tot;
}
int c[maxn], a[maxn];
int f[maxn];
int find(int s) {
	if (f[s] == s) {
		return s;
	}
	return find(f[s]);
}
bool cmp(bbb x,bbb y){
	return x.w<y.w;
}
int sum;
int t;
void krul() {
	sort(bb+1,bb+1+tot,cmp);
	for (int i = 1; i <= tot; ++i) {
		if(t==n-1){
			break;
		}
		int fa = find(bb[i].u);
		int so = find(bb[i].v);
		if (fa != so) {
			++t;
			f[so] = fa;
			sum += bb[i].w;
		}
	}
}
signed main() {
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%lld%lld%lld", &n, &m, &k);
	if(k==0){
	for (int i = 1; i <= n; ++i) {
		f[i] = i;
	}
		for (int i = 1; i <= m; ++i) {
			int u, v, w;
			scanf("%lld%lld%lld", &u, &v, &w);
			read(u, v, w);
			read(v, u, w);
		}	
		krul();
		
		printf("%lld", sum);
	}else{
		printf("0");
	}
	

	return 0;
}
/*
*/