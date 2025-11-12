#include<bits/stdc++.h>
//#undef STDIO
const int N = 1e4 + 10, M = 1e6 + 10, K = 20;
int n, m, mm, k, a[K][N], b[K], c[K], cnt;
typedef long long ll;
ll ans = LLONG_MAX;
struct edge{
	int u, v, w;
}e[M], ee[M << 1];
namespace calc{
	int fa[N + 100];
	int find(int x){
		return x == fa[x] ? x : fa[x] = find(fa[x]);
	}
	ll solve(){
		mm = m;
		for(int i = 1; i <= m; i++){
			ee[i] = e[i];
		}
		for(int i = 1; i <= n + cnt; i++) fa[i] = i;
		ll sum = 0;
		if(cnt){
			for(int i = 1; i <= cnt; i++) sum += c[b[i]];
			for(int i = 1; i <= n; i++){
				for(int j = 1; j <= cnt; j++){
					ee[++mm] = edge{i, n + j, a[b[j]][i]};
				}
			}
		}
		std::sort(ee + 1, ee + mm + 1, [](edge x, edge y){return x.w < y.w; });
		for(int i = 1; i <= mm; i++){
			if(find(ee[i].u) != find(ee[i].v)){
				sum += ee[i].w;
				fa[find(ee[i].u)] = find(ee[i].v);
			}
		}
		return sum;
	}
}
namespace sub{
	bool check(){
		for(int i = 1; i <= k; i++){
			if(c[i]) return false;
		}
		return true;
	}
	void solve(){
		cnt = k;
		for(int i = 1; i <= k; i++){
			b[i] = i;
		}
		printf("%lld", calc::solve());
	}
}
namespace bf{
	void dfs(int i){
		if(i > k){
//			if(clock() >= 0.92){
//				printf("%lld", ans);
//				fflush(stdout);
//				fclose(stdin);
//				fclose(stdout);
//				exit(0);
//			}
			ans = std::min(ans, calc::solve());
			return;
		}
		b[++cnt] = i;
		dfs(i + 1);
		--cnt;
		dfs(i + 1);
	}
	void solve(){
		dfs(1);
		printf("%lld", ans);
	}
}
int main(){
#ifndef STDIO
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
#endif
	scanf("%d%d%d", &n, &m, &k);
	for(int i = 1; i <= m; i++){
		int u, v, w;
		scanf("%d%d%d", &u, &v, &w);
		e[i] = edge{u, v, w};
	}
	for(int i = 1; i <= k; i++){
		scanf("%d", &c[i]);
		for(int j = 1; j <= n; j++){
			scanf("%d", &a[i][j]);
		}
	}
	if(sub::check()) sub::solve();
	else bf::solve();
	fflush(stdout);
	fclose(stdin);
	fclose(stdout);
	return 0;
}