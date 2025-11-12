#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 20000,M = 2000000;
int n, m, k ;
struct edge{
	int to;
	int val;
};
struct node{
	int u,v,w;
};
node q[M];
int c[N];

int fa[N];
int ans = 0;
int kk = 0;
bool cmp(node x,node y){
	return x.w < y.w;
}
int find(int x){
	if(fa[x] == x) return x;
	return fa[x] = find(fa[x]);
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin.tie(0);
	std::ios::sync_with_stdio(0); 
	cin >> n >> m >> k;
	if(k == 0){
		for(int i = 1; i <= m; i++){
			int u,v,w;
			cin >> u >> v >> w;
			q[i] = node{u,v,w};
		}
		for(int i = 1; i <= k; i++){
			cin >> c[i];
			for(int j = 1; j <= n; j++){
				int w;
				cin >> w;			
			}
	
		}
		sort(q+1,q+m+1,cmp);
		for(int i = 1; i <= n; i++) fa[i] = i;
		for(int i = 1; i <= m; i++){
			int u = q[i].u, v = q[i].v, w= q[i].w;
			int fau = find(u), fav = find(v);
			if(fau == fav) continue;
			else{
				fa[fau] = fav;
				ans += w;
	 		}
		}
		cout << ans;		
	}
	else{
		for(int i = 1; i <= m; i++){
			int u,v,w;
			cin >> u >> v >> w;
			q[i] = node{u,v,w};
		}
		int idx = m;
		for(int i = 1; i <= k; i++){
			cin >> c[i];
			ans+=c[i];
			for(int j = 1; j <= n; j++){
				int w;
				cin >> w;
				q[++idx] = node{i+n,j,w};		
			}
		}
		sort(q+1,q+idx+1,cmp);
		for(int i = 1; i <= n+k; i++) fa[i] = i;
		for(int i = 1; i <= idx; i++){
			int u = q[i].u, v = q[i].v, w= q[i].w;
			int fau = find(u), fav = find(v);
			if(fau == fav) continue;
			else{
				fa[fau] = fav;
				ans += w;
	 		}
		}
		cout << ans;			
	}

	return 0;
} 
