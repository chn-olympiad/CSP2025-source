#include <bits/stdc++.h>
#define PB push_back
#define ll long long
//#define int long long

using namespace std;

void rd(int &x){
	int flag = 1; x = 0;
	char c = getchar();
	while(c < '0' || c > '9'){
		if(c == '-') flag = -1;
		c = getchar();
	}
	while(c >= '0' && c <= '9'){
		x = (x << 1) + (x << 3) + (c ^ 48);
		c = getchar();
	}
	x *= flag;
}

const int N = 2e4 + 15;
const int M = 3e6 + 10;

int n, m, k;
struct edge{
	int u, v, w; 
}E[M], E2[M];

bool cmp(edge x, edge y){
	return x.w < y.w;
}

int cx[N], fa[N], siz[N];
int val[12][N]; 

int find(int x){
	if(fa[x] == x) return x;
	return fa[x] = find(fa[x]);
}

void merge(int x, int y){
	int fx = find(x), fy = find(y);
	if(siz[fy] < siz[fx]) swap(fx, fy);
	siz[fy] += siz[fx];
	fa[fx] = fy;
}

void solve1(){ // k = 0
	ll ans = 0;
	sort(E + 1, E + 1 + m, cmp);	
	int cnt = 0;
	for(int i = 1; i <= m; i ++){
		int u = E[i].u, v = E[i].v, w = E[i].w;
		int fu = find(u), fv = find(v);
		if(fu == fv) continue;
		if(siz[fv] < siz[fu]) swap(fu, fv);
		siz[fv] += siz[fu];
		fa[fu] = fv;
		cnt ++;
		ans += w; 
		if(cnt == n - 1){
			cout << ans << '\n';
			return ;
		}
	}
}

void solve2(){ // 特殊性质A 
	ll ans = 0;
	int nct = m;
	for(int i = 1; i <= k; i ++){
		for(int j = 1; j <= n; j ++){
			if(val[i][j] == 0){
				for(int g = 1; g <= n; g ++){
					if(j != g)
					E[++ nct] = {j, g, val[i][g]};
				}
				break;
			}
		}
	}
	sort(E + 1, E + 1 + nct, cmp);	
	int cnt = 0;
	for(int i = 1; i <= nct; i ++){
		int u = E[i].u, v = E[i].v, w = E[i].w;
		int fu = find(u), fv = find(v);
		if(fu == fv) continue;
		if(siz[fv] < siz[fu]) swap(fu, fv);
		siz[fv] += siz[fu];
		fa[fu] = fv;
		cnt ++;
		ans += w; 
		if(cnt == n - 1){
			cout << ans << '\n';
			return ;
		}
	}
	
}


void solve3(){ // 暴力 
	ll ans = (ll)1e18;
	for(int s = 0; s < (1 << k); s ++){
		int S = s;
		ll as = 0;
		for(int i = 1; i <= n + k; i ++) fa[i] = i, siz[i] = 1;
		int nw = 1, idx = n;
		int cnt = m;
		for(int i = 1; i <= m; i ++) E2[i] = E[i];
		while(S){
			if(S & 1){
				as += cx[nw];
				idx ++;
				for(int i = 1; i <= n; i ++){
					E2[++ cnt] = {idx, i, val[nw][i]};
				} 
			}
			nw ++;
			S >>= 1;
		}
		sort(E2 + 1, E2 + 1 + cnt, cmp);
		int cntt = 0;
		for(int i = 1; i <= cnt; i ++){
			int u = E2[i].u, v = E2[i].v, w = E2[i].w;
			int fu = find(u), fv = find(v);
			if(fu == fv) continue;
			if(siz[fv] < siz[fu]) swap(fu, fv);
			siz[fv] += siz[fu];
			fa[fu] = fv;
			cntt ++;
			as += w; 
			if(cntt == idx - 1){
				ans = min(ans, as);
				break;
			}
		}
		
	}
	cout << ans << '\n';
	return ;
}


signed main(){

	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	
	rd(n), rd(m), rd(k);
	
	for(int i = 1; i <= m; i ++){
		int u, v, w;
		rd(u), rd(v), rd(w);
		E[i] = {u, v, w};
	}
	int Fx1 = 1, Fx2 = 1;
	for(int i = 1; i <= k; i ++){
		rd(cx[i]);
		if(cx[i]) Fx1 = 0;
		int Fx3 = 0; 
		for(int j = 1; j <= n; j ++){
			rd(val[i][j]);
			if(!val[i][j]) Fx3 = 1;
		}
		if(!Fx3) Fx2 = 0; 
	}
	
	for(int i = 1; i <= n; i ++) fa[i] = i, siz[i] = 1;
	if(k == 0){
		solve1();
		return 0;
	}else{
		if(Fx1 && Fx2){
			solve2();
			return 0;
		}else{
			solve3();
			return 0;
		}
	}
	

	return 0;
}

