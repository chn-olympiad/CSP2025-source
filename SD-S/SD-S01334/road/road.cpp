#include <bits/stdc++.h>

using namespace std;

#define int long long

constexpr int N = 1e6 + 5;

struct edge{
	int u,v,w;
}e[N],g[N],h[N],last[N];

int n,m,k,fa[N],cnt = 0,c[N],have[15];
inline int Find(int x){
	return x == fa[x] ? x : fa[x] = Find(fa[x]);
}
inline void Merge(int x,int y){
	fa[Find(x)] = Find(y);
}
inline void Clear(){
	for(int i = 1; i <= n; ++ i){
		fa[i] = i;
	}
}
std::pair<int,int> out[12][10005];
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
//	freopen("road4.in","r",stdin);
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cin >> n >> m >> k;
	for(int i = 1; i <= m; ++ i){
		std::cin >> e[i].u >> e[i].v >> e[i].w;
	}
	std::sort(e + 1,e + m + 1,[&](const edge & a,const edge & b){
		return a.w < b.w;
	});
	Clear();
	int ans = 0;
	for(int i = 1; i <= m; ++ i){
		if(Find(e[i].u) != Find(e[i].v)){
			Merge(e[i].u,e[i].v);
			ans += e[i].w;
			g[++ cnt] = e[i];
			last[cnt] = e[i];
		}
	}
	for(int i = 1; i <= k; ++ i){
		std::cin >> c[i];
		for(int j = 1; j <= n; ++ j){
			std::cin >> out[i][j].first;
			out[i][j].second = j;
		}
		std::sort(out[i] + 1,out[i] + n + 1);
	}
	for(int i = 1; i < (1 << k); ++ i){
		int tot = 0;
		for(int j = 0; j < k; ++ j){
			if(i >> j & 1) have[++ tot] = j + 1;
		}
		for(int j = 1; j <= tot; ++ j){
			int pos1 = 1,pos2 = 1,nw_cnt = 0;
			while(pos1 <= cnt && pos2 <= n){
				if(g[pos1].w < out[have[j]][pos2].first){
					h[++ nw_cnt] = g[pos1];
					++ pos1;
				}else{
					h[++ nw_cnt] = (edge){
						n + j,out[have[j]][pos2].second,out[have[j]][pos2].first
					};
					++ pos2;
				}
			}
			while(pos1 <= cnt) h[++ nw_cnt] = g[pos1],++ pos1;
			while(pos2 <= n){
				h[++ nw_cnt] = (edge){
					n + j,out[have[j]][pos2].second,out[have[j]][pos2].first
				};
				++ pos2;
			}
			cnt = nw_cnt;
			for(int p = 1; p <= cnt; ++ p) g[p] = h[p];
		}
		
		for(int j = 1; j <= n + 10; ++ j) fa[j] = j;
		int sum = 0;
		for(int j = 1; j <= cnt; ++ j){
			if(Find(g[j].u) != Find(g[j].v)){
				Merge(g[j].u,g[j].v);
				sum += g[j].w;
			}
		}
		for(int j = 1; j <= tot; ++ j) sum += c[have[j]];
		ans = std::min(ans,sum);
		cnt = n - 1;
		for(int j = 1; j <= cnt; ++ j) g[j] = last[j];
	}
	std::cout << ans << '\n';
	return 0;
} 
