#include<bits/stdc++.h>
using namespace std;
const int N = 1e4 + 50, M = 1e6 + 10;
int n, m, k, vil[15], vis[N], dis[N], chp[15], pi[15][N], ans;
struct ChouQ{
	int vi, pi;
};
vector<ChouQ> bi[N];
void kru(){
	int xn = 1, cnt = 1;
	vis[xn] = 1;
	while(cnt < n){
		for(int t = 0; t < bi[xn].size(); t ++){
			int vi = bi[xn][t].vi;
			if(dis[vi] > bi[xn][t].pi){
				dis[vi] = bi[xn][t].pi;
			}
		}
		for(int u = 1; u <= k; u ++){
			for(int t = 1; t <= n; t ++){
				int len = pi[u][xn] + pi[u][t] + vil[u];
				if(dis[t] > len){
					dis[t] = len;
					chp[u] = 1;
				}
			}
		}
		int mins = 1e9, mint;
		for(int t = 1; t <= n; t ++){
			if(!vis[t] and dis[t] < mins){
				mins = dis[t];
				mint = t;
			}
		}
		if(chp[mint]){
			vil[mint] = 0;
		}
		//cout<<mint<<' '<<mins<<endl;
		cnt ++;
		vis[mint] = 1;
		ans += dis[mint];
		xn = mint;
	}
	printf("%d", ans);
	return;
}
struct bis{
	int ui, vi, pi;
}asd[N];
bool cmp(bis ai, bis ci){
	return ai.pi < ci.pi;
}
int fa[N];
int fin(int xn){
	if(xn == fa[xn]){
		return xn;
	}
	else{
		fa[xn] = fin(fa[xn]);
		return fa[xn];
	}
}
int main(){
	
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);

	scanf("%d%d%d", &n, &m, &k);
	if(k == 0){
		for(int t = 0; t < m; t ++){
			int ui, vi, pi;
			scanf("%d%d%d", &asd[t].ui, &asd[t].vi, &asd[t].pi);
		}
		sort(asd, asd + m, cmp);
		int jn = 0, cnt = 1;
		while(cnt < n){
			auto sd = asd[jn];
			if(fin(sd.ui) != fin(sd.vi)){
				ans += sd.pi;
				cnt ++;
				fa[sd.vi] = fa[sd.ui];
			}
			jn ++;
		}
		printf("%d", ans);
		return 0;
	}
	
	
	for(int t = 0; t < m; t ++){
		int ui, vi, pi;
		scanf("%d%d%d", &ui, &vi, &pi);
		bi[ui].push_back((ChouQ){vi, pi});
		bi[vi].push_back((ChouQ){ui, pi});
	}
	
	for(int t = 1; t <= k; t ++){
		scanf("%d", &vil[t]);
		for(int y = 1; y <= n; y ++){
			scanf("%d", &pi[t][y]);
		}
	}
	for(int y = 1; y <= n; y ++){
		dis[y] = 1e9;
	}
	kru();
	return 0;
}