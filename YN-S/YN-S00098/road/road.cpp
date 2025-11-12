#include<bits/stdc++.h>
#define int long long
using namespace std;
struct node{
	int u,v,w,pre = 0;
}a[3000005];
bool cmp(node a,node b){return a.w < b.w;}
int fa[10005];
bool vis[10005];
int get(int x){
	if(fa[x] == x) return x;
	return fa[x] = get(fa[x]);
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k; cin >> n >> m >> k;
	for(int i = 1;i <= n;i++) fa[i] = i;
	int tot = 0;
	for(int i = 1;i <= m;i++){
		cin >> a[++tot].u >> a[tot].v >> a[tot].w;
		a[++tot].v = a[i].u;
		a[tot].u = a[i].v;
		a[tot].w = a[i].w;
	}
	for(int i = 1;i <= k;i++){
		int t; cin >> t;
		for(int j = 1;j <= n;j++){
			int w; cin >> w;
			a[++tot].u = i;
			a[tot].v = j;
			a[tot].w = w;
			a[tot].pre = i;
			a[++tot].v = i;
			a[tot].u = j;
			a[tot].w = w;
			a[tot].pre = i;
		}
	}
	sort(a + 1,a + tot + 1,cmp);
	int ans = 0;
	for(int i = 1;i <= tot;i++){
		if(a[i].u > a[i].v) swap(a[i].u,a[i].v);
		if(get(a[i].u) != get(a[i].v)){
			fa[get(a[i].u)] = get(a[i].v);
			ans += a[i].w;
		}
	}
	cout << ans;
	return 0;
}